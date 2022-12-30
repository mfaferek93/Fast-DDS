// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/**
 * @file TypeIntrospectionPublisher.cpp
 *
 */

#include <csignal>
#include <thread>

#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv6TransportDescriptor.h>
#include <fastdds/rtps/common/Time_t.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/xmlparser/XMLProfileManager.h>
#include <fastrtps/types/DynamicPubSubType.h>
#include <fastrtps/types/DynamicDataPtr.h>
#include <fastrtps/types/DynamicDataFactory.h>

#include "TypeIntrospectionPublisher.h"

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastrtps::rtps;
using namespace eprosima::fastrtps;

std::atomic<bool> TypeIntrospectionPublisher::stop_(false);

TypeIntrospectionPublisher::TypeIntrospectionPublisher(
        const std::string& topic_name,
        const uint32_t domain,
        DataTypeKind data_type_kind,
        GeneratorKind generator_kind,
        bool use_type_object,
        bool use_type_information)
    : data_type_(data_type_factory(data_type_kind, generator_kind))
    , participant_(nullptr)
    , publisher_(nullptr)
    , topic_(nullptr)
    , writer_(nullptr)
{
    DomainParticipantQos pqos;
    pqos.name("TypeIntrospectionExample_Participant_Publisher");

    // Set to be used as a type lookup server
    // pqos.wire_protocol().builtin.discovery_config.discoveryProtocol = SIMPLE;
    // pqos.wire_protocol().builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
    // pqos.wire_protocol().builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
    // pqos.wire_protocol().builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
    // pqos.wire_protocol().builtin.use_WriterLivelinessProtocol = false;
    // pqos.wire_protocol().builtin.discovery_config.leaseDuration = c_TimeInfinite;

    if (use_type_information)
    {
        pqos.wire_protocol().builtin.typelookup_config.use_server = true;
    }

    // CREATE THE PARTICIPANT
    participant_ = DomainParticipantFactory::get_instance()->create_participant(domain, pqos);

    if (participant_ == nullptr)
    {
        throw std::runtime_error("Error creating participant");
    }

    // REGISTER THE TYPE
    // Get type from data_type_ manager
    types::DynamicType_ptr dyn_type = data_type_->get_type();
    eprosima::fastdds::dds::TypeSupport type(new eprosima::fastrtps::types::DynamicPubSubType(dyn_type));

    // Set type so introspection info is sent
    if (use_type_information)
    {
        type->auto_fill_type_information(true);
    }
    else
    {
        type->auto_fill_type_information(false);
    }

    if (use_type_object)
    {
        type->auto_fill_type_object(true);
    }
    else
    {
        type->auto_fill_type_object(false);
    }

    // Register Participant
    participant_->register_type(type);

    // CREATE THE PUBLISHER
    publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, this);

    if (publisher_ == nullptr)
    {
        throw std::runtime_error("Error creating publisher");
    }

    // CREATE THE TOPIC
    topic_ = participant_->create_topic(topic_name, data_type_->name(), TOPIC_QOS_DEFAULT);

    if (topic_ == nullptr)
    {
        throw std::runtime_error("Error creating topic");
    }

    // CREATE THE WRITER
    DataWriterQos wqos = DATAWRITER_QOS_DEFAULT;
    wqos.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    wqos.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS;

    writer_ = publisher_->create_datawriter(topic_, wqos, this);

    if (writer_ == nullptr)
    {
        throw std::runtime_error("Error creating data writer");
    }

    std::cout <<
        "Participant < " << participant_->guid() <<
        " > created in domain < " << participant_->get_domain_id() <<
        " > with writer < " << writer_->guid() <<
        " > with topic < " << topic_name <<
        " > with data type < " << data_type_->name() <<
        " > generated by < " << generator_kind <<
        " > using to send data type : " <<
        (use_type_information ? "< type information > " : "") <<
        (use_type_object ? "< type object > " : "") <<
        ((writer_->get_type()->m_isGetKeyDefined) ? ". Topic with @key ." : "") <<
        std::endl;

    std::cout << "Data Type for this Publisher is: " << data_type_->get_type() << std::endl;
}

bool TypeIntrospectionPublisher::is_stopped()
{
    return stop_;
}

void TypeIntrospectionPublisher::stop()
{
    stop_ = true;
}

TypeIntrospectionPublisher::~TypeIntrospectionPublisher()
{
    if (participant_ != nullptr)
    {
        if (publisher_ != nullptr)
        {
            if (writer_ != nullptr)
            {
                publisher_->delete_datawriter(writer_);
            }
            participant_->delete_publisher(publisher_);
        }
        if (topic_ != nullptr)
        {
            participant_->delete_topic(topic_);
        }
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }
}

void TypeIntrospectionPublisher::on_participant_discovery(
        eprosima::fastdds::dds::DomainParticipant*,
        eprosima::fastrtps::rtps::ParticipantDiscoveryInfo&& info)
{
    if (info.status == eprosima::fastrtps::rtps::ParticipantDiscoveryInfo::DISCOVERED_PARTICIPANT)
    {
        std::cout << "Participant found with guid: " << info.info.m_guid << std::endl;
    }
    // TODO
}

void TypeIntrospectionPublisher::on_publication_matched(
        eprosima::fastdds::dds::DataWriter*,
        const eprosima::fastdds::dds::PublicationMatchedStatus& info)
{
    if (info.current_count_change == 1)
    {
        std::cout << "Publisher matched with Reader: " << info.last_subscription_handle << std::endl;
    }
    else if (info.current_count_change == -1)
    {
        std::cout << "Publisher unmatched with Reader: " << info.last_subscription_handle << std::endl;
    }
    else
    {
        std::cout << info.current_count_change
                  << " is not a valid value for PublicationMatchedStatus current count change" << std::endl;
    }
}

void TypeIntrospectionPublisher::runThread(
        uint32_t samples,
        uint32_t sleep)
{
    unsigned int samples_sent = 0;
    while (!is_stopped() && (samples == 0 || samples_sent < samples))
    {
        publish(samples_sent);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        ++samples_sent;
    }
}

void TypeIntrospectionPublisher::run(
        uint32_t samples,
        uint32_t sleep)
{
    stop_ = false;
    std::thread thread(&TypeIntrospectionPublisher::runThread, this, samples, sleep);

    if (samples == 0)
    {
        std::cout << "Publisher running. Please press CTRL+C to stop the Publisher at any time." << std::endl;
    }
    else
    {
        std::cout << "Publisher running for " << samples <<
            " samples. Please press CTRL+C to stop the Publisher at any time." << std::endl;
    }
    signal(SIGINT, [](int signum)
            {
                std::cout << "SIGINT received, stopping Publisher execution." << std::endl;
                static_cast<void>(signum);
                TypeIntrospectionPublisher::stop();
            });
    thread.join();
}

void TypeIntrospectionPublisher::publish(unsigned int msg_index)
{
    // Get data depending on data_type
    auto dyn_data_ = data_type_->get_data(msg_index);

    // Publish data
    writer_->write(dyn_data_.get());

    std::cout << "Message published: \n" << dyn_data_ << std::endl;
}
