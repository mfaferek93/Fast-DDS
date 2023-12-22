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
 * @file Key.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#include <fastcdr/config.h>

#if FASTCDR_VERSION_MAJOR == 1

#ifndef _FAST_DDS_GENERATED_KEY_H_
#define _FAST_DDS_GENERATED_KEY_H_


#include <fastrtps/utils/fixed_size_string.hpp>

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

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
#if defined(KEY_SOURCE)
#define KEY_DllAPI __declspec( dllexport )
#else
#define KEY_DllAPI __declspec( dllimport )
#endif // KEY_SOURCE
#else
#define KEY_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define KEY_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima





/*!
 * @brief This class represents the structure Key_TypeIntrospectionExample defined by the user in the IDL file.
 * @ingroup Key
 */
class Key_TypeIntrospectionExample
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Key_TypeIntrospectionExample();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Key_TypeIntrospectionExample();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Key_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Key_TypeIntrospectionExample(
            const Key_TypeIntrospectionExample& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Key_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Key_TypeIntrospectionExample(
            Key_TypeIntrospectionExample&& x) noexcept;

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Key_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Key_TypeIntrospectionExample& operator =(
            const Key_TypeIntrospectionExample& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Key_TypeIntrospectionExample that will be copied.
     */
    eProsima_user_DllExport Key_TypeIntrospectionExample& operator =(
            Key_TypeIntrospectionExample&& x) noexcept;

    /*!
     * @brief Comparison operator.
     * @param x Key_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator ==(
            const Key_TypeIntrospectionExample& x) const;

    /*!
     * @brief Comparison operator.
     * @param x Key_TypeIntrospectionExample object to compare.
     */
    eProsima_user_DllExport bool operator !=(
            const Key_TypeIntrospectionExample& x) const;

    /*!
     * @brief This function copies the value in member instance_key
     * @param _instance_key New value to be copied in member instance_key
     */
    eProsima_user_DllExport void instance_key(
            const std::string& _instance_key);

    /*!
     * @brief This function moves the value in member instance_key
     * @param _instance_key New value to be moved in member instance_key
     */
    eProsima_user_DllExport void instance_key(
            std::string&& _instance_key);

    /*!
     * @brief This function returns a constant reference to member instance_key
     * @return Constant reference to member instance_key
     */
    eProsima_user_DllExport const std::string& instance_key() const;

    /*!
     * @brief This function returns a reference to member instance_key
     * @return Reference to member instance_key
     */
    eProsima_user_DllExport std::string& instance_key();


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
     * @brief This function sets a value in member value
     * @param _value New value for member value
     */
    eProsima_user_DllExport void value(
            int32_t _value);

    /*!
     * @brief This function returns the value of member value
     * @return Value of member value
     */
    eProsima_user_DllExport int32_t value() const;

    /*!
     * @brief This function returns a reference to member value
     * @return Reference to member value
     */
    eProsima_user_DllExport int32_t& value();


    /*!
    * @brief This function returns the maximum serialized size of an object
    * depending on the buffer alignment.
    * @param current_alignment Buffer alignment.
    * @return Maximum serialized size.
    */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const Key_TypeIntrospectionExample& data,
            size_t current_alignment = 0);



    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);




    /*!
    * @brief This function tells you if the Key has been defined for this type
    */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
    * @brief This function serializes the key members of an object using CDR serialization.
    * @param cdr CDR serialization object.
    */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;


private:

    std::string m_instance_key;
    uint32_t m_index;
    int32_t m_value;

};


#endif // _FAST_DDS_GENERATED_KEY_H_



#endif // FASTCDR_VERSION_MAJOR == 1
