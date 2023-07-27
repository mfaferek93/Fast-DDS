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
 * @file WideEnumCdrAux.ipp
 * This source file contains some declarations of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_WIDEENUMCDRAUX_IPP_
#define _FAST_DDS_GENERATED_WIDEENUMCDRAUX_IPP_

#include "WideEnumCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const MyEnumWideStruct& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.my_enum_wide(), current_alignment);


    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const MyEnumWideStruct& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr 
            << eprosima::fastcdr::MemberId(0) << data.my_enum_wide()
;

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        MyEnumWideStruct& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.my_enum_wide();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const MyEnumWideStruct& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
}


template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const SimpleWideUnion& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);

    // TODO Member id del discriminador
    current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
            current_alignment);

    switch(data._d())
    {
                        case A:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.first(), current_alignment);
                        break;

                        case B:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.second(), current_alignment);
                        break;

                        case D:
                        current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.third(), current_alignment);
                        break;

    }

    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}


template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const SimpleWideUnion& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch(data._d())
    {
                        case A:
                        scdr << eprosima::fastcdr::MemberId(1) << data.first();
                        break;

                        case B:
                        scdr << eprosima::fastcdr::MemberId(2) << data.second();
                        break;

                        case D:
                        scdr << eprosima::fastcdr::MemberId(3) << data.third();
                        break;

    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        SimpleWideUnion& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                    case 0:
                        dcdr >> data._d();
                        break;
                    default:
                        switch (data._d())
                        {
                                                                case A:
                                                                // TODO Test on mutable the MemberId
                                                                dcdr >> data.first();
                                                                break;

                                                                case B:
                                                                // TODO Test on mutable the MemberId
                                                                dcdr >> data.second();
                                                                break;

                                                                case D:
                                                                // TODO Test on mutable the MemberId
                                                                dcdr >> data.third();
                                                                break;

                        }
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const SimpleWideUnionStruct& data,
        size_t current_alignment)
{
    static_cast<void>(calculator);
    static_cast<void>(data);
    size_t initial_alignment = current_alignment;

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    current_alignment += calculator.begin_calculate_type_serialized_size(
            eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            current_alignment);


                current_alignment += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data.my_union(), current_alignment);


    current_alignment += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return current_alignment - initial_alignment;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const SimpleWideUnionStruct& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
);

    scdr 
            << eprosima::fastcdr::MemberId(0) << data.my_union()
;

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        SimpleWideUnionStruct& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2
 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR
,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.my_union();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const SimpleWideUnionStruct& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
}



} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_WIDEENUMCDRAUX_IPP_