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
#ifndef USDDTENCAPSULATION_GENERATED_DTOBJECTREFERENCE_H
#define USDDTENCAPSULATION_GENERATED_DTOBJECTREFERENCE_H

/// \file usdDTEncapsulation/dtObjectReference.h

#include "pxr/pxr.h"
#include "./api.h"
#include "pxr/usd/usdGeom/imageable.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "./tokens.h"

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
// DTOBJECTREFERENCE                                                          //
// -------------------------------------------------------------------------- //

/// \class DtObjectReference
///
/// A reference to an asset file.
///
class DtObjectReference : public UsdGeomImageable
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a DtObjectReference on UsdPrim \p prim .
    /// Equivalent to DtObjectReference::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit DtObjectReference(const UsdPrim& prim=UsdPrim())
        : UsdGeomImageable(prim)
    {
    }

    /// Construct a DtObjectReference on the prim held by \p schemaObj .
    /// Should be preferred over DtObjectReference(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit DtObjectReference(const UsdSchemaBase& schemaObj)
        : UsdGeomImageable(schemaObj)
    {
    }

    /// Destructor.
    USDDTENCAPSULATION_API
    virtual ~DtObjectReference();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDDTENCAPSULATION_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a DtObjectReference holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// DtObjectReference(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDDTENCAPSULATION_API
    static DtObjectReference
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Attempt to ensure a \a UsdPrim adhering to this schema at \p path
    /// is defined (according to UsdPrim::IsDefined()) on this stage.
    ///
    /// If a prim adhering to this schema at \p path is already defined on this
    /// stage, return that prim.  Otherwise author an \a SdfPrimSpec with
    /// \a specifier == \a SdfSpecifierDef and this schema's prim type name for
    /// the prim at \p path at the current EditTarget.  Author \a SdfPrimSpec s
    /// with \p specifier == \a SdfSpecifierDef and empty typeName at the
    /// current EditTarget for any nonexistent, or existing but not \a Defined
    /// ancestors.
    ///
    /// The given \a path must be an absolute prim path that does not contain
    /// any variant selections.
    ///
    /// If it is impossible to author any of the necessary PrimSpecs, (for
    /// example, in case \a path cannot map to the current UsdEditTarget's
    /// namespace) issue an error and return an invalid \a UsdPrim.
    ///
    /// Note that this method may return a defined prim whose typeName does not
    /// specify this schema class, in case a stronger typeName opinion overrides
    /// the opinion at the current EditTarget.
    ///
    USDDTENCAPSULATION_API
    static DtObjectReference
    Define(const UsdStagePtr &stage, const SdfPath &path);

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    USDDTENCAPSULATION_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    USDDTENCAPSULATION_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    USDDTENCAPSULATION_API
    const TfType &_GetTfType() const override;

public:
    // --------------------------------------------------------------------- //
    // DTASSET 
    // --------------------------------------------------------------------- //
    /// The path to the asset that contains, at least, the appearance of the object.
    /// It can also contain physics properties (e.g. UAssets and USD Physics Schema)
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `asset dtAsset` |
    /// | C++ Type | SdfAssetPath |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Asset |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtAssetAttr() const;

    /// See GetDtAssetAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtAssetAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTSCOPE 
    // --------------------------------------------------------------------- //
    /// The scope in the hierarchy of the asset. Defaults to the root.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string dtScope = "/"` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtScopeAttr() const;

    /// See GetDtScopeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtScopeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTPREVIEW 
    // --------------------------------------------------------------------- //
    /// The path or URL to the preview of the asset. e.g a thumbnail. Optional
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string dtPreview = ""` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtPreviewAttr() const;

    /// See GetDtPreviewAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtPreviewAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTSHA256 
    // --------------------------------------------------------------------- //
    /// The SHA256 hash of the asset. Optional
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string dtSHA256 = ""` |
    /// | C++ Type | std::string |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->String |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtSHA256Attr() const;

    /// See GetDtSHA256Attr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtSHA256Attr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTARCHITECTURES 
    // --------------------------------------------------------------------- //
    /// The architectures that the asset is compatible with. e.g. [win-ue5.0, linux-ue5.1]
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `string[] dtArchitectures = ["default"]` |
    /// | C++ Type | VtArray<std::string> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->StringArray |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtArchitecturesAttr() const;

    /// See GetDtArchitecturesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtArchitecturesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
