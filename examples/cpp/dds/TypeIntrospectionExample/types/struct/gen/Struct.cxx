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
 * @file Struct.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Struct.h"
#include "StructTypeObject.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

InternalStruct_TypeIntrospectionExample::InternalStruct_TypeIntrospectionExample()
{
    // m_x_member com.eprosima.idl.parser.typecode.PrimitiveTypeCode@13eb8acf
    m_x_member = 0;
    // m_y_member com.eprosima.idl.parser.typecode.PrimitiveTypeCode@51c8530f
    m_y_member = 0;
    // m_z_member com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7403c468
    m_z_member = 0;

    // Just to register all known types
    registerStructTypes();
}

InternalStruct_TypeIntrospectionExample::~InternalStruct_TypeIntrospectionExample()
{



}

InternalStruct_TypeIntrospectionExample::InternalStruct_TypeIntrospectionExample(
        const InternalStruct_TypeIntrospectionExample& x)
{
    m_x_member = x.m_x_member;
    m_y_member = x.m_y_member;
    m_z_member = x.m_z_member;
}

InternalStruct_TypeIntrospectionExample::InternalStruct_TypeIntrospectionExample(
        InternalStruct_TypeIntrospectionExample&& x)
{
    m_x_member = x.m_x_member;
    m_y_member = x.m_y_member;
    m_z_member = x.m_z_member;
}

InternalStruct_TypeIntrospectionExample& InternalStruct_TypeIntrospectionExample::operator =(
        const InternalStruct_TypeIntrospectionExample& x)
{

    m_x_member = x.m_x_member;
    m_y_member = x.m_y_member;
    m_z_member = x.m_z_member;

    return *this;
}

InternalStruct_TypeIntrospectionExample& InternalStruct_TypeIntrospectionExample::operator =(
        InternalStruct_TypeIntrospectionExample&& x)
{

    m_x_member = x.m_x_member;
    m_y_member = x.m_y_member;
    m_z_member = x.m_z_member;

    return *this;
}

bool InternalStruct_TypeIntrospectionExample::operator ==(
        const InternalStruct_TypeIntrospectionExample& x) const
{

    return (m_x_member == x.m_x_member && m_y_member == x.m_y_member && m_z_member == x.m_z_member);
}

bool InternalStruct_TypeIntrospectionExample::operator !=(
        const InternalStruct_TypeIntrospectionExample& x) const
{
    return !(*this == x);
}

size_t InternalStruct_TypeIntrospectionExample::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t InternalStruct_TypeIntrospectionExample::getCdrSerializedSize(
        const InternalStruct_TypeIntrospectionExample& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void InternalStruct_TypeIntrospectionExample::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_x_member;
    scdr << m_y_member;
    scdr << m_z_member;

}

void InternalStruct_TypeIntrospectionExample::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_x_member;
    dcdr >> m_y_member;
    dcdr >> m_z_member;
}

/*!
 * @brief This function sets a value in member x_member
 * @param _x_member New value for member x_member
 */
void InternalStruct_TypeIntrospectionExample::x_member(
        int32_t _x_member)
{
    m_x_member = _x_member;
}

/*!
 * @brief This function returns the value of member x_member
 * @return Value of member x_member
 */
int32_t InternalStruct_TypeIntrospectionExample::x_member() const
{
    return m_x_member;
}

/*!
 * @brief This function returns a reference to member x_member
 * @return Reference to member x_member
 */
int32_t& InternalStruct_TypeIntrospectionExample::x_member()
{
    return m_x_member;
}

/*!
 * @brief This function sets a value in member y_member
 * @param _y_member New value for member y_member
 */
void InternalStruct_TypeIntrospectionExample::y_member(
        int32_t _y_member)
{
    m_y_member = _y_member;
}

/*!
 * @brief This function returns the value of member y_member
 * @return Value of member y_member
 */
int32_t InternalStruct_TypeIntrospectionExample::y_member() const
{
    return m_y_member;
}

/*!
 * @brief This function returns a reference to member y_member
 * @return Reference to member y_member
 */
int32_t& InternalStruct_TypeIntrospectionExample::y_member()
{
    return m_y_member;
}

/*!
 * @brief This function sets a value in member z_member
 * @param _z_member New value for member z_member
 */
void InternalStruct_TypeIntrospectionExample::z_member(
        int32_t _z_member)
{
    m_z_member = _z_member;
}

/*!
 * @brief This function returns the value of member z_member
 * @return Value of member z_member
 */
int32_t InternalStruct_TypeIntrospectionExample::z_member() const
{
    return m_z_member;
}

/*!
 * @brief This function returns a reference to member z_member
 * @return Reference to member z_member
 */
int32_t& InternalStruct_TypeIntrospectionExample::z_member()
{
    return m_z_member;
}


size_t InternalStruct_TypeIntrospectionExample::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;






    return current_align;
}

bool InternalStruct_TypeIntrospectionExample::isKeyDefined()
{
    return false;
}

void InternalStruct_TypeIntrospectionExample::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
       
}

Struct_TypeIntrospectionExample::Struct_TypeIntrospectionExample()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@45afc369
    m_index = 0;
    // m_internal_data com.eprosima.fastdds.idl.parser.typecode.StructTypeCode@799d4f69


    // Just to register all known types
    registerStructTypes();
}

Struct_TypeIntrospectionExample::~Struct_TypeIntrospectionExample()
{


}

Struct_TypeIntrospectionExample::Struct_TypeIntrospectionExample(
        const Struct_TypeIntrospectionExample& x)
{
    m_index = x.m_index;
    m_internal_data = x.m_internal_data;
}

Struct_TypeIntrospectionExample::Struct_TypeIntrospectionExample(
        Struct_TypeIntrospectionExample&& x)
{
    m_index = x.m_index;
    m_internal_data = std::move(x.m_internal_data);
}

Struct_TypeIntrospectionExample& Struct_TypeIntrospectionExample::operator =(
        const Struct_TypeIntrospectionExample& x)
{

    m_index = x.m_index;
    m_internal_data = x.m_internal_data;

    return *this;
}

Struct_TypeIntrospectionExample& Struct_TypeIntrospectionExample::operator =(
        Struct_TypeIntrospectionExample&& x)
{

    m_index = x.m_index;
    m_internal_data = std::move(x.m_internal_data);

    return *this;
}

bool Struct_TypeIntrospectionExample::operator ==(
        const Struct_TypeIntrospectionExample& x) const
{

    return (m_index == x.m_index && m_internal_data == x.m_internal_data);
}

bool Struct_TypeIntrospectionExample::operator !=(
        const Struct_TypeIntrospectionExample& x) const
{
    return !(*this == x);
}

size_t Struct_TypeIntrospectionExample::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += InternalStruct_TypeIntrospectionExample::getMaxCdrSerializedSize(current_alignment);

    return current_alignment - initial_alignment;
}

size_t Struct_TypeIntrospectionExample::getCdrSerializedSize(
        const Struct_TypeIntrospectionExample& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += InternalStruct_TypeIntrospectionExample::getCdrSerializedSize(data.internal_data(), current_alignment);

    return current_alignment - initial_alignment;
}

void Struct_TypeIntrospectionExample::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_index;
    scdr << m_internal_data;

}

void Struct_TypeIntrospectionExample::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_index;
    dcdr >> m_internal_data;
}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void Struct_TypeIntrospectionExample::index(
        uint32_t _index)
{
    m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t Struct_TypeIntrospectionExample::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& Struct_TypeIntrospectionExample::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member internal_data
 * @param _internal_data New value to be copied in member internal_data
 */
void Struct_TypeIntrospectionExample::internal_data(
        const InternalStruct_TypeIntrospectionExample& _internal_data)
{
    m_internal_data = _internal_data;
}

/*!
 * @brief This function moves the value in member internal_data
 * @param _internal_data New value to be moved in member internal_data
 */
void Struct_TypeIntrospectionExample::internal_data(
        InternalStruct_TypeIntrospectionExample&& _internal_data)
{
    m_internal_data = std::move(_internal_data);
}

/*!
 * @brief This function returns a constant reference to member internal_data
 * @return Constant reference to member internal_data
 */
const InternalStruct_TypeIntrospectionExample& Struct_TypeIntrospectionExample::internal_data() const
{
    return m_internal_data;
}

/*!
 * @brief This function returns a reference to member internal_data
 * @return Reference to member internal_data
 */
InternalStruct_TypeIntrospectionExample& Struct_TypeIntrospectionExample::internal_data()
{
    return m_internal_data;
}

size_t Struct_TypeIntrospectionExample::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;





    return current_align;
}

bool Struct_TypeIntrospectionExample::isKeyDefined()
{
    return false;
}

void Struct_TypeIntrospectionExample::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
      
}
