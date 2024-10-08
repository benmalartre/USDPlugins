//
// Copyright 2020 benmalartre
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//

#include "pxr/usd/usdAnimX/types.h"
#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/timeCode.h"

PXR_NAMESPACE_OPEN_SCOPE

#define ANIMX_VALUE_TYPE_TOKEN_INIT(r, unused, elem) \
    ANIMX_VALUE_TYPE_TOKEN(elem)                     \
        (BOOST_PP_STRINGIZE(                         \
          ANIMX_VALUE_SERIALIZATION_TYPE(elem)),     \
    TfToken::Immortal),

#define ANIMX_VALUE_TYPE_ARRAY_TOKEN_INIT(r, unused, elem)\
  BOOST_PP_CAT(ANIMX_VALUE_TYPE_TOKEN(elem), Array)       \
        (BOOST_PP_STRINGIZE(                              \
          ANIMX_VALUE_SERIALIZATION_TYPE(elem)[]),        \
    TfToken::Immortal),

#define ANIMX_VALUE_TYPE_TOKEN_VECTORIZE(r, unused, elem) \
    ANIMX_VALUE_TYPE_TOKEN(elem),

#define ANIMX_VALUE_TYPE_ARRAY_TOKEN_VECTORIZE(r, unused, elem) \
    BOOST_PP_CAT(ANIMX_VALUE_TYPE_TOKEN(elem), Array),

UsdAnimXValueTypeTokensType::UsdAnimXValueTypeTokensType() : 
    BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_TOKEN_INIT, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_ARRAY_TOKEN_INIT, ~, ANIMX_VALUE_TYPES)
    allTokens({
      BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_TOKEN_VECTORIZE, ~, ANIMX_VALUE_TYPES)
      BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_ARRAY_TOKEN_VECTORIZE, ~, ANIMX_VALUE_TYPES)
    })
{
}

TfStaticData<UsdAnimXValueTypeTokensType> UsdAnimXValueTypeTokens;

#undef ANIMX_VALUE_TYPE_TOKEN_INIT
#undef ANIMX_VALUE_TYPE_ARRAY_TOKEN_INIT
#undef ANIMX_VALUE_TYPE_TOKEN_VECTORIZE
#undef ANIMX_VALUE_TYPE_ARRAY_TOKEN_VECTORIZE

#define ANIMX_SDF_VALUE_TYPE_FROM_TOKEN(r, unused, elem)                   \
    if(token == UsdAnimXValueTypeTokens->ANIMX_VALUE_TYPE_TOKEN(elem))     \
        return SdfValueTypeNames->ANIMX_VALUE_SDF_TYPE(elem);

#define ANIMX_SDF_VALUE_TYPE_ARRAY_FROM_TOKEN(r, unused, elem)             \
    if(token == UsdAnimXValueTypeTokens->BOOST_PP_CAT(                     \
      ANIMX_VALUE_TYPE_TOKEN(elem), Array))                                \
        return SdfValueTypeNames->BOOST_PP_CAT(                            \
          ANIMX_VALUE_SDF_TYPE(elem), Array);

const SdfValueTypeName& AnimXGetSdfValueTypeNameFromToken(const TfToken& token)
{
    static SdfValueTypeName emptyTypeName;
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SDF_VALUE_TYPE_FROM_TOKEN, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SDF_VALUE_TYPE_ARRAY_FROM_TOKEN, ~, ANIMX_VALUE_TYPES)
    return emptyTypeName;
}
#undef ANIMX_SDF_VALUE_TYPE_FROM_TOKEN
#undef ANIMX_SDF_VALUE_TYPE_ARRAY_FROM_TOKEN

#define ANIMX_TOKEN_FROM_SDF_VALUE_TYPE(r, unused, elem)                      \
    if(type == SdfValueTypeNames->ANIMX_VALUE_SDF_TYPE(elem).GetType())       \
        return UsdAnimXValueTypeTokens->ANIMX_VALUE_TYPE_TOKEN(elem);

#define ANIMX_TOKEN_FROM_SDF_VALUE_TYPE_ARRAY(r, unused, elem)                \
    if(type == SdfValueTypeNames->BOOST_PP_CAT(                               \
      ANIMX_VALUE_SDF_TYPE(elem), Array).GetType())                           \
        return UsdAnimXValueTypeTokens->BOOST_PP_CAT(                         \
          ANIMX_VALUE_TYPE_TOKEN(elem), Array);

const TfToken& AnimXGetTokenFromSdfValueTypeName(const TfType& type)
{
    static TfToken emptyToken;
    BOOST_PP_SEQ_FOR_EACH(ANIMX_TOKEN_FROM_SDF_VALUE_TYPE, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_TOKEN_FROM_SDF_VALUE_TYPE_ARRAY, ~, ANIMX_VALUE_TYPES)
    return emptyToken;
}
#undef ANIMX_TOKEN_FROM_SDF_VALUE_TYPE
#undef ANIMX_TOKEN_FROM_SDF_VALUE_TYPE_ARRAY

#define ANIMX_SERIALIZATION_TYPE_FROM_TOKEN(r, unused, elem)                \
    if(token == UsdAnimXValueTypeTokens->ANIMX_VALUE_TYPE_TOKEN(elem))      \
        resultToken = TfToken                                               \
            (BOOST_PP_STRINGIZE(                                            \
                ANIMX_VALUE_SERIALIZATION_TYPE(elem)));

#define ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_TOKEN(r, unused, elem)          \
    if(token == UsdAnimXValueTypeTokens->BOOST_PP_CAT(                      \
      ANIMX_VALUE_TYPE_TOKEN(elem), Array))                                 \
        resultToken = TfToken                                               \
            (BOOST_PP_STRINGIZE(                                            \
                ANIMX_VALUE_SERIALIZATION_TYPE(elem)[]));

const TfToken& AnimXGetSerializationTypeNameFromToken(const TfToken& token)
{
    static TfToken resultToken;
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SERIALIZATION_TYPE_FROM_TOKEN, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_TOKEN, ~, ANIMX_VALUE_TYPES)
    return resultToken;
}
#undef ANIMX_SERIALIZATION_TYPE_FROM_TOKEN
#undef ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_TOKEN

#define ANIMX_SERIALIZATION_TYPE_FROM_SDF_VALUE_TYPE(r, unused, elem)       \
    if(type == SdfValueTypeNames->ANIMX_VALUE_SDF_TYPE(elem).GetType())     \
        resultToken = TfToken                                               \
            (BOOST_PP_STRINGIZE(                                            \
                ANIMX_VALUE_SERIALIZATION_TYPE(elem)));

#define ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_SDF_VALUE_TYPE(r, unused, elem) \
    if(type == SdfValueTypeNames->BOOST_PP_CAT(                             \
      ANIMX_VALUE_SDF_TYPE(elem), Array).GetType())                         \
        resultToken = TfToken                                               \
            (BOOST_PP_STRINGIZE(                                            \
                ANIMX_VALUE_SERIALIZATION_TYPE(elem)[]));

const TfToken& AnimXGetSerializationTypeNameFromSdfValueTypeName(const TfType& type)
{
    static TfToken resultToken;
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SERIALIZATION_TYPE_FROM_SDF_VALUE_TYPE, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_SDF_VALUE_TYPE, ~, ANIMX_VALUE_TYPES)
    return resultToken;
}
#undef ANIMX_SERIALIZATION_TYPE_FROM_SDF_VALUE_TYPE
#undef ANIMX_SERIALIZATION_TYPE_ARRAY_FROM_SDF_VALUE_TYPE

PXR_NAMESPACE_CLOSE_SCOPE
