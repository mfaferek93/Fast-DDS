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
 * @file monitorservice_typesPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastddsgen.
 */


#ifndef _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_PUBSUBTYPES_H_

#include <fastdds/dds/core/policy/QosPolicies.hpp>
#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastdds/rtps/common/InstanceHandle.hpp>
#include <fastdds/rtps/common/SerializedPayload.h>
#include <fastdds/utils/md5.h>

#include "monitorservice_types.hpp"

#include "typesPubSubTypes.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 2)
#error \
    Generated monitorservice_types is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER

namespace eprosima
{
    namespace fastdds
    {
        namespace statistics
        {

            /*!
             * @brief This class represents the TopicDataType of the type Connection defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class ConnectionPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef Connection type;

                eProsima_user_DllExport ConnectionPubSubType();

                eProsima_user_DllExport ~ConnectionPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };

            /*!
             * @brief This class represents the TopicDataType of the type QosPolicyCount_s defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class QosPolicyCount_sPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef QosPolicyCount_s type;

                eProsima_user_DllExport QosPolicyCount_sPubSubType();

                eProsima_user_DllExport ~QosPolicyCount_sPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return true;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };

            /*!
             * @brief This class represents the TopicDataType of the type BaseStatus_s defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class BaseStatus_sPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef BaseStatus_s type;

                eProsima_user_DllExport BaseStatus_sPubSubType();

                eProsima_user_DllExport ~BaseStatus_sPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return true;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };
            typedef std::vector<eprosima::fastdds::statistics::QosPolicyCount_s> QosPolicyCountSeq_s;

            /*!
             * @brief This class represents the TopicDataType of the type IncompatibleQoSStatus_s defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class IncompatibleQoSStatus_sPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef IncompatibleQoSStatus_s type;

                eProsima_user_DllExport IncompatibleQoSStatus_sPubSubType();

                eProsima_user_DllExport ~IncompatibleQoSStatus_sPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };

            /*!
             * @brief This class represents the TopicDataType of the type LivelinessChangedStatus_s defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class LivelinessChangedStatus_sPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef LivelinessChangedStatus_s type;

                eProsima_user_DllExport LivelinessChangedStatus_sPubSubType();

                eProsima_user_DllExport ~LivelinessChangedStatus_sPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return true;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };

            /*!
             * @brief This class represents the TopicDataType of the type DeadlineMissedStatus_s defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class DeadlineMissedStatus_sPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef DeadlineMissedStatus_s type;

                eProsima_user_DllExport DeadlineMissedStatus_sPubSubType();

                eProsima_user_DllExport ~DeadlineMissedStatus_sPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return true;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };
            typedef eprosima::fastdds::statistics::BaseStatus_s LivelinessLostStatus_s;
            typedef eprosima::fastdds::statistics::BaseStatus_s InconsistentTopicStatus_s;
            typedef eprosima::fastdds::statistics::BaseStatus_s SampleLostStatus_s;
            namespace StatusKind
            {
                typedef uint32_t StatusKind;









            } // namespace StatusKind


            /*!
             * @brief This class represents the TopicDataType of the type MonitorServiceStatusData defined by the user in the IDL file.
             * @ingroup monitorservice_types
             */
            class MonitorServiceStatusDataPubSubType : public eprosima::fastdds::dds::TopicDataType
            {
            public:

                typedef MonitorServiceStatusData type;

                eProsima_user_DllExport MonitorServiceStatusDataPubSubType();

                eProsima_user_DllExport ~MonitorServiceStatusDataPubSubType() override;

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload) override
                {
                    return serialize(data, payload, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport bool serialize(
                        void* data,
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool deserialize(
                        eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                        void* data) override;

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data) override
                {
                    return getSerializedSizeProvider(data, eprosima::fastdds::dds::DEFAULT_DATA_REPRESENTATION);
                }

                eProsima_user_DllExport std::function<uint32_t()> getSerializedSizeProvider(
                        void* data,
                        eprosima::fastdds::dds::DataRepresentationId_t data_representation) override;

                eProsima_user_DllExport bool getKey(
                        void* data,
                        eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                        bool force_md5 = false) override;

                eProsima_user_DllExport void* createData() override;

                eProsima_user_DllExport void deleteData(
                        void* data) override;

                //Register TypeObject representation in Fast DDS TypeObjectRegistry
                eProsima_user_DllExport void register_type_object_representation() const override;

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
                eProsima_user_DllExport inline bool is_bounded() const override
                {
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

            #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
                eProsima_user_DllExport inline bool is_plain() const override
                {
                    return false;
                }

                eProsima_user_DllExport inline bool is_plain(
                    eprosima::fastdds::dds::DataRepresentationId_t data_representation) const override
                {
                    static_cast<void>(data_representation);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

            #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
                eProsima_user_DllExport inline bool construct_sample(
                        void* memory) const override
                {
                    static_cast<void>(memory);
                    return false;
                }

            #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

                MD5 m_md5;
                unsigned char* m_keyBuffer;

            };
        } // namespace statistics
    } // namespace fastdds
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_EPROSIMA_FASTDDS_STATISTICS_MONITORSERVICE_TYPES_PUBSUBTYPES_H_

