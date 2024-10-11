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
#include "pxr/usd/usdPbd/solver.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPbdSolver,
        TfType::Bases< UsdGeomXform > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PbdSolver")
    // to find TfType<UsdPbdSolver>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPbdSolver>("PbdSolver");
}

/* virtual */
UsdPbdSolver::~UsdPbdSolver()
{
}

/* static */
UsdPbdSolver
UsdPbdSolver::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPbdSolver();
    }
    return UsdPbdSolver(stage->GetPrimAtPath(path));
}

/* static */
UsdPbdSolver
UsdPbdSolver::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PbdSolver");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPbdSolver();
    }
    return UsdPbdSolver(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPbdSolver::_GetSchemaKind() const
{
    return UsdPbdSolver::schemaKind;
}

/* static */
const TfType &
UsdPbdSolver::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPbdSolver>();
    return tfType;
}

/* static */
bool 
UsdPbdSolver::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPbdSolver::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPbdSolver::GetStartFrameAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->startFrame);
}

UsdAttribute
UsdPbdSolver::CreateStartFrameAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->startFrame,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdSolver::GetSleepThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->sleepThreshold);
}

UsdAttribute
UsdPbdSolver::CreateSleepThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->sleepThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdSolver::GetSubStepsAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->subSteps);
}

UsdAttribute
UsdPbdSolver::CreateSubStepsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->subSteps,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdSolver::GetIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->iteration);
}

UsdAttribute
UsdPbdSolver::CreateIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->iteration,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPbdSolver::GetGravityAttr() const
{
    return GetPrim().GetAttribute(UsdPbdTokens->gravity);
}

UsdAttribute
UsdPbdSolver::CreateGravityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPbdTokens->gravity,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
UsdPbdSolver::GetBodiesRel() const
{
    return GetPrim().GetRelationship(UsdPbdTokens->bodies);
}

UsdRelationship
UsdPbdSolver::CreateBodiesRel() const
{
    return GetPrim().CreateRelationship(UsdPbdTokens->bodies,
                       /* custom = */ false);
}

UsdRelationship
UsdPbdSolver::GetCollidersRel() const
{
    return GetPrim().GetRelationship(UsdPbdTokens->colliders);
}

UsdRelationship
UsdPbdSolver::CreateCollidersRel() const
{
    return GetPrim().CreateRelationship(UsdPbdTokens->colliders,
                       /* custom = */ false);
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
UsdPbdSolver::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPbdTokens->startFrame,
        UsdPbdTokens->sleepThreshold,
        UsdPbdTokens->subSteps,
        UsdPbdTokens->iteration,
        UsdPbdTokens->gravity,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomXform::GetSchemaAttributeNames(true),
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
