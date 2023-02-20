// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fastrtps/types/DynamicTypeBuilder.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/DynamicType.h>
#include <fastrtps/types/TypeDescriptor.h>
#include <fastrtps/types/MemberDescriptor.h>
#include <fastrtps/types/DynamicTypeMember.h>
#include <fastrtps/types/AnnotationDescriptor.h>
#include <fastdds/dds/log/Log.hpp>

#include <tuple>

using namespace eprosima::fastrtps::types;

DynamicTypeBuilder::DynamicTypeBuilder(
        use_the_create_method)
{
}

DynamicTypeBuilder::DynamicTypeBuilder(
        use_the_create_method,
        const DynamicTypeBuilder& builder)
{
    *this = builder;
}

DynamicTypeBuilder::DynamicTypeBuilder(
        use_the_create_method,
        const TypeDescriptor& descriptor)
    : current_member_id_(0)
{
    (void)descriptor;
    // TODO BARR: refactor

//    descriptor_ = new TypeDescriptor(descriptor);
//    try
//    {
//        name_ = descriptor->get_name();
//        kind_ = descriptor->get_kind();
//    }
//    catch (...)
//    {
//        name_ = "";
//        kind_ = TK_NONE;
//    }
//
//    // Alias types use the same members than it's base class.
//    if (kind_ == TK_ALIAS)
//    {
//        for (auto it = descriptor_->get_base_type()->member_by_id_.begin();
//                it != descriptor_->get_base_type()->member_by_id_.end(); ++it)
//        {
//            member_by_name_.insert(std::make_pair(it->second->get_name(), it->second));
//        }
//    }
//
//    refresh_member_ids();
}

DynamicTypeBuilder::member_iterator DynamicTypeBuilder::add_empty_member(
        uint32_t index,
        const std::string& name)
{
    // insert the new member
    member_iterator it;
    if( index >=  members_.size() )
    {
        // at the end
        index = uint32_t(members_.size());
        it = members_.emplace(members_.end(), index, name);
    }
    else
    {
        // move all the others
        it = members_.begin();
        std::advance(it, index);
        it = members_.emplace(it, index, name);
        // rename the others
        for(auto i = index; it != members_.end(); ++it)
        {
            it->set_index(++i);
            assert(it->get_index() == i);
        }
    }

    if (get_kind() == TK_BITMASK)
    {
        if (index >= get_bounds(0))
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, out of bounds.");
        }

        it->annotation_set_position(static_cast<uint16_t>(index));
    }

    return it;
}

ReturnCode_t DynamicTypeBuilder::add_member(
        const MemberDescriptor& descriptor) noexcept
{
    try
    {
        if (!descriptor.is_consistent(get_kind()))
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, The input descriptor isn't consistent.");
        }

        if (get_kind() != TK_ANNOTATION && get_kind() != TK_BITMASK
                && get_kind() != TK_ENUM && get_kind() != TK_STRUCTURE
                && get_kind() != TK_UNION && get_kind() != TK_BITSET)
        {
            std::ostringstream os;
            os << "Error adding member, the current type " << get_kind() << " doesn't support members.";

            throw std::system_error(
                    ReturnCode_t::RETCODE_PRECONDITION_NOT_MET,
                    os.str());
        }

        auto member_name = descriptor.get_name();

        // Bitsets allow multiple empty members.
        if( get_kind() != TK_BITSET && descriptor.get_name().empty())
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, missing proper name.");
        }

        if(!member_name.empty() && exists_member_by_name(member_name))
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, there is other member with the same name.");
        }

        auto member_id = descriptor.get_id();
        if (member_id != MEMBER_ID_INVALID && exists_member_by_id(member_id))
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, there is other member with the same id.");
        }

        if (!check_union_configuration(descriptor))
        {
            throw std::system_error(
                    ReturnCode_t::RETCODE_BAD_PARAMETER,
                    "Error adding member, invalid union parameters.");
        }

        auto it = add_empty_member(descriptor.get_index(), member_name);

        DynamicTypeMember& newMember = *it;
        // Copy all elements but keep the index
        auto member_index = newMember.get_index();
        newMember = descriptor;
        newMember.set_index(member_index);

        if(member_id == MEMBER_ID_INVALID)
        {
            // assing a new one
            while(exists_member_by_id(current_member_id_))
            {
                member_id = ++current_member_id_;
            }

            newMember.set_id(member_id);
        }

        // update the indexes collections
        if (!member_name.empty()) // Don't store empty bitset members.
        {
            member_by_id_.insert(std::make_pair(member_id, &newMember));
            member_by_name_.insert(std::make_pair(member_name, &newMember));
        }

        // advance
        ++current_member_id_;
    }
    catch(std::system_error& e)
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, e.what());
        return e.code().value();
    }

    return ReturnCode_t::RETCODE_OK;
}

DynamicType_ptr DynamicTypeBuilder::build() const
{
    if (is_consistent())
    {
        return DynamicTypeBuilderFactory::get_instance()->create_type(this);
    }
    else
    {
        EPROSIMA_LOG_ERROR(DYN_TYPES, "Error building type. The current descriptor isn't consistent.");
        return nullptr;
    }
}

bool DynamicTypeBuilder::check_union_configuration(
        const MemberDescriptor& descriptor)
{
    if (get_kind() == TK_UNION)
    {
        bool default_union_value = descriptor.is_default_union_value();
        if (!default_union_value && descriptor.get_union_labels().size() == 0)
        {
            return false;
        }
        for (auto& m : members_ )
        {
            // Check that there isn't any member as default label and that there isn't any member with the same case.
            if (default_union_value && m.is_default_union_value() ||
                    !descriptor.check_union_labels(m.get_union_labels()))
            {
                return false;
            }
        }
    }
    return true;
}

void DynamicTypeBuilder::clear()
{
    TypeDescriptor::clean();
    current_member_id_ = 0;
}

bool DynamicTypeBuilder::is_discriminator_type() const
{
    auto base = get_base_type();
    auto kind = get_kind();

    if (kind == TK_ALIAS && base)
    {
        return base->is_discriminator_type();
    }
    return kind == TK_BOOLEAN || kind == TK_BYTE || kind == TK_INT16 || kind == TK_INT32 ||
           kind == TK_INT64 || kind == TK_UINT16 || kind == TK_UINT32 || kind == TK_UINT64 ||
           kind == TK_FLOAT32 || kind == TK_FLOAT64 || kind == TK_FLOAT128 || kind == TK_CHAR8 ||
           kind == TK_CHAR16 || kind == TK_STRING8 || kind == TK_STRING16 || kind == TK_ENUM || kind == TK_BITMASK;
}

void DynamicTypeBuilder::refresh_member_ids()
{
    auto base = get_base_type();
    auto kind = get_kind();

    if ((kind == TK_STRUCTURE || kind == TK_BITSET) && base)
    {
        current_member_id_ = base->get_members_count();
    }
}

bool DynamicTypeBuilder::equals(
        const DynamicType& other) const
{
    return get_type_descriptor() == other.get_type_descriptor();
}
