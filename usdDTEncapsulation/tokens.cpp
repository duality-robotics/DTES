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
#include "./tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

DtTokensType::DtTokensType() :
    dtArchitectures("dtArchitectures", TfToken::Immortal),
    dtAsset("dtAsset", TfToken::Immortal),
    dtAxis("dtAxis", TfToken::Immortal),
    dtCenterOfMass("dtCenterOfMass", TfToken::Immortal),
    dtCollisionShape("dtCollisionShape", TfToken::Immortal),
    dtDensity("dtDensity", TfToken::Immortal),
    dtDisplayName("dtDisplayName", TfToken::Immortal),
    dtDynamicFriction("dtDynamicFriction", TfToken::Immortal),
    dtHeightPadding("dtHeightPadding", TfToken::Immortal),
    dtMass("dtMass", TfToken::Immortal),
    dtMaxHulls("dtMaxHulls", TfToken::Immortal),
    dtMaxVertices("dtMaxVertices", TfToken::Immortal),
    dtPadding("dtPadding", TfToken::Immortal),
    dtPhysicsType("dtPhysicsType", TfToken::Immortal),
    dtPreview("dtPreview", TfToken::Immortal),
    dtRadiusPadding("dtRadiusPadding", TfToken::Immortal),
    dtResolution("dtResolution", TfToken::Immortal),
    dtRestitution("dtRestitution", TfToken::Immortal),
    dtRotationalInertia("dtRotationalInertia", TfToken::Immortal),
    dtScope("dtScope", TfToken::Immortal),
    dtSHA256("dtSHA256", TfToken::Immortal),
    dtStaticFriction("dtStaticFriction", TfToken::Immortal),
    dtTwinType("dtTwinType", TfToken::Immortal),
    dtWallThickness("dtWallThickness", TfToken::Immortal),
    dynamic("Dynamic", TfToken::Immortal),
    invisible("invisible", TfToken::Immortal),
    itemTwin("ItemTwin", TfToken::Immortal),
    kilogramsPerUnit("kilogramsPerUnit", TfToken::Immortal),
    kinematic("Kinematic", TfToken::Immortal),
    spaceTwin("SpaceTwin", TfToken::Immortal),
    static_("Static", TfToken::Immortal),
    systemTwin("SystemTwin", TfToken::Immortal),
    visibility("visibility", TfToken::Immortal),
    x("X", TfToken::Immortal),
    y("Y", TfToken::Immortal),
    z("Z", TfToken::Immortal),
    allTokens({
        dtArchitectures,
        dtAsset,
        dtAxis,
        dtCenterOfMass,
        dtCollisionShape,
        dtDensity,
        dtDisplayName,
        dtDynamicFriction,
        dtHeightPadding,
        dtMass,
        dtMaxHulls,
        dtMaxVertices,
        dtPadding,
        dtPhysicsType,
        dtPreview,
        dtRadiusPadding,
        dtResolution,
        dtRestitution,
        dtRotationalInertia,
        dtScope,
        dtSHA256,
        dtStaticFriction,
        dtTwinType,
        dtWallThickness,
        dynamic,
        invisible,
        itemTwin,
        kilogramsPerUnit,
        kinematic,
        spaceTwin,
        static_,
        systemTwin,
        visibility,
        x,
        y,
        z
    })
{
}

TfStaticData<DtTokensType> DtTokens;

PXR_NAMESPACE_CLOSE_SCOPE
