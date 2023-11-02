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
 * @file datatypes.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_DATATYPES_H_
#define _FAST_DDS_GENERATED_DATATYPES_H_

#include <array>
#include <bitset>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include <fastcdr/cdr/fixed_size_string.hpp>
#include <fastcdr/xcdr/optional.hpp>



#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(DATATYPES_SOURCE)
#define DATATYPES_DllAPI __declspec( dllexport )
#else
#define DATATYPES_DllAPI __declspec( dllimport )
#endif // DATATYPES_SOURCE
#else
#define DATATYPES_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DATATYPES_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
class CdrSizeCalculator;
} // namespace fastcdr
} // namespace eprosima



/*!
 * @brief This class represents the structure Timestamp defined by the user in the IDL file.
 * @ingroup datatypes
 */
class Timestamp
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Timestamp();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Timestamp();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Timestamp that will be copied.
     */
    eProsima_user_DllExport Timestamp(
            const Timestamp& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Timestamp that will be copied.
     */
    eProsima_user_DllExport Timestamp(
            Timestamp&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Timestamp that will be copied.
     */
    eProsima_user_DllExport Timestamp& operator =(
            const Timestamp& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Timestamp that will be copied.
     */
    eProsima_user_DllExport Timestamp& operator =(
            Timestamp&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Timestamp object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Timestamp& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Timestamp object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Timestamp& x) const;

    /*!
     * @brief This function sets a value in member sec
     * @param _sec New value for member sec
     */
    eProsima_user_DllExport void sec(
            uint64_t _sec);

    /*!
     * @brief This function returns the value of member sec
     * @return Value of member sec
     */
    eProsima_user_DllExport uint64_t sec() const;

    /*!
     * @brief This function returns a reference to member sec
     * @return Reference to member sec
     */
    eProsima_user_DllExport uint64_t& sec();


    /*!
     * @brief This function sets a value in member nanosec
     * @param _nanosec New value for member nanosec
     */
    eProsima_user_DllExport void nanosec(
            uint32_t _nanosec);

    /*!
     * @brief This function returns the value of member nanosec
     * @return Value of member nanosec
     */
    eProsima_user_DllExport uint32_t nanosec() const;

    /*!
     * @brief This function returns a reference to member nanosec
     * @return Reference to member nanosec
     */
    eProsima_user_DllExport uint32_t& nanosec();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Timestamp& data,
            size_t current_alignment = 0);

private:

    uint64_t m_sec{0};
    uint32_t m_nanosec{0};

};
/*!
 * @brief This class represents the structure Header defined by the user in the IDL file.
 * @ingroup datatypes
 */
class Header
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Header();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Header();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header(
            const Header& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header(
            Header&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header& operator =(
            const Header& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Header that will be copied.
     */
    eProsima_user_DllExport Header& operator =(
            Header&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Header object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Header& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Header object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Header& x) const;

    /*!
     * @brief This function sets a value in member sec
     * @param _sec New value for member sec
     */
    eProsima_user_DllExport void sec(
            int32_t _sec);

    /*!
     * @brief This function returns the value of member sec
     * @return Value of member sec
     */
    eProsima_user_DllExport int32_t sec() const;

    /*!
     * @brief This function returns a reference to member sec
     * @return Reference to member sec
     */
    eProsima_user_DllExport int32_t& sec();


    /*!
     * @brief This function sets a value in member nanosec
     * @param _nanosec New value for member nanosec
     */
    eProsima_user_DllExport void nanosec(
            uint32_t _nanosec);

    /*!
     * @brief This function returns the value of member nanosec
     * @return Value of member nanosec
     */
    eProsima_user_DllExport uint32_t nanosec() const;

    /*!
     * @brief This function returns a reference to member nanosec
     * @return Reference to member nanosec
     */
    eProsima_user_DllExport uint32_t& nanosec();


    /*!
     * @brief This function copies the value in member frame_id
     * @param _frame_id New value to be copied in member frame_id
     */
    eProsima_user_DllExport void frame_id(
            const eprosima::fastcdr::fixed_string<256>& _frame_id);

    /*!
     * @brief This function moves the value in member frame_id
     * @param _frame_id New value to be moved in member frame_id
     */
    eProsima_user_DllExport void frame_id(
            eprosima::fastcdr::fixed_string<256>&& _frame_id);

    /*!
     * @brief This function returns a constant reference to member frame_id
     * @return Constant reference to member frame_id
     */
    eProsima_user_DllExport const eprosima::fastcdr::fixed_string<256>& frame_id() const;

    /*!
     * @brief This function returns a reference to member frame_id
     * @return Reference to member frame_id
     */
    eProsima_user_DllExport eprosima::fastcdr::fixed_string<256>& frame_id();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Header& data,
            size_t current_alignment = 0);

private:

    int32_t m_sec{0};
    uint32_t m_nanosec{0};
    eprosima::fastcdr::fixed_string<256> m_frame_id;

};
/*!
 * @brief This class represents the structure Image defined by the user in the IDL file.
 * @ingroup datatypes
 */
class Image
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Image();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Image();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Image that will be copied.
     */
    eProsima_user_DllExport Image(
            const Image& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Image that will be copied.
     */
    eProsima_user_DllExport Image(
            Image&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Image that will be copied.
     */
    eProsima_user_DllExport Image& operator =(
            const Image& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Image that will be copied.
     */
    eProsima_user_DllExport Image& operator =(
            Image&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Image object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Image& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Image object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Image& x) const;

    /*!
     * @brief This function copies the value in member header_value
     * @param _header_value New value to be copied in member header_value
     */
    eProsima_user_DllExport void header_value(
            const Header& _header_value);

    /*!
     * @brief This function moves the value in member header_value
     * @param _header_value New value to be moved in member header_value
     */
    eProsima_user_DllExport void header_value(
            Header&& _header_value);

    /*!
     * @brief This function returns a constant reference to member header_value
     * @return Constant reference to member header_value
     */
    eProsima_user_DllExport const Header& header_value() const;

    /*!
     * @brief This function returns a reference to member header_value
     * @return Reference to member header_value
     */
    eProsima_user_DllExport Header& header_value();


    /*!
     * @brief This function sets a value in member height
     * @param _height New value for member height
     */
    eProsima_user_DllExport void height(
            uint32_t _height);

    /*!
     * @brief This function returns the value of member height
     * @return Value of member height
     */
    eProsima_user_DllExport uint32_t height() const;

    /*!
     * @brief This function returns a reference to member height
     * @return Reference to member height
     */
    eProsima_user_DllExport uint32_t& height();


    /*!
     * @brief This function sets a value in member width
     * @param _width New value for member width
     */
    eProsima_user_DllExport void width(
            uint32_t _width);

    /*!
     * @brief This function returns the value of member width
     * @return Value of member width
     */
    eProsima_user_DllExport uint32_t width() const;

    /*!
     * @brief This function returns a reference to member width
     * @return Reference to member width
     */
    eProsima_user_DllExport uint32_t& width();


    /*!
     * @brief This function copies the value in member encoding
     * @param _encoding New value to be copied in member encoding
     */
    eProsima_user_DllExport void encoding(
            const eprosima::fastcdr::fixed_string<256>& _encoding);

    /*!
     * @brief This function moves the value in member encoding
     * @param _encoding New value to be moved in member encoding
     */
    eProsima_user_DllExport void encoding(
            eprosima::fastcdr::fixed_string<256>&& _encoding);

    /*!
     * @brief This function returns a constant reference to member encoding
     * @return Constant reference to member encoding
     */
    eProsima_user_DllExport const eprosima::fastcdr::fixed_string<256>& encoding() const;

    /*!
     * @brief This function returns a reference to member encoding
     * @return Reference to member encoding
     */
    eProsima_user_DllExport eprosima::fastcdr::fixed_string<256>& encoding();


    /*!
     * @brief This function sets a value in member is_bigendian
     * @param _is_bigendian New value for member is_bigendian
     */
    eProsima_user_DllExport void is_bigendian(
            bool _is_bigendian);

    /*!
     * @brief This function returns the value of member is_bigendian
     * @return Value of member is_bigendian
     */
    eProsima_user_DllExport bool is_bigendian() const;

    /*!
     * @brief This function returns a reference to member is_bigendian
     * @return Reference to member is_bigendian
     */
    eProsima_user_DllExport bool& is_bigendian();


    /*!
     * @brief This function sets a value in member step
     * @param _step New value for member step
     */
    eProsima_user_DllExport void step(
            uint32_t _step);

    /*!
     * @brief This function returns the value of member step
     * @return Value of member step
     */
    eProsima_user_DllExport uint32_t step() const;

    /*!
     * @brief This function returns a reference to member step
     * @return Reference to member step
     */
    eProsima_user_DllExport uint32_t& step();


    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
            const std::vector<uint8_t>& _data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
            std::vector<uint8_t>&& _data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::vector<uint8_t>& data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::vector<uint8_t>& data();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Image& data,
            size_t current_alignment = 0);

private:

    Header m_header_value;
    uint32_t m_height{0};
    uint32_t m_width{0};
    eprosima::fastcdr::fixed_string<256> m_encoding;
    bool m_is_bigendian{false};
    uint32_t m_step{0};
    std::vector<uint8_t> m_data;

};
const uint8_t PointField__INT8 = 1;
const uint8_t PointField__UINT8 = 2;
const uint8_t PointField__INT16 = 3;
const uint8_t PointField__UINT16 = 4;
const uint8_t PointField__INT32 = 5;
const uint8_t PointField__UINT32 = 6;
const uint8_t PointField__FLOAT32 = 7;
const uint8_t PointField__FLOAT64 = 8;
/*!
 * @brief This class represents the structure PointField defined by the user in the IDL file.
 * @ingroup datatypes
 */
class PointField
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport PointField();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~PointField();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object PointField that will be copied.
     */
    eProsima_user_DllExport PointField(
            const PointField& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object PointField that will be copied.
     */
    eProsima_user_DllExport PointField(
            PointField&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object PointField that will be copied.
     */
    eProsima_user_DllExport PointField& operator =(
            const PointField& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object PointField that will be copied.
     */
    eProsima_user_DllExport PointField& operator =(
            PointField&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x PointField object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const PointField& x) const;

    /*!
     * @brief Comparison operator.
     * @param x PointField object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const PointField& x) const;

    /*!
     * @brief This function copies the value in member name
     * @param _name New value to be copied in member name
     */
    eProsima_user_DllExport void name(
            const eprosima::fastcdr::fixed_string<256>& _name);

    /*!
     * @brief This function moves the value in member name
     * @param _name New value to be moved in member name
     */
    eProsima_user_DllExport void name(
            eprosima::fastcdr::fixed_string<256>&& _name);

    /*!
     * @brief This function returns a constant reference to member name
     * @return Constant reference to member name
     */
    eProsima_user_DllExport const eprosima::fastcdr::fixed_string<256>& name() const;

    /*!
     * @brief This function returns a reference to member name
     * @return Reference to member name
     */
    eProsima_user_DllExport eprosima::fastcdr::fixed_string<256>& name();


    /*!
     * @brief This function sets a value in member offset
     * @param _offset New value for member offset
     */
    eProsima_user_DllExport void offset(
            uint32_t _offset);

    /*!
     * @brief This function returns the value of member offset
     * @return Value of member offset
     */
    eProsima_user_DllExport uint32_t offset() const;

    /*!
     * @brief This function returns a reference to member offset
     * @return Reference to member offset
     */
    eProsima_user_DllExport uint32_t& offset();


    /*!
     * @brief This function sets a value in member datatype
     * @param _datatype New value for member datatype
     */
    eProsima_user_DllExport void datatype(
            uint8_t _datatype);

    /*!
     * @brief This function returns the value of member datatype
     * @return Value of member datatype
     */
    eProsima_user_DllExport uint8_t datatype() const;

    /*!
     * @brief This function returns a reference to member datatype
     * @return Reference to member datatype
     */
    eProsima_user_DllExport uint8_t& datatype();


    /*!
     * @brief This function sets a value in member count
     * @param _count New value for member count
     */
    eProsima_user_DllExport void count(
            uint32_t _count);

    /*!
     * @brief This function returns the value of member count
     * @return Value of member count
     */
    eProsima_user_DllExport uint32_t count() const;

    /*!
     * @brief This function returns a reference to member count
     * @return Reference to member count
     */
    eProsima_user_DllExport uint32_t& count();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const PointField& data,
            size_t current_alignment = 0);

private:

    eprosima::fastcdr::fixed_string<256> m_name;
    uint32_t m_offset{0};
    uint8_t m_datatype{0};
    uint32_t m_count{0};

};
/*!
 * @brief This class represents the structure PointCloud2 defined by the user in the IDL file.
 * @ingroup datatypes
 */
class PointCloud2
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport PointCloud2();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~PointCloud2();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object PointCloud2 that will be copied.
     */
    eProsima_user_DllExport PointCloud2(
            const PointCloud2& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object PointCloud2 that will be copied.
     */
    eProsima_user_DllExport PointCloud2(
            PointCloud2&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object PointCloud2 that will be copied.
     */
    eProsima_user_DllExport PointCloud2& operator =(
            const PointCloud2& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object PointCloud2 that will be copied.
     */
    eProsima_user_DllExport PointCloud2& operator =(
            PointCloud2&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x PointCloud2 object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const PointCloud2& x) const;

    /*!
     * @brief Comparison operator.
     * @param x PointCloud2 object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const PointCloud2& x) const;

    /*!
     * @brief This function copies the value in member header_value
     * @param _header_value New value to be copied in member header_value
     */
    eProsima_user_DllExport void header_value(
            const Header& _header_value);

    /*!
     * @brief This function moves the value in member header_value
     * @param _header_value New value to be moved in member header_value
     */
    eProsima_user_DllExport void header_value(
            Header&& _header_value);

    /*!
     * @brief This function returns a constant reference to member header_value
     * @return Constant reference to member header_value
     */
    eProsima_user_DllExport const Header& header_value() const;

    /*!
     * @brief This function returns a reference to member header_value
     * @return Reference to member header_value
     */
    eProsima_user_DllExport Header& header_value();


    /*!
     * @brief This function sets a value in member height
     * @param _height New value for member height
     */
    eProsima_user_DllExport void height(
            uint32_t _height);

    /*!
     * @brief This function returns the value of member height
     * @return Value of member height
     */
    eProsima_user_DllExport uint32_t height() const;

    /*!
     * @brief This function returns a reference to member height
     * @return Reference to member height
     */
    eProsima_user_DllExport uint32_t& height();


    /*!
     * @brief This function sets a value in member width
     * @param _width New value for member width
     */
    eProsima_user_DllExport void width(
            uint32_t _width);

    /*!
     * @brief This function returns the value of member width
     * @return Value of member width
     */
    eProsima_user_DllExport uint32_t width() const;

    /*!
     * @brief This function returns a reference to member width
     * @return Reference to member width
     */
    eProsima_user_DllExport uint32_t& width();


    /*!
     * @brief This function copies the value in member fields
     * @param _fields New value to be copied in member fields
     */
    eProsima_user_DllExport void fields(
            const std::vector<PointField>& _fields);

    /*!
     * @brief This function moves the value in member fields
     * @param _fields New value to be moved in member fields
     */
    eProsima_user_DllExport void fields(
            std::vector<PointField>&& _fields);

    /*!
     * @brief This function returns a constant reference to member fields
     * @return Constant reference to member fields
     */
    eProsima_user_DllExport const std::vector<PointField>& fields() const;

    /*!
     * @brief This function returns a reference to member fields
     * @return Reference to member fields
     */
    eProsima_user_DllExport std::vector<PointField>& fields();


    /*!
     * @brief This function sets a value in member is_bigendian
     * @param _is_bigendian New value for member is_bigendian
     */
    eProsima_user_DllExport void is_bigendian(
            bool _is_bigendian);

    /*!
     * @brief This function returns the value of member is_bigendian
     * @return Value of member is_bigendian
     */
    eProsima_user_DllExport bool is_bigendian() const;

    /*!
     * @brief This function returns a reference to member is_bigendian
     * @return Reference to member is_bigendian
     */
    eProsima_user_DllExport bool& is_bigendian();


    /*!
     * @brief This function sets a value in member point_step
     * @param _point_step New value for member point_step
     */
    eProsima_user_DllExport void point_step(
            uint32_t _point_step);

    /*!
     * @brief This function returns the value of member point_step
     * @return Value of member point_step
     */
    eProsima_user_DllExport uint32_t point_step() const;

    /*!
     * @brief This function returns a reference to member point_step
     * @return Reference to member point_step
     */
    eProsima_user_DllExport uint32_t& point_step();


    /*!
     * @brief This function sets a value in member row_step
     * @param _row_step New value for member row_step
     */
    eProsima_user_DllExport void row_step(
            uint32_t _row_step);

    /*!
     * @brief This function returns the value of member row_step
     * @return Value of member row_step
     */
    eProsima_user_DllExport uint32_t row_step() const;

    /*!
     * @brief This function returns a reference to member row_step
     * @return Reference to member row_step
     */
    eProsima_user_DllExport uint32_t& row_step();


    /*!
     * @brief This function copies the value in member data
     * @param _data New value to be copied in member data
     */
    eProsima_user_DllExport void data(
            const std::vector<uint8_t>& _data);

    /*!
     * @brief This function moves the value in member data
     * @param _data New value to be moved in member data
     */
    eProsima_user_DllExport void data(
            std::vector<uint8_t>&& _data);

    /*!
     * @brief This function returns a constant reference to member data
     * @return Constant reference to member data
     */
    eProsima_user_DllExport const std::vector<uint8_t>& data() const;

    /*!
     * @brief This function returns a reference to member data
     * @return Reference to member data
     */
    eProsima_user_DllExport std::vector<uint8_t>& data();


    /*!
     * @brief This function sets a value in member is_dense
     * @param _is_dense New value for member is_dense
     */
    eProsima_user_DllExport void is_dense(
            bool _is_dense);

    /*!
     * @brief This function returns the value of member is_dense
     * @return Value of member is_dense
     */
    eProsima_user_DllExport bool is_dense() const;

    /*!
     * @brief This function returns a reference to member is_dense
     * @return Reference to member is_dense
     */
    eProsima_user_DllExport bool& is_dense();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const PointCloud2& data,
            size_t current_alignment = 0);

private:

    Header m_header_value;
    uint32_t m_height{0};
    uint32_t m_width{0};
    std::vector<PointField> m_fields;
    bool m_is_bigendian{false};
    uint32_t m_point_step{0};
    uint32_t m_row_step{0};
    std::vector<uint8_t> m_data;
    bool m_is_dense{false};

};
/*!
 * @brief This class represents the structure BigData defined by the user in the IDL file.
 * @ingroup datatypes
 */
class BigData
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport BigData();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~BigData();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object BigData that will be copied.
     */
    eProsima_user_DllExport BigData(
            const BigData& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object BigData that will be copied.
     */
    eProsima_user_DllExport BigData(
            BigData&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object BigData that will be copied.
     */
    eProsima_user_DllExport BigData& operator =(
            const BigData& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object BigData that will be copied.
     */
    eProsima_user_DllExport BigData& operator =(
            BigData&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x BigData object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const BigData& x) const;

    /*!
     * @brief Comparison operator.
     * @param x BigData object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const BigData& x) const;

    /*!
     * @brief This function copies the value in member timestamp_value
     * @param _timestamp_value New value to be copied in member timestamp_value
     */
    eProsima_user_DllExport void timestamp_value(
            const Timestamp& _timestamp_value);

    /*!
     * @brief This function moves the value in member timestamp_value
     * @param _timestamp_value New value to be moved in member timestamp_value
     */
    eProsima_user_DllExport void timestamp_value(
            Timestamp&& _timestamp_value);

    /*!
     * @brief This function returns a constant reference to member timestamp_value
     * @return Constant reference to member timestamp_value
     */
    eProsima_user_DllExport const Timestamp& timestamp_value() const;

    /*!
     * @brief This function returns a reference to member timestamp_value
     * @return Reference to member timestamp_value
     */
    eProsima_user_DllExport Timestamp& timestamp_value();


    /*!
     * @brief This function copies the value in member image_value
     * @param _image_value New value to be copied in member image_value
     */
    eProsima_user_DllExport void image_value(
            const Image& _image_value);

    /*!
     * @brief This function moves the value in member image_value
     * @param _image_value New value to be moved in member image_value
     */
    eProsima_user_DllExport void image_value(
            Image&& _image_value);

    /*!
     * @brief This function returns a constant reference to member image_value
     * @return Constant reference to member image_value
     */
    eProsima_user_DllExport const Image& image_value() const;

    /*!
     * @brief This function returns a reference to member image_value
     * @return Reference to member image_value
     */
    eProsima_user_DllExport Image& image_value();


    /*!
     * @brief This function copies the value in member point_cloud_value
     * @param _point_cloud_value New value to be copied in member point_cloud_value
     */
    eProsima_user_DllExport void point_cloud_value(
            const PointCloud2& _point_cloud_value);

    /*!
     * @brief This function moves the value in member point_cloud_value
     * @param _point_cloud_value New value to be moved in member point_cloud_value
     */
    eProsima_user_DllExport void point_cloud_value(
            PointCloud2&& _point_cloud_value);

    /*!
     * @brief This function returns a constant reference to member point_cloud_value
     * @return Constant reference to member point_cloud_value
     */
    eProsima_user_DllExport const PointCloud2& point_cloud_value() const;

    /*!
     * @brief This function returns a reference to member point_cloud_value
     * @return Reference to member point_cloud_value
     */
    eProsima_user_DllExport PointCloud2& point_cloud_value();


    /*!
     * @brief This function sets a value in member index
     * @param _index New value for member index
     */
    eProsima_user_DllExport void index(
            uint32_t _index);

    /*!
     * @brief This function returns the value of member index
     * @return Value of member index
     */
    eProsima_user_DllExport uint32_t index() const;

    /*!
     * @brief This function returns a reference to member index
     * @return Reference to member index
     */
    eProsima_user_DllExport uint32_t& index();

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const BigData& data,
            size_t current_alignment = 0);

private:

    Timestamp m_timestamp_value;
    Image m_image_value;
    PointCloud2 m_point_cloud_value;
    uint32_t m_index{0};

};

#endif // _FAST_DDS_GENERATED_DATATYPES_H_

