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
#include "./dtObjectReference.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<DtObjectReference,
        TfType::Bases< UsdGeomImageable > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("dtObjectReference")
    // to find TfType<DtObjectReference>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, DtObjectReference>("dtObjectReference");
}

/* virtual */
DtObjectReference::~DtObjectReference()
{
}

/* static */
DtObjectReference
DtObjectReference::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return DtObjectReference();
    }
    return DtObjectReference(stage->GetPrimAtPath(path));
}

/* static */
DtObjectReference
DtObjectReference::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("dtObjectReference");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return DtObjectReference();
    }
    return DtObjectReference(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind DtObjectReference::_GetSchemaKind() const
{
    return DtObjectReference::schemaKind;
}

/* static */
const TfType &
DtObjectReference::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<DtObjectReference>();
    return tfType;
}

/* static */
bool 
DtObjectReference::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
DtObjectReference::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
DtObjectReference::GetDtAssetAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtAsset);
}

UsdAttribute
DtObjectReference::CreateDtAssetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtAsset,
                       SdfValueTypeNames->Asset,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtObjectReference::GetDtScopeAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtScope);
}

UsdAttribute
DtObjectReference::CreateDtScopeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtScope,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtObjectReference::GetDtPreviewAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtPreview);
}

UsdAttribute
DtObjectReference::CreateDtPreviewAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtPreview,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtObjectReference::GetDtSHA256Attr() const
{
    return GetPrim().GetAttribute(DtTokens->dtSHA256);
}

UsdAttribute
DtObjectReference::CreateDtSHA256Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtSHA256,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtObjectReference::GetDtArchitecturesAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtArchitectures);
}

UsdAttribute
DtObjectReference::CreateDtArchitecturesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtArchitectures,
                       SdfValueTypeNames->StringArray,
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
DtObjectReference::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        DtTokens->dtAsset,
        DtTokens->dtScope,
        DtTokens->dtPreview,
        DtTokens->dtSHA256,
        DtTokens->dtArchitectures,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomImageable::GetSchemaAttributeNames(true),
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
