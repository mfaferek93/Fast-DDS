// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include <fastrtps/types/TypesBase.h>
#include <fastdds/dds/log/Log.hpp>

#include <fastrtps/types/v1_3/DynamicType.hpp>
#include <dynamic-types/v1_3/DynamicTypeImpl.hpp>

using namespace eprosima::fastrtps::types::v1_3;
using eprosima::fastrtps::types::ReturnCode_t;

bool DynamicType::operator ==(
        const DynamicType& other) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this)
           == DynamicTypeImpl::get_implementation(other);
}

bool DynamicType::operator !=(
        const DynamicType& other) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this)
           != DynamicTypeImpl::get_implementation(other);
}

ReturnCode_t DynamicType::get_descriptor(TypeDescriptor& td) const noexcept
{
    td = DynamicTypeImpl::get_implementation(*this).get_descriptor();
    return ReturnCode_t::RETCODE_OK;
}

const char* DynamicType::get_name() const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_name().c_str();
}

TypeKind DynamicType::get_kind() const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_kind();
}

const DynamicTypeMember* DynamicType::get_member_by_name(
        const char* name,
        ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_member_by_name(name, ec);
}

DynamicTypeMembersByName DynamicType::get_all_members_by_name(
        ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_all_members_by_name(ec);
}

const DynamicTypeMember* DynamicType::get_member(
        MemberId id,
        ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    try
    {
        if (ec)
        {
            *ec = ReturnCode_t{};
        }

        return &DynamicTypeImpl::get_implementation(*this).get_member(id).get_interface();
    }
    catch(std::system_error& e)
    {
        if (ec)
        {
            *ec = static_cast<uint32_t>(e.code().value());
        }

        EPROSIMA_LOG_ERROR(DYN_TYPES, e.what());

        return nullptr;
    }
}

DynamicTypeMembersById DynamicType::get_all_members(ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_all_members_by_id(ec);
}

uint32_t DynamicType::get_member_count() const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_member_count();
}

const DynamicTypeMember* DynamicType::get_member_by_index(
        uint32_t index,
        ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    try
    {
        if (ec)
        {
            *ec = ReturnCode_t{};
        }

        return &DynamicTypeImpl::get_implementation(*this).get_member_by_index(index).get_interface();
    }
    catch(std::system_error& e)
    {
        if (ec)
        {
            *ec = static_cast<uint32_t>(e.code().value());
        }

        EPROSIMA_LOG_ERROR(DYN_TYPES, e.what());

        return nullptr;
    }
}

uint32_t DynamicType::get_annotation_count() const noexcept
{
    return static_cast<uint32_t>(DynamicTypeImpl::get_implementation(*this).get_annotation_count());
}

ReturnCode_t DynamicType::get_annotation(
        AnnotationDescriptor& annotation,
        uint32_t index) const noexcept
{
    return DynamicTypeImpl::get_implementation(*this).get_annotation(annotation, index);
}

const Annotations* DynamicType::get_all_annotations(
    ReturnCode_t* ec /*= nullptr*/) const noexcept
{
    if (ec)
    {
        *ec = ReturnCode_t{};
    }

    return &DynamicTypeImpl::get_implementation(*this).get_annotations();
}

bool DynamicType::equals(
        const DynamicType& other) const noexcept
{
    return *this == other;
}

bool DynamicType::key_annotation() const
{
    return DynamicTypeImpl::get_implementation(*this).key_annotation();
}

