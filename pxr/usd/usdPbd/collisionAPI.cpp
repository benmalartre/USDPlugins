//
// Copyright 2016 Pixar
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
#include "pxr/usd/usdPbd/collisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPbdCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPbdCollisionAPI::~UsdPbdCollisionAPI()
{
}

/* static */
UsdPbdCollisionAPI
UsdPbdCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPbdCollisionAPI();
    }
    return UsdPbdCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPbdCollisionAPI::_GetSchemaKind() const
{
    return UsdPbdCollisionAPI::schemaKind;
}

/* static */
bool
UsdPbdCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPbdCollisionAPI>(whyNot);
}

/* static */
UsdPbdCollisionAPI
UsdPbdCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPbdCollisionAPI>()) {
        return UsdPbdCollisionAPI(prim);
    }
    return UsdPbdCollisionAPI();
}

/* static */
const TfType &
UsdPbdCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPbdCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPbdCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPbdCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPbdCollisionAPI::GetCollisionEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->collisionEnabled);
}

UsdAttribute
UsdPbdCollisionAPI::CreateCollisionEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->collisionEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdCollisionAPI::GetMarginAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->margin);
}

UsdAttribute
UsdPbdCollisionAPI::CreateMarginAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->margin,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdCollisionAPI::GetFrictionAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->friction);
}

UsdAttribute
UsdPbdCollisionAPI::CreateFrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->friction,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdCollisionAPI::GetRestitutionAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->restitution);
}

UsdAttribute
UsdPbdCollisionAPI::CreateRestitutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->restitution,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdCollisionAPI::GetMaxSeparationVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->maxSeparationVelocity);
}

UsdAttribute
UsdPbdCollisionAPI::CreateMaxSeparationVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->maxSeparationVelocity,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
UsdPbdCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPbdTokens->collisionEnabled,
        UsdPbdTokens->margin,
        UsdPbdTokens->friction,
        UsdPbdTokens->restitution,
        UsdPbdTokens->maxSeparationVelocity,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdAPISchemaBase::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
