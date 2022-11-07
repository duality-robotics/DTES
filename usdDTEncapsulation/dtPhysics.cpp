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
#include "./dtPhysics.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<DtPhysics,
        TfType::Bases< UsdTyped > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("dtPhysics")
    // to find TfType<DtPhysics>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, DtPhysics>("dtPhysics");
}

/* virtual */
DtPhysics::~DtPhysics()
{
}

/* static */
DtPhysics
DtPhysics::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return DtPhysics();
    }
    return DtPhysics(stage->GetPrimAtPath(path));
}

/* static */
DtPhysics
DtPhysics::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("dtPhysics");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return DtPhysics();
    }
    return DtPhysics(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind DtPhysics::_GetSchemaKind() const
{
    return DtPhysics::schemaKind;
}

/* static */
const TfType &
DtPhysics::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<DtPhysics>();
    return tfType;
}

/* static */
bool 
DtPhysics::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
DtPhysics::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
DtPhysics::GetDtPhysicsTypeAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtPhysicsType);
}

UsdAttribute
DtPhysics::CreateDtPhysicsTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtPhysicsType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtMassAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtMass);
}

UsdAttribute
DtPhysics::CreateDtMassAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtMass,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtDensityAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtDensity);
}

UsdAttribute
DtPhysics::CreateDtDensityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtDensity,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtCenterOfMassAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtCenterOfMass);
}

UsdAttribute
DtPhysics::CreateDtCenterOfMassAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtCenterOfMass,
                       SdfValueTypeNames->Point3d,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtRotationalInertiaAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtRotationalInertia);
}

UsdAttribute
DtPhysics::CreateDtRotationalInertiaAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtRotationalInertia,
                       SdfValueTypeNames->Double3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtStaticFrictionAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtStaticFriction);
}

UsdAttribute
DtPhysics::CreateDtStaticFrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtStaticFriction,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtDynamicfrictionAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtDynamicFriction);
}

UsdAttribute
DtPhysics::CreateDtDynamicfrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtDynamicFriction,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtPhysics::GetDtRestitutionAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtRestitution);
}

UsdAttribute
DtPhysics::CreateDtRestitutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtRestitution,
                       SdfValueTypeNames->Double,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
DtPhysics::GetDtCollisionShapesRel() const
{
    return GetPrim().GetRelationship(DtTokens->dtCollisionShape);
}

UsdRelationship
DtPhysics::CreateDtCollisionShapesRel() const
{
    return GetPrim().CreateRelationship(DtTokens->dtCollisionShape,
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
DtPhysics::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        DtTokens->dtPhysicsType,
        DtTokens->dtMass,
        DtTokens->dtDensity,
        DtTokens->dtCenterOfMass,
        DtTokens->dtRotationalInertia,
        DtTokens->dtStaticFriction,
        DtTokens->dtDynamicFriction,
        DtTokens->dtRestitution,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdTyped::GetSchemaAttributeNames(true),
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
