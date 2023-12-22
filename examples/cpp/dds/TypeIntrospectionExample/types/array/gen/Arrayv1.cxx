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
 * @file Array.cpp
 * This source file contains the implementation of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Array.h"

#if FASTCDR_VERSION_MAJOR == 1

#include "ArrayTypeObject.h"

#include <fastcdr/Cdr.h>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

namespace helper { namespace internal {

enum class Size {
    UInt8,
    UInt16,
    UInt32,
    UInt64,
};

constexpr Size get_size(int s) {
    return (s <= 8 ) ? Size::UInt8:
           (s <= 16) ? Size::UInt16:
           (s <= 32) ? Size::UInt32: Size::UInt64;
}

template<Size s>
struct FindTypeH;

template<>
struct FindTypeH<Size::UInt8> {
    using type = std::uint8_t;
};

template<>
struct FindTypeH<Size::UInt16> {
    using type = std::uint16_t;
};

template<>
struct FindTypeH<Size::UInt32> {
    using type = std::uint32_t;
};

template<>
struct FindTypeH<Size::UInt64> {
    using type = std::uint64_t;
};
}

template<int S>
struct FindType {
    using type = typename internal::FindTypeH<internal::get_size(S)>::type;
};
}

#define Array_TypeIntrospectionExample_max_cdr_typesize 20ULL;




Array_TypeIntrospectionExample::Array_TypeIntrospectionExample()
{
    // unsigned long m_index
    m_index = 0;
    // long m_points
    memset(&m_points, 0, ((3)) * 4);

    // Just to register all known types
    registerArrayTypes();
}

Array_TypeIntrospectionExample::~Array_TypeIntrospectionExample()
{
}

Array_TypeIntrospectionExample::Array_TypeIntrospectionExample(
        const Array_TypeIntrospectionExample& x)
{
    m_index = x.m_index;


    m_points = x.m_points;

}

Array_TypeIntrospectionExample::Array_TypeIntrospectionExample(
        Array_TypeIntrospectionExample&& x) noexcept
{
    m_index = x.m_index;


    m_points = std::move(x.m_points);

}

Array_TypeIntrospectionExample& Array_TypeIntrospectionExample::operator =(
        const Array_TypeIntrospectionExample& x)
{
    m_index = x.m_index;


    m_points = x.m_points;

    return *this;
}

Array_TypeIntrospectionExample& Array_TypeIntrospectionExample::operator =(
        Array_TypeIntrospectionExample&& x) noexcept
{
    m_index = x.m_index;


    m_points = std::move(x.m_points);

    return *this;
}

bool Array_TypeIntrospectionExample::operator ==(
        const Array_TypeIntrospectionExample& x) const
{
    return (m_index == x.m_index &&
           m_points == x.m_points);
}

bool Array_TypeIntrospectionExample::operator !=(
        const Array_TypeIntrospectionExample& x) const
{
    return !(*this == x);
}

size_t Array_TypeIntrospectionExample::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return Array_TypeIntrospectionExample_max_cdr_typesize;
}

size_t Array_TypeIntrospectionExample::getCdrSerializedSize(
        const Array_TypeIntrospectionExample& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += (((3)) * 4) + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}


void Array_TypeIntrospectionExample::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    scdr << m_index;

    scdr << m_points;


}

void Array_TypeIntrospectionExample::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{
    dcdr >> m_index;



    dcdr >> m_points;


}


bool Array_TypeIntrospectionExample::isKeyDefined()
{
    return false;
}

void Array_TypeIntrospectionExample::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void Array_TypeIntrospectionExample::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t Array_TypeIntrospectionExample::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& Array_TypeIntrospectionExample::index()
{
    return m_index;
}


/*!
 * @brief This function copies the value in member points
 * @param _points New value to be copied in member points
 */
void Array_TypeIntrospectionExample::points(
        const std::array<int32_t, 3>& _points)
{
    m_points = _points;
}

/*!
 * @brief This function moves the value in member points
 * @param _points New value to be moved in member points
 */
void Array_TypeIntrospectionExample::points(
        std::array<int32_t, 3>&& _points)
{
    m_points = std::move(_points);
}

/*!
 * @brief This function returns a constant reference to member points
 * @return Constant reference to member points
 */
const std::array<int32_t, 3>& Array_TypeIntrospectionExample::points() const
{
    return m_points;
}

/*!
 * @brief This function returns a reference to member points
 * @return Reference to member points
 */
std::array<int32_t, 3>& Array_TypeIntrospectionExample::points()
{
    return m_points;
}




#endif // FASTCDR_VERSION_MAJOR == 1
