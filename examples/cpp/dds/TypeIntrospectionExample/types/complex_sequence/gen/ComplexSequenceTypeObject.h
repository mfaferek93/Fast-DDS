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
 * @file ComplexSequenceTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _FAST_DDS_GENERATED_COMPLEXSEQUENCE_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_COMPLEXSEQUENCE_TYPE_OBJECT_H_


#include <fastrtps/types/TypeObject.h>
#include <map>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif // if defined(EPROSIMA_USER_DLL_EXPORT)
#else
#define eProsima_user_DllExport
#endif // if defined(_WIN32)

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(ComplexSequence_SOURCE)
#define ComplexSequence_DllAPI __declspec( dllexport )
#else
#define ComplexSequence_DllAPI __declspec( dllimport )
#endif // ComplexSequence_SOURCE
#else
#define ComplexSequence_DllAPI
#endif // if defined(EPROSIMA_USER_DLL_EXPORT)
#else
#define ComplexSequence_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerComplexSequenceTypes();

eProsima_user_DllExport const TypeIdentifier* GetInternalSequencePoints_TypeIntrospectionExampleIdentifier(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetInternalSequencePoints_TypeIntrospectionExampleObject(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInternalSequencePoints_TypeIntrospectionExampleObject();
eProsima_user_DllExport const TypeObject* GetCompleteInternalSequencePoints_TypeIntrospectionExampleObject();

eProsima_user_DllExport const TypeIdentifier* GetInternalSequenceMessage_TypeIntrospectionExampleIdentifier(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetInternalSequenceMessage_TypeIntrospectionExampleObject(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalInternalSequenceMessage_TypeIntrospectionExampleObject();
eProsima_user_DllExport const TypeObject* GetCompleteInternalSequenceMessage_TypeIntrospectionExampleObject();

eProsima_user_DllExport const TypeIdentifier* GetComplexSequence_TypeIntrospectionExampleIdentifier(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetComplexSequence_TypeIntrospectionExampleObject(
        bool complete = false);
eProsima_user_DllExport const TypeObject* GetMinimalComplexSequence_TypeIntrospectionExampleObject();
eProsima_user_DllExport const TypeObject* GetCompleteComplexSequence_TypeIntrospectionExampleObject();


#endif // _FAST_DDS_GENERATED_COMPLEXSEQUENCE_TYPE_OBJECT_H_