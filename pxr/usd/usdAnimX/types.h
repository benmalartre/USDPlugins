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
#ifndef PXR_USD_USD_ANIMX_TYPES_H
#define PXR_USD_USD_ANIMX_TYPES_H

#include "pxr/pxr.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include "pxr/base/vt/value.h"
#include "pxr/usd/sdf/valueTypeName.h"
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/stringize.hpp> 
#include <vector>
#include <typeinfo>
#include "pxr/usd/usdAnimX/api.h"

PXR_NAMESPACE_OPEN_SCOPE

/// SdfValueTypeName, Serialization, Token
///
#define _ANIMX_SCALAR_VALUE_TYPES               \
    ((Bool,       bool,       bool_,         )) \
    ((UChar,      uchar,      uchar_,        )) \
    ((Int,        int,        int_,          )) \
    ((UInt,       uint,       uint_,         )) \
    ((Int64,      int64,      int64_,        )) \
    ((UInt64,     uint64,     uint64_,       )) \
    ((Half,       half,       half_,         )) \
    ((Float,      float,      float_,        )) \
    ((Double,     double,     double_,       )) \
    ((TimeCode,   timecode,   timecode_,     )) \
    ((Token,      token,      token_,        ))

#define _ANIMX_DIMENSIONED_VALUE_TYPES          \
    ((Matrix2d,   matrix2d,   matrix2d_,     )) \
    ((Matrix3d,   matrix3d,   matrix3d_,     )) \
    ((Matrix4d,   matrix4d,   matrix4d_,     )) \
    ((Quath,      quath,      quath_,        )) \
    ((Quatf,      quatf,      quatf_,        )) \
    ((Quatd,      quatd,      quatd_,        )) \
    ((Int2,       int2,       int2_,         )) \
    ((Half2,      half2,      half2_,        )) \
    ((Float2,     float2,     float2_,       )) \
    ((Double2,    double2,    double2_,      )) \
    ((Int3,       int3,       int3_,         )) \
    ((Half3,      half3,      half3_,        )) \
    ((Float3,     float3,     float3_,       )) \
    ((Double3,    double3,    double3_,      )) \
    ((Int4,       int4,       int4_,         )) \
    ((Half4,      half4,      half4_,        )) \
    ((Float4,     float4,     float4_,       )) \
    ((Double4,    double4,    double4_,      ))

#define ANIMX_VALUE_TYPES _ANIMX_SCALAR_VALUE_TYPES _ANIMX_DIMENSIONED_VALUE_TYPES

// Accessors for individual elements in the value types tuples.
#define ANIMX_VALUE_SDF_TYPE(tup) BOOST_PP_TUPLE_ELEM(4, 0, tup)
#define ANIMX_VALUE_SERIALIZATION_TYPE(tup) BOOST_PP_TUPLE_ELEM(4, 1, tup)
#define ANIMX_VALUE_TYPE_TOKEN(tup) BOOST_PP_TUPLE_ELEM(4, 2, tup)

#define ANIMX_VALUE_TYPE_TOKEN_DECL(r, unused, elem) \
    const TfToken ANIMX_VALUE_TYPE_TOKEN(elem);

#define ANIMX_VALUE_TYPE_ARRAY_TOKEN_DECL(r, unused, elem) \
    const TfToken BOOST_PP_CAT(ANIMX_VALUE_TYPE_TOKEN(elem), Array);

// Public value types tokens declaration
struct UsdAnimXValueTypeTokensType {
    ANIMX_API UsdAnimXValueTypeTokensType();
    BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_TOKEN_DECL, ~, ANIMX_VALUE_TYPES)
    BOOST_PP_SEQ_FOR_EACH(ANIMX_VALUE_TYPE_ARRAY_TOKEN_DECL, ~, ANIMX_VALUE_TYPES)
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};
#undef ANIMX_VALUE_TYPE_TOKEN_DECL
#undef ANIMX_VALUE_TYPE_ARRAY_TOKEN_DECL

/// \var UsdAnimXValueTypeTokens
extern ANIMX_API TfStaticData<UsdAnimXValueTypeTokensType> UsdAnimXValueTypeTokens;

ANIMX_API 
const SdfValueTypeName& 
AnimXGetSdfValueTypeNameFromToken(const TfToken& token);

ANIMX_API 
const TfToken& 
AnimXGetTokenFromSdfValueTypeName(const TfType& type);

ANIMX_API 
const TfToken& 
AnimXGetSerializationTypeNameFromToken(const TfToken& token);

ANIMX_API 
const TfToken& 
AnimXGetSerializationTypeNameFromSdfValueTypeName(const TfType& type);

PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_USD_USD_ANIMX_TYPES_H