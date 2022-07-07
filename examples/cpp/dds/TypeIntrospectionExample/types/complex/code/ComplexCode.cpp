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
 * @file HelloWorldCode.cpp
 *
 */

#include <fastrtps/types/DynamicDataPtr.h>
#include <fastrtps/types/DynamicDataFactory.h>
#include <fastrtps/types/DynamicTypeBuilderFactory.h>
#include <fastrtps/types/DynamicTypeBuilderPtr.h>

#include "../../types.hpp"

using namespace eprosima::fastrtps;

template <>
eprosima::fastrtps::types::DynamicType_ptr
    DataType<DataTypeKind::COMPLEX , GeneratorKind::CODE>::generate_type_() const
{
    // Tmp variable to avoid calling get_instance many times
    types::DynamicTypeBuilderFactory *builder_factory =
        types::DynamicTypeBuilderFactory::get_instance();

    /////
    // Main Data structure
    types::DynamicTypeBuilder_ptr builder =
        builder_factory->create_struct_builder();

    // Add index
    builder->add_member(0, "index", builder_factory->create_uint32_type());

    /////
    // Substructure with 3 points
    // Add values
    types::DynamicTypeBuilder_ptr points_builder =
        types::DynamicTypeBuilderFactory::get_instance()->create_struct_builder();
    points_builder->add_member(0, "x_member", types::DynamicTypeBuilderFactory::get_instance()->create_int32_type());
    points_builder->add_member(1, "y_member", types::DynamicTypeBuilderFactory::get_instance()->create_int32_type());
    points_builder->add_member(2, "z_member", types::DynamicTypeBuilderFactory::get_instance()->create_int32_type());

    builder->add_member(1, "internal_data", points_builder->build());

    /////
    // Substructure of message
    types::DynamicTypeBuilder_ptr message_builder =
        types::DynamicTypeBuilderFactory::get_instance()->create_struct_builder();
    message_builder->add_member(0, "message", types::DynamicTypeBuilderFactory::get_instance()->create_string_type());

    /////
    // Add array of size 3 messages to main structure
    types::DynamicTypeBuilder_ptr array_builder =
        types::DynamicTypeBuilderFactory::get_instance()->create_array_builder(
            message_builder->build(),
            {3});

    builder->add_member(2, "messages", array_builder->build());

    // Set name
    builder->set_name(COMPLEX_DATA_TYPE_NAME);

    // Create Dynamic type
    types::DynamicType_ptr dyn_type = builder->build();

    return dyn_type;
}
