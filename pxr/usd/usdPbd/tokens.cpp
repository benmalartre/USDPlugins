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
#include "pxr/usd/usdPbd/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPbdTokensType::UsdPbdTokensType() :
    bodies("bodies", TfToken::Immortal),
    colliders("colliders", TfToken::Immortal),
    collisionEnabled("collisionEnabled", TfToken::Immortal),
    damp("damp", TfToken::Immortal),
    friction("friction", TfToken::Immortal),
    gravity("gravity", TfToken::Immortal),
    iteration("iteration", TfToken::Immortal),
    margin("margin", TfToken::Immortal),
    mass("mass", TfToken::Immortal),
    maxSeparationVelocity("maxSeparationVelocity", TfToken::Immortal),
    pbd("pbd", TfToken::Immortal),
    pbd_MultipleApplyTemplate_ConstraintEnabled("pbd:__INSTANCE_NAME__:constraintEnabled", TfToken::Immortal),
    pbd_MultipleApplyTemplate_Damp("pbd:__INSTANCE_NAME__:damp", TfToken::Immortal),
    pbd_MultipleApplyTemplate_Stiffness("pbd:__INSTANCE_NAME__:stiffness", TfToken::Immortal),
    radius("radius", TfToken::Immortal),
    restitution("restitution", TfToken::Immortal),
    simulationEnabled("simulationEnabled", TfToken::Immortal),
    sleepThreshold("sleepThreshold", TfToken::Immortal),
    startFrame("startFrame", TfToken::Immortal),
    subSteps("subSteps", TfToken::Immortal),
    velocity("velocity", TfToken::Immortal),
    PbdBodyAPI("PbdBodyAPI", TfToken::Immortal),
    PbdCollisionAPI("PbdCollisionAPI", TfToken::Immortal),
    PbdConstraintAPI("PbdConstraintAPI", TfToken::Immortal),
    PbdSolver("PbdSolver", TfToken::Immortal),
    allTokens({
        bodies,
        colliders,
        collisionEnabled,
        damp,
        friction,
        gravity,
        iteration,
        margin,
        mass,
        maxSeparationVelocity,
        pbd,
        pbd_MultipleApplyTemplate_ConstraintEnabled,
        pbd_MultipleApplyTemplate_Damp,
        pbd_MultipleApplyTemplate_Stiffness,
        radius,
        restitution,
        simulationEnabled,
        sleepThreshold,
        startFrame,
        subSteps,
        velocity,
        PbdBodyAPI,
        PbdCollisionAPI,
        PbdConstraintAPI,
        PbdSolver
    })
{
}

TfStaticData<UsdPbdTokensType> UsdPbdTokens;

PXR_NAMESPACE_CLOSE_SCOPE
