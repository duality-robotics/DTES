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
#ifndef DT_TOKENS_H
#define DT_TOKENS_H

/// \file usdDTEncapsulation/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include "./api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


/// \class DtTokensType
///
/// \link DtTokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// DtTokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use DtTokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(DtTokens->dtArchitectures);
/// \endcode
struct DtTokensType {
    USDDTENCAPSULATION_API DtTokensType();
    /// \brief "dtArchitectures"
    /// 
    /// DtObjectReference
    const TfToken dtArchitectures;
    /// \brief "dtAsset"
    /// 
    /// DtObjectReference
    const TfToken dtAsset;
    /// \brief "dtAxis"
    /// 
    /// DtCapsuleApproximationAPI
    const TfToken dtAxis;
    /// \brief "dtCenterOfMass"
    /// 
    /// DtPhysics
    const TfToken dtCenterOfMass;
    /// \brief "dtCollisionShape"
    /// 
    /// DtPhysics
    const TfToken dtCollisionShape;
    /// \brief "dtDensity"
    /// 
    /// DtPhysics
    const TfToken dtDensity;
    /// \brief "dtDisplayName"
    /// 
    /// DtEncapsulation
    const TfToken dtDisplayName;
    /// \brief "dtDynamicFriction"
    /// 
    /// DtPhysics
    const TfToken dtDynamicFriction;
    /// \brief "dtHeightPadding"
    /// 
    /// DtCapsuleApproximationAPI
    const TfToken dtHeightPadding;
    /// \brief "dtMass"
    /// 
    /// DtPhysics
    const TfToken dtMass;
    /// \brief "dtMaxHulls"
    /// 
    /// DtConvexHullApproximationAPI
    const TfToken dtMaxHulls;
    /// \brief "dtMaxVertices"
    /// 
    /// DtConvexHullApproximationAPI
    const TfToken dtMaxVertices;
    /// \brief "dtPadding"
    /// 
    /// DtHollowBoxApproximationAPI, DtBoxApproximationAPI, DtSphereApproximationAPI
    const TfToken dtPadding;
    /// \brief "dtPhysicsType"
    /// 
    /// DtPhysics
    const TfToken dtPhysicsType;
    /// \brief "dtPreview"
    /// 
    /// DtObjectReference
    const TfToken dtPreview;
    /// \brief "dtRadiusPadding"
    /// 
    /// DtCapsuleApproximationAPI
    const TfToken dtRadiusPadding;
    /// \brief "dtResolution"
    /// 
    /// DtConvexHullApproximationAPI
    const TfToken dtResolution;
    /// \brief "dtRestitution"
    /// 
    /// DtPhysics
    const TfToken dtRestitution;
    /// \brief "dtRotationalInertia"
    /// 
    /// DtPhysics
    const TfToken dtRotationalInertia;
    /// \brief "dtScope"
    /// 
    /// DtObjectReference
    const TfToken dtScope;
    /// \brief "dtSHA256"
    /// 
    /// DtObjectReference
    const TfToken dtSHA256;
    /// \brief "dtStaticFriction"
    /// 
    /// DtPhysics
    const TfToken dtStaticFriction;
    /// \brief "dtTwinType"
    /// 
    /// DtEncapsulation
    const TfToken dtTwinType;
    /// \brief "dtWallThickness"
    /// 
    /// DtHollowBoxApproximationAPI
    const TfToken dtWallThickness;
    /// \brief "Dynamic"
    /// 
    /// Possible value for DtPhysics::GetDtPhysicsTypeAttr()
    const TfToken dynamic;
    /// \brief "invisible"
    /// 
    /// Default value for DtCollisionShape::GetVisibilityAttr()
    const TfToken invisible;
    /// \brief "ItemTwin"
    /// 
    /// Possible value for DtEncapsulation::GetDtTwinTypeAttr()
    const TfToken itemTwin;
    /// \brief "kilogramsPerUnit"
    /// 
    /// Stage-level metadata that encodes a scene's linear unit of measure as kilograms per encoded unit.
    const TfToken kilogramsPerUnit;
    /// \brief "Kinematic"
    /// 
    /// Possible value for DtPhysics::GetDtPhysicsTypeAttr()
    const TfToken kinematic;
    /// \brief "SpaceTwin"
    /// 
    /// Possible value for DtEncapsulation::GetDtTwinTypeAttr()
    const TfToken spaceTwin;
    /// \brief "Static"
    /// 
    /// Possible value for DtPhysics::GetDtPhysicsTypeAttr()
    const TfToken static_;
    /// \brief "SystemTwin"
    /// 
    /// Possible value for DtEncapsulation::GetDtTwinTypeAttr()
    const TfToken systemTwin;
    /// \brief "visibility"
    /// 
    /// DtCollisionShape
    const TfToken visibility;
    /// \brief "X"
    /// 
    /// Possible value for DtCapsuleApproximationAPI::GetDtAxisAttr()
    const TfToken x;
    /// \brief "Y"
    /// 
    /// Possible value for DtCapsuleApproximationAPI::GetDtAxisAttr()
    const TfToken y;
    /// \brief "Z"
    /// 
    /// Possible value for DtCapsuleApproximationAPI::GetDtAxisAttr(), Default value for DtCapsuleApproximationAPI::GetDtAxisAttr()
    const TfToken z;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var DtTokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa DtTokensType
extern USDDTENCAPSULATION_API TfStaticData<DtTokensType> DtTokens;

PXR_NAMESPACE_CLOSE_SCOPE

#endif
