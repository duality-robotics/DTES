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
#ifndef USDDTENCAPSULATION_GENERATED_DTPHYSICS_H
#define USDDTENCAPSULATION_GENERATED_DTPHYSICS_H

/// \file usdDTEncapsulation/dtPhysics.h

#include "pxr/pxr.h"
#include "./api.h"
#include "pxr/usd/usd/typed.h"
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
// DTPHYSICS                                                                  //
// -------------------------------------------------------------------------- //

/// \class DtPhysics
///
/// This is the scope for physics-related properties of a specific object.
/// Can only be contained within a dtScope or a dtObjectReference.
/// When contained within a dtObjectReference, the physics definition is applied to
/// the object referenced by the dtScope property.
/// When contained within a dtScope, the physics definition is applied to the object
/// referenced by the name of the dtScope.
/// 
/// If the object to which the physics definition is applied is not a leaf in the hierarchy,
/// the physics definition is applied to the object and all of its descendants.
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref DtTokens.
/// So to set an attribute to the value "rightHanded", use DtTokens->rightHanded
/// as the value.
///
class DtPhysics : public UsdTyped
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a DtPhysics on UsdPrim \p prim .
    /// Equivalent to DtPhysics::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit DtPhysics(const UsdPrim& prim=UsdPrim())
        : UsdTyped(prim)
    {
    }

    /// Construct a DtPhysics on the prim held by \p schemaObj .
    /// Should be preferred over DtPhysics(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit DtPhysics(const UsdSchemaBase& schemaObj)
        : UsdTyped(schemaObj)
    {
    }

    /// Destructor.
    USDDTENCAPSULATION_API
    virtual ~DtPhysics();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDDTENCAPSULATION_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a DtPhysics holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// DtPhysics(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDDTENCAPSULATION_API
    static DtPhysics
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
    static DtPhysics
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
    // DTPHYSICSTYPE 
    // --------------------------------------------------------------------- //
    /// The type of physics to apply to the object.
    /// Static: The object is static and does not move.
    /// Dynamic: The object is dynamic and moves according to the physics simulation.
    /// Kinematic: The object will not be affected by physics, but it can move.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `token dtPhysicsType` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref DtTokens "Allowed Values" | Static, Dynamic, Kinematic |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtPhysicsTypeAttr() const;

    /// See GetDtPhysicsTypeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtPhysicsTypeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTMASS 
    // --------------------------------------------------------------------- //
    /// If non-zero, directly specifies the mass of the object.
    /// Note that any child prim can also have a mass when they apply massAPI.
    /// In this case, the precedence rule is 'parent mass overrides the
    /// child's'. This may come as counter-intuitive, but mass is a computed
    /// quantity and in general not accumulative. For example, if a parent
    /// has mass of 10, and one of two children has mass of 20, allowing
    /// child's mass to override its parent results in a mass of -10 for the
    /// other child. Note if mass is 0.0 it is ignored.
    /// Ignored for Kinematic and Static objects.
    /// Units: mass.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double dtMass = 0` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtMassAttr() const;

    /// See GetDtMassAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtMassAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTDENSITY 
    // --------------------------------------------------------------------- //
    /// If non-zero, specifies the density of the object.
    /// In the context of rigid body physics, density indirectly results in
    /// setting mass via (mass = density x volume of the object). How the
    /// volume is computed is up to implementation of the physics system.
    /// It is generally computed from the collision approximation rather than
    /// the graphical mesh. In the case where both density and mass are
    /// specified for the same object, mass has precedence over density.
    /// Unlike mass, child's prim's density overrides parent prim's density
    /// as it is accumulative. Note if density is 0.0 it is ignored.
    /// Ignored for Kinematic and Static objects.
    /// Units: mass/distance/distance/distance.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double dtDensity = 0` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtDensityAttr() const;

    /// See GetDtDensityAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtDensityAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTCENTEROFMASS 
    // --------------------------------------------------------------------- //
    /// Center of mass in the prim's local space.
    /// Ignored for Kinematic and Static Twins.
    /// Units: distance.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `point3d dtCenterOfMass = (0, 0, 0)` |
    /// | C++ Type | GfVec3d |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Point3d |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtCenterOfMassAttr() const;

    /// See GetDtCenterOfMassAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtCenterOfMassAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTROTATIONALINERTIA 
    // --------------------------------------------------------------------- //
    /// If non-zero, specifies rotational inertia tensor along the
    /// principal axes. Note if diagonalInertial is (0.0, 0.0, 0.0) it is
    /// ignored. Ignored for Kinematic and Static objects.
    /// Units: mass*distance*distance.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double3 dtRotationalInertia = (0, 0, 0)` |
    /// | C++ Type | GfVec3d |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double3 |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtRotationalInertiaAttr() const;

    /// See GetDtRotationalInertiaAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtRotationalInertiaAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTSTATICFRICTION 
    // --------------------------------------------------------------------- //
    /// Static Friction coefficient. Unitless.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double dtStaticFriction = 0` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtStaticFrictionAttr() const;

    /// See GetDtStaticFrictionAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtStaticFrictionAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTDYNAMICFRICTION 
    // --------------------------------------------------------------------- //
    /// Dynamic Friction coefficient. Unitless.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double dtDynamicFriction = 0` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtDynamicfrictionAttr() const;

    /// See GetDtDynamicfrictionAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtDynamicfrictionAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTRESTITUTION 
    // --------------------------------------------------------------------- //
    /// Restitution coefficient. Unitless.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `double dtRestitution = 0` |
    /// | C++ Type | double |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Double |
    USDDTENCAPSULATION_API
    UsdAttribute GetDtRestitutionAttr() const;

    /// See GetDtRestitutionAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDDTENCAPSULATION_API
    UsdAttribute CreateDtRestitutionAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DTCOLLISIONSHAPES 
    // --------------------------------------------------------------------- //
    /// 
    /// A relationship to a dtCollisionShape scope that defines the collision
    /// bounds for this object.
    /// 
    ///
    USDDTENCAPSULATION_API
    UsdRelationship GetDtCollisionShapesRel() const;

    /// See GetDtCollisionShapesRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDDTENCAPSULATION_API
    UsdRelationship CreateDtCollisionShapesRel() const;

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
