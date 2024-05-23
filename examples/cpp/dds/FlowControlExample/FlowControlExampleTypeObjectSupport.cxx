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
 * @file FlowControlExampleTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen.
 */

#include "FlowControlExampleTypeObjectSupport.hpp"

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

#include "FlowControlExample.hpp"


using namespace eprosima::fastdds::dds::xtypes;

// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_FlowControlExample_type_identifier(
        TypeIdentifierPair& type_ids_FlowControlExample)
{

    ReturnCode_t return_code_FlowControlExample {eprosima::fastdds::dds::RETCODE_OK};
    return_code_FlowControlExample =
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
        "FlowControlExample", type_ids_FlowControlExample);
    if (eprosima::fastdds::dds::RETCODE_OK != return_code_FlowControlExample)
    {
        StructTypeFlag struct_flags_FlowControlExample = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::NOT_APPLIED,
                false, false);
        static_cast<void>(return_code_FlowControlExample);
        QualifiedTypeName type_name_FlowControlExample = "FlowControlExample";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_FlowControlExample;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_FlowControlExample;
        CompleteTypeDetail detail_FlowControlExample = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_FlowControlExample, ann_custom_FlowControlExample, type_name_FlowControlExample.to_string());
        CompleteStructHeader header_FlowControlExample;
        header_FlowControlExample = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_FlowControlExample);
        CompleteStructMemberSeq member_seq_FlowControlExample;
        {
            TypeIdentifierPair type_ids_message;
            ReturnCode_t return_code_message {eprosima::fastdds::dds::RETCODE_OK};
            return_code_message =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_array_char_600000", type_ids_message);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_message)
            {
                return_code_message =
                    eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                    "_char", type_ids_message);

                if (eprosima::fastdds::dds::RETCODE_OK != return_code_message)
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "Array element TypeIdentifier unknown to TypeObjectRegistry.");
                    return;
                }
                TypeIdentifier* element_identifier_anonymous_array_char_600000 {nullptr};
                if (EK_COMPLETE == type_ids_message.type_identifier1()._d() || TK_NONE == type_ids_message.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_message.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_message.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_message.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier1().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_message.type_identifier1()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier1().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_message.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_message.type_identifier1().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_message.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_message.type_identifier1()._d() &&
                        (EK_COMPLETE == type_ids_message.type_identifier1().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_message.type_identifier1().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_array_char_600000 = new TypeIdentifier(type_ids_message.type_identifier1());
                }
                else if (EK_COMPLETE == type_ids_message.type_identifier2()._d() ||
                        (TI_PLAIN_SEQUENCE_SMALL == type_ids_message.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_SEQUENCE_LARGE == type_ids_message.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_SMALL == type_ids_message.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier2().array_sdefn().header().equiv_kind()) ||
                        (TI_PLAIN_ARRAY_LARGE == type_ids_message.type_identifier2()._d() &&
                        EK_COMPLETE == type_ids_message.type_identifier2().array_ldefn().header().equiv_kind()) ||
                        (TI_PLAIN_MAP_SMALL == type_ids_message.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_message.type_identifier2().map_sdefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_message.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                        (TI_PLAIN_MAP_LARGE == type_ids_message.type_identifier2()._d() &&
                        (EK_COMPLETE == type_ids_message.type_identifier2().map_ldefn().header().equiv_kind() ||
                        EK_COMPLETE == type_ids_message.type_identifier2().map_ldefn().key_identifier()->_d())))
                {
                    element_identifier_anonymous_array_char_600000 = new TypeIdentifier(type_ids_message.type_identifier2());
                }
                else
                {
                    EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Array element TypeIdentifier inconsistent.");
                    return;
                }
                EquivalenceKind equiv_kind_anonymous_array_char_600000 = EK_COMPLETE;
                if (TK_NONE == type_ids_message.type_identifier2()._d())
                {
                    equiv_kind_anonymous_array_char_600000 = EK_BOTH;
                }
                CollectionElementFlag element_flags_anonymous_array_char_600000 = 0;
                PlainCollectionHeader header_anonymous_array_char_600000 = TypeObjectUtils::build_plain_collection_header(equiv_kind_anonymous_array_char_600000, element_flags_anonymous_array_char_600000);
                {
                    LBoundSeq array_bound_seq;
                        TypeObjectUtils::add_array_dimension(array_bound_seq, static_cast<LBound>(600000));

                    PlainArrayLElemDefn array_ldefn = TypeObjectUtils::build_plain_array_l_elem_defn(header_anonymous_array_char_600000, array_bound_seq,
                                eprosima::fastcdr::external<TypeIdentifier>(element_identifier_anonymous_array_char_600000));
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_l_array_type_identifier(array_ldefn, "anonymous_array_char_600000", type_ids_message))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_array_char_600000 already registered in TypeObjectRegistry for a different type.");
                    }
                }
            }
            StructMemberFlag member_flags_message = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_message;
            MemberId member_id_message = 0x00000000;
            if (EK_COMPLETE == type_ids_message.type_identifier1()._d() || TK_NONE == type_ids_message.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_message.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_message.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_message.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_message.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_message.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_message.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_message.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_message.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_message.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_message.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_message = TypeObjectUtils::build_common_struct_member(member_id_message,
                        member_flags_message, type_ids_message.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_message.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_message.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_message.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_message.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_message.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_message.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_message.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_message.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_message.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_message.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_message.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_message.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_message = TypeObjectUtils::build_common_struct_member(member_id_message,
                        member_flags_message, type_ids_message.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure message member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_message = "message";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_message;
            ann_custom_FlowControlExample.reset();
            CompleteMemberDetail detail_message = TypeObjectUtils::build_complete_member_detail(name_message, member_ann_builtin_message, ann_custom_FlowControlExample);
            CompleteStructMember member_message = TypeObjectUtils::build_complete_struct_member(common_message, detail_message);
            TypeObjectUtils::add_complete_struct_member(member_seq_FlowControlExample, member_message);
        }
        {
            TypeIdentifierPair type_ids_wasFast;
            ReturnCode_t return_code_wasFast {eprosima::fastdds::dds::RETCODE_OK};
            return_code_wasFast =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_char", type_ids_wasFast);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_wasFast)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "wasFast Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_wasFast = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructKind::NOT_APPLIED,
                    false, false, false, false);
            CommonStructMember common_wasFast;
            MemberId member_id_wasFast = 0x00000001;
            if (EK_COMPLETE == type_ids_wasFast.type_identifier1()._d() || TK_NONE == type_ids_wasFast.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_wasFast.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_wasFast.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_wasFast.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_wasFast.type_identifier1()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_wasFast.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_wasFast.type_identifier1().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_wasFast.type_identifier1()._d() &&
                    (EK_COMPLETE == type_ids_wasFast.type_identifier1().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_wasFast.type_identifier1().map_ldefn().key_identifier()->_d())))
            {
                common_wasFast = TypeObjectUtils::build_common_struct_member(member_id_wasFast,
                        member_flags_wasFast, type_ids_wasFast.type_identifier1());
            }
            else if (EK_COMPLETE == type_ids_wasFast.type_identifier2()._d() ||
                    (TI_PLAIN_SEQUENCE_SMALL == type_ids_wasFast.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().seq_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_SEQUENCE_LARGE == type_ids_wasFast.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().seq_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_SMALL == type_ids_wasFast.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().array_sdefn().header().equiv_kind()) ||
                    (TI_PLAIN_ARRAY_LARGE == type_ids_wasFast.type_identifier2()._d() &&
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().array_ldefn().header().equiv_kind()) ||
                    (TI_PLAIN_MAP_SMALL == type_ids_wasFast.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_wasFast.type_identifier2().map_sdefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().map_sdefn().key_identifier()->_d())) ||
                    (TI_PLAIN_MAP_LARGE == type_ids_wasFast.type_identifier2()._d() &&
                    (EK_COMPLETE == type_ids_wasFast.type_identifier2().map_ldefn().header().equiv_kind() ||
                    EK_COMPLETE == type_ids_wasFast.type_identifier2().map_ldefn().key_identifier()->_d())))
            {
                common_wasFast = TypeObjectUtils::build_common_struct_member(member_id_wasFast,
                        member_flags_wasFast, type_ids_wasFast.type_identifier2());
            }
            else
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "Structure wasFast member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_wasFast = "wasFast";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_wasFast;
            ann_custom_FlowControlExample.reset();
            CompleteMemberDetail detail_wasFast = TypeObjectUtils::build_complete_member_detail(name_wasFast, member_ann_builtin_wasFast, ann_custom_FlowControlExample);
            CompleteStructMember member_wasFast = TypeObjectUtils::build_complete_struct_member(common_wasFast, detail_wasFast);
            TypeObjectUtils::add_complete_struct_member(member_seq_FlowControlExample, member_wasFast);
        }
        CompleteStructType struct_type_FlowControlExample = TypeObjectUtils::build_complete_struct_type(struct_flags_FlowControlExample, header_FlowControlExample, member_seq_FlowControlExample);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_FlowControlExample, type_name_FlowControlExample.to_string(), type_ids_FlowControlExample))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "FlowControlExample already registered in TypeObjectRegistry for a different type.");
        }
    }
}

