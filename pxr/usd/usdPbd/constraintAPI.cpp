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
#include "pxr/usd/usdPbd/constraintAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

#include "pxr/base/tf/staticTokens.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPbdConstraintAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

TF_DEFINE_PRIVATE_TOKENS(
    _schemaTokens,
    (constraint)
);

/* virtual */
UsdPbdConstraintAPI::~UsdPbdConstraintAPI()
{
}

/* static */
UsdPbdConstraintAPI
UsdPbdConstraintAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPbdConstraintAPI();
    }
    TfToken name;
    if (!IsPbdConstraintAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid constraint path <%s>.", path.GetText());
        return UsdPbdConstraintAPI();
    }
    return UsdPbdConstraintAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPbdConstraintAPI
UsdPbdConstraintAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPbdConstraintAPI(prim, name);
}

/* static */
std::vector<UsdPbdConstraintAPI>
UsdPbdConstraintAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPbdConstraintAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPbdConstraintAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdConstraintEnabled),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdStiffness),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdDamp),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPbdConstraintAPI::IsPbdConstraintAPIPath(
    const SdfPath &path, TfToken *name)
{
    if (!path.IsPropertyPath()) {
        return false;
    }

    std::string propertyName = path.GetName();
    TfTokenVector tokens = SdfPath::TokenizeIdentifierAsTokens(propertyName);

    // The baseName of the  path can't be one of the 
    // schema properties. We should validate this in the creation (or apply)
    // API.
    TfToken baseName = *tokens.rbegin();
    if (IsSchemaPropertyBaseName(baseName)) {
        return false;
    }

    if (tokens.size() >= 2
        && tokens[0] == _schemaTokens->constraint) {
        *name = TfToken(propertyName.substr(
            _schemaTokens->constraint.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPbdConstraintAPI::_GetSchemaKind() const
{
    return UsdPbdConstraintAPI::schemaKind;
}

/* static */
bool
UsdPbdConstraintAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPbdConstraintAPI>(name, whyNot);
}

/* static */
UsdPbdConstraintAPI
UsdPbdConstraintAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPbdConstraintAPI>(name)) {
        return UsdPbdConstraintAPI(prim, name);
    }
    return UsdPbdConstraintAPI();
}

/* static */
const TfType &
UsdPbdConstraintAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPbdConstraintAPI>();
    return tfType;
}

/* static */
bool 
UsdPbdConstraintAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPbdConstraintAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/// Returns the property name prefixed with the correct namespace prefix, which
/// is composed of the the API's propertyNamespacePrefix metadata and the
/// instance name of the API.
static inline
TfToken
_GetNamespacedPropertyName(const TfToken instanceName, const TfToken propName)
{
    return UsdSchemaRegistry::MakeMultipleApplyNameInstance(propName, instanceName);
}

UsdAttribute
UsdPbdConstraintAPI::GetPbdConstraintEnabledAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdConstraintEnabled));
}

UsdAttribute
UsdPbdConstraintAPI::CreatePbdConstraintEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPbdTokens->constraint_MultipleApplyTemplate_PbdConstraintEnabled),
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdConstraintAPI::GetStiffnessAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdStiffness));
}

UsdAttribute
UsdPbdConstraintAPI::CreateStiffnessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPbdTokens->constraint_MultipleApplyTemplate_PbdStiffness),
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdConstraintAPI::GetDampAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPbdTokens->constraint_MultipleApplyTemplate_PbdDamp));
}

UsdAttribute
UsdPbdConstraintAPI::CreateDampAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPbdTokens->constraint_MultipleApplyTemplate_PbdDamp),
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
UsdPbdConstraintAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPbdTokens->constraint_MultipleApplyTemplate_PbdConstraintEnabled,
        UsdPbdTokens->constraint_MultipleApplyTemplate_PbdStiffness,
        UsdPbdTokens->constraint_MultipleApplyTemplate_PbdDamp,
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

/*static*/
TfTokenVector
UsdPbdConstraintAPI::GetSchemaAttributeNames(
    bool includeInherited, const TfToken &instanceName)
{
    const TfTokenVector &attrNames = GetSchemaAttributeNames(includeInherited);
    if (instanceName.IsEmpty()) {
        return attrNames;
    }
    TfTokenVector result;
    result.reserve(attrNames.size());
    for (const TfToken &attrName : attrNames) {
        result.push_back(
            UsdSchemaRegistry::MakeMultipleApplyNameInstance(attrName, instanceName));
    }
    return result;
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
