// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file KeyedHelloWorldTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "KeyedHelloWorldTypeObjectSupport.hpp"

#include <mutex>
#include <string>

#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/xtypes/common.hpp>
#include <fastdds/dds/xtypes/type_representation/ITypeObjectRegistry.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObject.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObjectUtils.hpp>

#include "KeyedHelloWorld.hpp"


using namespace eprosima::fastdds::dds::xtypes;

// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_KeyedHelloWorld_type_identifier(
        TypeIdentifierPair& type_ids_KeyedHelloWorld)
{

    ReturnCode_t return_code_KeyedHelloWorld {eprosima::fastdds::dds::RETCODE_OK};
    return_code_KeyedHelloWorld =
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
        "KeyedHelloWorld", type_ids_KeyedHelloWorld);
    if (eprosima::fastdds::dds::RETCODE_OK != return_code_KeyedHelloWorld)
    {
        StructTypeFlag struct_flags_KeyedHelloWorld = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::APPENDABLE,
                false, false);
        static_cast<void>(return_code_KeyedHelloWorld);
        QualifiedTypeName type_name_KeyedHelloWorld = "KeyedHelloWorld";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_KeyedHelloWorld;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_KeyedHelloWorld;
        CompleteTypeDetail detail_KeyedHelloWorld = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_KeyedHelloWorld, ann_custom_KeyedHelloWorld, type_name_KeyedHelloWorld.to_string());
        CompleteStructHeader header_KeyedHelloWorld;
        header_KeyedHelloWorld = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_KeyedHelloWorld);
        CompleteStructMemberSeq member_seq_KeyedHelloWorld;
        {
            TypeIdentifierPair type_ids_key;
            ReturnCode_t return_code_key {eprosima::fastdds::dds::RETCODE_OK};
            return_code_key =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_uint16_t", type_ids_key);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_key)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "key Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_key = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, true, false);
            MemberId member_id_key = 0x00000000;
            bool common_key_ec {false};
            CommonStructMember common_key {TypeObjectUtils::build_common_struct_member(member_id_key, member_flags_key, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_key, common_key_ec))};
            if (!common_key_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure key member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_key = "key";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_key;
            ann_custom_KeyedHelloWorld.reset();
            AppliedAnnotationSeq tmp_ann_custom_key;
            eprosima::fastcdr::optional<std::string> unit_key;
            eprosima::fastcdr::optional<AnnotationParameterValue> min_key;
            eprosima::fastcdr::optional<AnnotationParameterValue> max_key;
            eprosima::fastcdr::optional<std::string> hash_id_key;
            if (unit_key.has_value() || min_key.has_value() || max_key.has_value() || hash_id_key.has_value())
            {
                member_ann_builtin_key = TypeObjectUtils::build_applied_builtin_member_annotations(unit_key, min_key, max_key, hash_id_key);
            }
            if (!tmp_ann_custom_key.empty())
            {
                ann_custom_KeyedHelloWorld = tmp_ann_custom_key;
            }
            CompleteMemberDetail detail_key = TypeObjectUtils::build_complete_member_detail(name_key, member_ann_builtin_key, ann_custom_KeyedHelloWorld);
            CompleteStructMember member_key = TypeObjectUtils::build_complete_struct_member(common_key, detail_key);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeyedHelloWorld, member_key);
        }
        {
            TypeIdentifierPair type_ids_index;
            ReturnCode_t return_code_index {eprosima::fastdds::dds::RETCODE_OK};
            return_code_index =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_uint16_t", type_ids_index);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_index)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "index Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_index = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_index = 0x00000001;
            bool common_index_ec {false};
            CommonStructMember common_index {TypeObjectUtils::build_common_struct_member(member_id_index, member_flags_index, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_index, common_index_ec))};
            if (!common_index_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure index member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_index = "index";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_index;
            ann_custom_KeyedHelloWorld.reset();
            CompleteMemberDetail detail_index = TypeObjectUtils::build_complete_member_detail(name_index, member_ann_builtin_index, ann_custom_KeyedHelloWorld);
            CompleteStructMember member_index = TypeObjectUtils::build_complete_struct_member(common_index, detail_index);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeyedHelloWorld, member_index);
        }
        {
            TypeIdentifierPair type_ids_message;
            ReturnCode_t return_code_message {eprosima::fastdds::dds::RETCODE_OK};
            return_code_message =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_string_128", type_ids_message);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_message)
            {
                {
                    SBound bound = static_cast<SBound>(128);
                    StringSTypeDefn string_sdefn = TypeObjectUtils::build_string_s_type_defn(bound);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_s_string_type_identifier(string_sdefn,
                            "anonymous_string_128", type_ids_message))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_string_128 already registered in TypeObjectRegistry for a different type.");
                    }
                }
            }
            StructMemberFlag member_flags_message = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_message = 0x00000002;
            bool common_message_ec {false};
            CommonStructMember common_message {TypeObjectUtils::build_common_struct_member(member_id_message, member_flags_message, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_message, common_message_ec))};
            if (!common_message_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure message member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_message = "message";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_message;
            ann_custom_KeyedHelloWorld.reset();
            CompleteMemberDetail detail_message = TypeObjectUtils::build_complete_member_detail(name_message, member_ann_builtin_message, ann_custom_KeyedHelloWorld);
            CompleteStructMember member_message = TypeObjectUtils::build_complete_struct_member(common_message, detail_message);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeyedHelloWorld, member_message);
        }
        CompleteStructType struct_type_KeyedHelloWorld = TypeObjectUtils::build_complete_struct_type(struct_flags_KeyedHelloWorld, header_KeyedHelloWorld, member_seq_KeyedHelloWorld);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_KeyedHelloWorld, type_name_KeyedHelloWorld.to_string(), type_ids_KeyedHelloWorld))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "KeyedHelloWorld already registered in TypeObjectRegistry for a different type.");
        }
    }
}

