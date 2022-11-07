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
#include "./dtConvexHullApproximationAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"
#include "pxr/usd/usd/tokens.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<DtConvexHullApproximationAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

TF_DEFINE_PRIVATE_TOKENS(
    _schemaTokens,
    (dtConvexHullApproximationAPI)
);

/* virtual */
DtConvexHullApproximationAPI::~DtConvexHullApproximationAPI()
{
}

/* static */
DtConvexHullApproximationAPI
DtConvexHullApproximationAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return DtConvexHullApproximationAPI();
    }
    return DtConvexHullApproximationAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind DtConvexHullApproximationAPI::_GetSchemaKind() const
{
    return DtConvexHullApproximationAPI::schemaKind;
}

/* static */
bool
DtConvexHullApproximationAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<DtConvexHullApproximationAPI>(whyNot);
}

/* static */
DtConvexHullApproximationAPI
DtConvexHullApproximationAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<DtConvexHullApproximationAPI>()) {
        return DtConvexHullApproximationAPI(prim);
    }
    return DtConvexHullApproximationAPI();
}

/* static */
const TfType &
DtConvexHullApproximationAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<DtConvexHullApproximationAPI>();
    return tfType;
}

/* static */
bool 
DtConvexHullApproximationAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
DtConvexHullApproximationAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
DtConvexHullApproximationAPI::GetDtResolutionAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtResolution);
}

UsdAttribute
DtConvexHullApproximationAPI::CreateDtResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtResolution,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtConvexHullApproximationAPI::GetDtMaxVerticesAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtMaxVertices);
}

UsdAttribute
DtConvexHullApproximationAPI::CreateDtMaxVerticesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtMaxVertices,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
DtConvexHullApproximationAPI::GetDtMaxHullsAttr() const
{
    return GetPrim().GetAttribute(DtTokens->dtMaxHulls);
}

UsdAttribute
DtConvexHullApproximationAPI::CreateDtMaxHullsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(DtTokens->dtMaxHulls,
                       SdfValueTypeNames->Int,
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
DtConvexHullApproximationAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        DtTokens->dtResolution,
        DtTokens->dtMaxVertices,
        DtTokens->dtMaxHulls,
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
