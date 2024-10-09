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
    colliders("colliders", TfToken::Immortal),
    constraint("constraint", TfToken::Immortal),
    constraint_MultipleApplyTemplate_PbdConstraintEnabled("constraint:__INSTANCE_NAME__:pbd:constraintEnabled", TfToken::Immortal),
    constraint_MultipleApplyTemplate_PbdDamp("constraint:__INSTANCE_NAME__:pbd:damp", TfToken::Immortal),
    constraint_MultipleApplyTemplate_PbdStiffness("constraint:__INSTANCE_NAME__:pbd:stiffness", TfToken::Immortal),
    pbdCollisionEnabled("pbd:collisionEnabled", TfToken::Immortal),
    pbdFriction("pbd:friction", TfToken::Immortal),
    pbdMargin("pbd:margin", TfToken::Immortal),
    pbdMass("pbd:mass", TfToken::Immortal),
    pbdMaxSeparationVelocity("pbd:maxSeparationVelocity", TfToken::Immortal),
    pbdRadius("pbd:radius", TfToken::Immortal),
    pbdRestitution("pbd:restitution", TfToken::Immortal),
    pbdSimulationEnabled("pbd:simulationEnabled", TfToken::Immortal),
    solverBodies("solver:bodies", TfToken::Immortal),
    solverColliders("solver:colliders", TfToken::Immortal),
    solverGravity("solver:gravity", TfToken::Immortal),
    solverIteration("solver:iteration", TfToken::Immortal),
    solverSleepThreshold("solver:sleepThreshold", TfToken::Immortal),
    solverSubSteps("solver:subSteps", TfToken::Immortal),
    PbdBodyAPI("PbdBodyAPI", TfToken::Immortal),
    PbdCollisionAPI("PbdCollisionAPI", TfToken::Immortal),
    PbdConstraintAPI("PbdConstraintAPI", TfToken::Immortal),
    PbdSolver("PbdSolver", TfToken::Immortal),
    allTokens({
        colliders,
        constraint,
        constraint_MultipleApplyTemplate_PbdConstraintEnabled,
        constraint_MultipleApplyTemplate_PbdDamp,
        constraint_MultipleApplyTemplate_PbdStiffness,
        pbdCollisionEnabled,
        pbdFriction,
        pbdMargin,
        pbdMass,
        pbdMaxSeparationVelocity,
        pbdRadius,
        pbdRestitution,
        pbdSimulationEnabled,
        solverBodies,
        solverColliders,
        solverGravity,
        solverIteration,
        solverSleepThreshold,
        solverSubSteps,
        PbdBodyAPI,
        PbdCollisionAPI,
        PbdConstraintAPI,
        PbdSolver
    })
{
}

TfStaticData<UsdPbdTokensType> UsdPbdTokens;

PXR_NAMESPACE_CLOSE_SCOPE
