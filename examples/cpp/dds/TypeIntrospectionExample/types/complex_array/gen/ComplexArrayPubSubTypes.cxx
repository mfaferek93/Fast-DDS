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
 * @file ComplexArrayPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "ComplexArrayPubSubTypes.h"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;

InternalArrayPoints_TypeIntrospectionExamplePubSubType::InternalArrayPoints_TypeIntrospectionExamplePubSubType()
{
    setName("InternalArrayPoints_TypeIntrospectionExample");
    auto type_size = InternalArrayPoints_TypeIntrospectionExample::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = InternalArrayPoints_TypeIntrospectionExample::isKeyDefined();
    size_t keyLength = InternalArrayPoints_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16 ?
            InternalArrayPoints_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

InternalArrayPoints_TypeIntrospectionExamplePubSubType::~InternalArrayPoints_TypeIntrospectionExamplePubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool InternalArrayPoints_TypeIntrospectionExamplePubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    InternalArrayPoints_TypeIntrospectionExample* p_type = static_cast<InternalArrayPoints_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool InternalArrayPoints_TypeIntrospectionExamplePubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        //Convert DATA to pointer of your type
        InternalArrayPoints_TypeIntrospectionExample* p_type = static_cast<InternalArrayPoints_TypeIntrospectionExample*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> InternalArrayPoints_TypeIntrospectionExamplePubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<InternalArrayPoints_TypeIntrospectionExample*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* InternalArrayPoints_TypeIntrospectionExamplePubSubType::createData()
{
    return reinterpret_cast<void*>(new InternalArrayPoints_TypeIntrospectionExample());
}

void InternalArrayPoints_TypeIntrospectionExamplePubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<InternalArrayPoints_TypeIntrospectionExample*>(data));
}

bool InternalArrayPoints_TypeIntrospectionExamplePubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    InternalArrayPoints_TypeIntrospectionExample* p_type = static_cast<InternalArrayPoints_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            InternalArrayPoints_TypeIntrospectionExample::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || InternalArrayPoints_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

InternalArrayMessage_TypeIntrospectionExamplePubSubType::InternalArrayMessage_TypeIntrospectionExamplePubSubType()
{
    setName("InternalArrayMessage_TypeIntrospectionExample");
    auto type_size = InternalArrayMessage_TypeIntrospectionExample::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = InternalArrayMessage_TypeIntrospectionExample::isKeyDefined();
    size_t keyLength = InternalArrayMessage_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16 ?
            InternalArrayMessage_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

InternalArrayMessage_TypeIntrospectionExamplePubSubType::~InternalArrayMessage_TypeIntrospectionExamplePubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool InternalArrayMessage_TypeIntrospectionExamplePubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    InternalArrayMessage_TypeIntrospectionExample* p_type = static_cast<InternalArrayMessage_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool InternalArrayMessage_TypeIntrospectionExamplePubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        //Convert DATA to pointer of your type
        InternalArrayMessage_TypeIntrospectionExample* p_type = static_cast<InternalArrayMessage_TypeIntrospectionExample*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> InternalArrayMessage_TypeIntrospectionExamplePubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<InternalArrayMessage_TypeIntrospectionExample*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* InternalArrayMessage_TypeIntrospectionExamplePubSubType::createData()
{
    return reinterpret_cast<void*>(new InternalArrayMessage_TypeIntrospectionExample());
}

void InternalArrayMessage_TypeIntrospectionExamplePubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<InternalArrayMessage_TypeIntrospectionExample*>(data));
}

bool InternalArrayMessage_TypeIntrospectionExamplePubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    InternalArrayMessage_TypeIntrospectionExample* p_type = static_cast<InternalArrayMessage_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            InternalArrayMessage_TypeIntrospectionExample::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || InternalArrayMessage_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

ComplexArray_TypeIntrospectionExamplePubSubType::ComplexArray_TypeIntrospectionExamplePubSubType()
{
    setName("ComplexArray_TypeIntrospectionExample");
    auto type_size = ComplexArray_TypeIntrospectionExample::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = ComplexArray_TypeIntrospectionExample::isKeyDefined();
    size_t keyLength = ComplexArray_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16 ?
            ComplexArray_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

ComplexArray_TypeIntrospectionExamplePubSubType::~ComplexArray_TypeIntrospectionExamplePubSubType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool ComplexArray_TypeIntrospectionExamplePubSubType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    ComplexArray_TypeIntrospectionExample* p_type = static_cast<ComplexArray_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

bool ComplexArray_TypeIntrospectionExamplePubSubType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    try
    {
        //Convert DATA to pointer of your type
        ComplexArray_TypeIntrospectionExample* p_type = static_cast<ComplexArray_TypeIntrospectionExample*>(data);

        // Object that manages the raw buffer.
        eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

        // Object that deserializes the data.
        eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

        // Deserialize encapsulation.
        deser.read_encapsulation();
        payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> ComplexArray_TypeIntrospectionExamplePubSubType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ComplexArray_TypeIntrospectionExample*>(data))) +
                      4u /*encapsulation*/;
           };
}

void* ComplexArray_TypeIntrospectionExamplePubSubType::createData()
{
    return reinterpret_cast<void*>(new ComplexArray_TypeIntrospectionExample());
}

void ComplexArray_TypeIntrospectionExamplePubSubType::deleteData(
        void* data)
{
    delete(reinterpret_cast<ComplexArray_TypeIntrospectionExample*>(data));
}

bool ComplexArray_TypeIntrospectionExamplePubSubType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    ComplexArray_TypeIntrospectionExample* p_type = static_cast<ComplexArray_TypeIntrospectionExample*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            ComplexArray_TypeIntrospectionExample::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || ComplexArray_TypeIntrospectionExample::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

