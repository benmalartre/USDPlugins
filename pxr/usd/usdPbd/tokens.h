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
#ifndef USDPBD_TOKENS_H
#define USDPBD_TOKENS_H

/// \file UsdPbd/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include "pxr/usd/usdPbd/api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


/// \class UsdPbdTokensType
///
/// \link UsdPbdTokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// UsdPbdTokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use UsdPbdTokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(UsdPbdTokens->bodies);
/// \endcode
struct UsdPbdTokensType {
    USDPBD_API UsdPbdTokensType();
    /// \brief "bodies"
    /// 
    /// UsdPbdSolver
    const TfToken bodies;
    /// \brief "colliders"
    /// 
    /// UsdPbdSolver,  This token represents the collection name to use with UsdCollectionAPI to represent collision objects for the solver 
    const TfToken colliders;
    /// \brief "collisionEnabled"
    /// 
    /// UsdPbdCollisionAPI
    const TfToken collisionEnabled;
    /// \brief "damp"
    /// 
    /// UsdPbdBodyAPI
    const TfToken damp;
    /// \brief "friction"
    /// 
    /// UsdPbdCollisionAPI
    const TfToken friction;
    /// \brief "gravity"
    /// 
    /// UsdPbdSolver
    const TfToken gravity;
    /// \brief "iteration"
    /// 
    /// UsdPbdSolver
    const TfToken iteration;
    /// \brief "margin"
    /// 
    /// UsdPbdCollisionAPI
    const TfToken margin;
    /// \brief "mass"
    /// 
    /// UsdPbdBodyAPI
    const TfToken mass;
    /// \brief "maxSeparationVelocity"
    /// 
    /// UsdPbdCollisionAPI
    const TfToken maxSeparationVelocity;
    /// \brief "pbd"
    /// 
    /// Property namespace prefix for the UsdPbdConstraintAPI schema.
    const TfToken pbd;
    /// \brief "pbd:__INSTANCE_NAME__:constraintEnabled"
    /// 
    /// UsdPbdConstraintAPI
    const TfToken pbd_MultipleApplyTemplate_ConstraintEnabled;
    /// \brief "pbd:__INSTANCE_NAME__:damp"
    /// 
    /// UsdPbdConstraintAPI
    const TfToken pbd_MultipleApplyTemplate_Damp;
    /// \brief "pbd:__INSTANCE_NAME__:stiffness"
    /// 
    /// UsdPbdConstraintAPI
    const TfToken pbd_MultipleApplyTemplate_Stiffness;
    /// \brief "radius"
    /// 
    /// UsdPbdBodyAPI
    const TfToken radius;
    /// \brief "restitution"
    /// 
    /// UsdPbdCollisionAPI
    const TfToken restitution;
    /// \brief "simulationEnabled"
    /// 
    /// UsdPbdBodyAPI
    const TfToken simulationEnabled;
    /// \brief "sleepThreshold"
    /// 
    /// UsdPbdSolver
    const TfToken sleepThreshold;
    /// \brief "startFrame"
    /// 
    /// UsdPbdSolver
    const TfToken startFrame;
    /// \brief "subSteps"
    /// 
    /// UsdPbdSolver
    const TfToken subSteps;
    /// \brief "velocity"
    /// 
    /// UsdPbdBodyAPI
    const TfToken velocity;
    /// \brief "PbdBodyAPI"
    /// 
    /// Schema identifer and family for UsdPbdBodyAPI
    const TfToken PbdBodyAPI;
    /// \brief "PbdCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPbdCollisionAPI
    const TfToken PbdCollisionAPI;
    /// \brief "PbdConstraintAPI"
    /// 
    /// Schema identifer and family for UsdPbdConstraintAPI
    const TfToken PbdConstraintAPI;
    /// \brief "PbdSolver"
    /// 
    /// Schema identifer and family for UsdPbdSolver
    const TfToken PbdSolver;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var UsdPbdTokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa UsdPbdTokensType
extern USDPBD_API TfStaticData<UsdPbdTokensType> UsdPbdTokens;

PXR_NAMESPACE_CLOSE_SCOPE

#endif
