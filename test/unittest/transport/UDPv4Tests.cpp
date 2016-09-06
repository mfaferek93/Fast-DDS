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

#include <fastrtps/transport/UDPv4Transport.h>
#include <gtest/gtest.h>
#include <boost/thread.hpp>
#include <fastrtps/utils/IPFinder.h>
#include <fastrtps/log/Log.h>
#include <memory>

using namespace std;
using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;
using namespace boost::interprocess;

#ifndef __APPLE__
const uint32_t ReceiveBufferCapacity = 65536;
#endif

class UDPv4Tests: public ::testing::Test 
{
    public:
        UDPv4Tests()
        {
            HELPER_SetDescriptorDefaults();
        }

        ~UDPv4Tests()
        {
            Log::KillThread();
        }

        void HELPER_SetDescriptorDefaults();

        UDPv4TransportDescriptor descriptor;
        unique_ptr<boost::thread> senderThread;
        unique_ptr<boost::thread> receiverThread;
};

TEST_F(UDPv4Tests, locators_with_kind_1_supported)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t supportedLocator;
    supportedLocator.kind = LOCATOR_KIND_UDPv4;
    Locator_t unsupportedLocator;
    unsupportedLocator.kind = LOCATOR_KIND_UDPv6;

    // Then
    ASSERT_TRUE(transportUnderTest.IsLocatorSupported(supportedLocator));
    ASSERT_FALSE(transportUnderTest.IsLocatorSupported(unsupportedLocator));
}

TEST_F(UDPv4Tests, opening_and_closing_output_channel)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t genericOutputChannelLocator;
    genericOutputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    genericOutputChannelLocator.port = 7400; // arbitrary

    // Then
    ASSERT_FALSE (transportUnderTest.IsOutputChannelOpen(genericOutputChannelLocator));
    ASSERT_TRUE  (transportUnderTest.OpenOutputChannel(genericOutputChannelLocator));
    ASSERT_TRUE  (transportUnderTest.IsOutputChannelOpen(genericOutputChannelLocator));
    ASSERT_TRUE  (transportUnderTest.CloseOutputChannel(genericOutputChannelLocator));
    ASSERT_FALSE (transportUnderTest.IsOutputChannelOpen(genericOutputChannelLocator));
    ASSERT_FALSE (transportUnderTest.CloseOutputChannel(genericOutputChannelLocator));
}

TEST_F(UDPv4Tests, opening_and_closing_input_channel)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t multicastFilterLocator;
    multicastFilterLocator.kind = LOCATOR_KIND_UDPv4;
    multicastFilterLocator.port = 7410; // arbitrary
    multicastFilterLocator.set_IP4_address(239, 255, 0, 1);

    // Then
    ASSERT_FALSE (transportUnderTest.IsInputChannelOpen(multicastFilterLocator));
    ASSERT_TRUE  (transportUnderTest.OpenInputChannel(multicastFilterLocator));
    ASSERT_TRUE  (transportUnderTest.IsInputChannelOpen(multicastFilterLocator));
    ASSERT_TRUE  (transportUnderTest.CloseInputChannel(multicastFilterLocator));
    ASSERT_FALSE (transportUnderTest.IsInputChannelOpen(multicastFilterLocator));
    ASSERT_FALSE (transportUnderTest.CloseInputChannel(multicastFilterLocator));
}

#ifndef __APPLE__
TEST_F(UDPv4Tests, send_and_receive_between_ports)
{
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t multicastLocator;
    multicastLocator.port = 7410;
    multicastLocator.kind = LOCATOR_KIND_UDPv4;
    multicastLocator.set_IP4_address(239, 255, 0, 1);

    Locator_t outputChannelLocator;
    outputChannelLocator.port = 7400;
    outputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    ASSERT_TRUE(transportUnderTest.OpenOutputChannel(outputChannelLocator)); // Includes loopback
    ASSERT_TRUE(transportUnderTest.OpenInputChannel(multicastLocator));
    octet message[5] = { 'H','e','l','l','o' };

    auto sendThreadFunction = [&]()
    {
        EXPECT_TRUE(transportUnderTest.Send(message, 5, outputChannelLocator, multicastLocator));
    };

    auto receiveThreadFunction = [&]() 
    {
        octet receiveBuffer[ReceiveBufferCapacity];
        uint32_t receiveBufferSize;

        Locator_t remoteLocatorToReceive;
        EXPECT_TRUE(transportUnderTest.Receive(receiveBuffer, ReceiveBufferCapacity, receiveBufferSize, multicastLocator, remoteLocatorToReceive));
        EXPECT_EQ(memcmp(message,receiveBuffer,5), 0);
    };

    receiverThread.reset(new boost::thread(receiveThreadFunction));      
    senderThread.reset(new boost::thread(sendThreadFunction));      
    senderThread->join();
    receiverThread->join();
}

TEST_F(UDPv4Tests, send_to_loopback)
{
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t multicastLocator;
    multicastLocator.port = 7410;
    multicastLocator.kind = LOCATOR_KIND_UDPv4;
    multicastLocator.set_IP4_address(239, 255, 0, 1);

    Locator_t outputChannelLocator;
    outputChannelLocator.port = 7400;
    outputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    outputChannelLocator.set_IP4_address(127,0,0,1); // Loopback
    ASSERT_TRUE(transportUnderTest.OpenOutputChannel(outputChannelLocator));
    ASSERT_TRUE(transportUnderTest.OpenInputChannel(multicastLocator));
    octet message[5] = { 'H','e','l','l','o' };

    auto sendThreadFunction = [&]()
    {
        Locator_t destinationLocator;
        destinationLocator.port = 7410;
        destinationLocator.kind = LOCATOR_KIND_UDPv4;
        EXPECT_TRUE(transportUnderTest.Send(message, 5, outputChannelLocator, multicastLocator));
    };

    auto receiveThreadFunction = [&]() 
    {
        octet receiveBuffer[ReceiveBufferCapacity];
        uint32_t receiveBufferSize;

        Locator_t remoteLocatorToReceive;
        EXPECT_TRUE(transportUnderTest.Receive(receiveBuffer, ReceiveBufferCapacity, receiveBufferSize, multicastLocator, remoteLocatorToReceive));
        EXPECT_EQ(memcmp(message,receiveBuffer,5), 0);
    };

    receiverThread.reset(new boost::thread(receiveThreadFunction));      
    senderThread.reset(new boost::thread(sendThreadFunction));      
    senderThread->join();
    receiverThread->join();
}
#endif

TEST_F(UDPv4Tests, send_is_rejected_if_buffer_size_is_bigger_to_size_specified_in_descriptor)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t genericOutputChannelLocator;
    genericOutputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    genericOutputChannelLocator.port = 7400;
    transportUnderTest.OpenOutputChannel(genericOutputChannelLocator);

    Locator_t destinationLocator;
    destinationLocator.kind = LOCATOR_KIND_UDPv4;
    destinationLocator.port = 7410;

    // Then
    vector<octet> receiveBufferWrongSize(descriptor.sendBufferSize + 1);
    ASSERT_FALSE(transportUnderTest.Send(receiveBufferWrongSize.data(), (uint32_t)receiveBufferWrongSize.size(), genericOutputChannelLocator, destinationLocator));
}

TEST_F(UDPv4Tests, Receive_is_rejected_if_buffer_size_is_smaller_than_size_specified_in_descriptor)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t genericInputChannelLocator;
    genericInputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    genericInputChannelLocator.port = 7410;
    transportUnderTest.OpenInputChannel(genericInputChannelLocator);

    Locator_t originLocator;
    octet* emptyBuffer = nullptr;
    uint32_t size;
    // Then
    ASSERT_FALSE(transportUnderTest.Receive(emptyBuffer,0, size, genericInputChannelLocator, originLocator));
}

TEST_F(UDPv4Tests, opening_any_output_address_opens_port_for_all_IP_addresses)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t specificOutputChannelLocator;
    specificOutputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    specificOutputChannelLocator.port = 7410;
    specificOutputChannelLocator.set_IP4_address(222,222,222,222);

    Locator_t differentOutputChannelLocator;
    differentOutputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    differentOutputChannelLocator.port = 7410;
    differentOutputChannelLocator.set_IP4_address(111,111,111,111);

    // When
    ASSERT_TRUE(transportUnderTest.OpenOutputChannel(specificOutputChannelLocator));

    // Then
    ASSERT_TRUE(transportUnderTest.IsOutputChannelOpen(differentOutputChannelLocator));
}

TEST_F(UDPv4Tests, RemoteToMainLocal_simply_strips_out_address_leaving_IP_ANY)
{
    // Given
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t remoteLocator;
    remoteLocator.kind = LOCATOR_KIND_UDPv4;
    remoteLocator.port = 7410;
    remoteLocator.set_IP4_address(222,222,222,222);

    // When
    Locator_t mainLocalLocator = transportUnderTest.RemoteToMainLocal(remoteLocator);

    ASSERT_EQ(mainLocalLocator.port, remoteLocator.port);
    ASSERT_EQ(mainLocalLocator.kind, remoteLocator.kind);

    ASSERT_EQ(mainLocalLocator.to_IP4_string(), "0.0.0.0");
}

TEST_F(UDPv4Tests, in_granular_mode_locators_match_if_port_AND_address_matches)
{
    // Given
    descriptor.granularMode = true;
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t locatorAlpha;
    locatorAlpha.port = 50000;
    locatorAlpha.set_IP4_address(239, 255, 0, 1);
    Locator_t locatorBeta = locatorAlpha;

    // Then
    ASSERT_TRUE(transportUnderTest.DoLocatorsMatch(locatorAlpha, locatorBeta));

    locatorBeta.set_IP4_address(100, 100, 100, 100);
    // Then
    ASSERT_FALSE(transportUnderTest.DoLocatorsMatch(locatorAlpha, locatorBeta));
}

TEST_F(UDPv4Tests, granular_send_to_wrong_interface)
{
    descriptor.granularMode = true;
    UDPv4Transport transportUnderTest(descriptor);
    transportUnderTest.init();

    Locator_t outputChannelLocator;
    outputChannelLocator.port = 7400;
    outputChannelLocator.kind = LOCATOR_KIND_UDPv4;
    outputChannelLocator.set_IP4_address(127,0,0,1); // Loopback
    ASSERT_TRUE(transportUnderTest.OpenOutputChannel(outputChannelLocator));

    //Sending through a different IP will NOT work in granular mode, except 0.0.0.0
    outputChannelLocator.set_IP4_address(111,111,111,111);
    vector<octet> message = { 'H','e','l','l','o' };
    ASSERT_FALSE(transportUnderTest.Send(message.data(), (uint32_t)message.size(), outputChannelLocator, Locator_t()));
}

void UDPv4Tests::HELPER_SetDescriptorDefaults()
{
    descriptor.maxMessageSize = 5;
    descriptor.sendBufferSize = 5;
    descriptor.receiveBufferSize = 5;
    descriptor.granularMode = false;
}

int main(int argc, char **argv)
{
    Log::SetVerbosity(Log::Info);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
