#include "boost/python.hpp"
#include "pxr/pxr.h"
#include "pxr/base/tf/pyModule.h"

PXR_NAMESPACE_USING_DIRECTIVE

TF_WRAP_MODULE
{
	TF_WRAP(DtTokens);

    // Base classes
	TF_WRAP(DtEncapsulation);
	TF_WRAP(DtObjectReference);
    TF_WRAP(DtScope);

    // Physics
    TF_WRAP(DtPhysics);

    TF_WRAP(DtCollisionShape);
    TF_WRAP(DtSphereApproximationAPI);
    TF_WRAP(DtBoxApproximationAPI);
    TF_WRAP(DtHollowBoxApproximationAPI);
    TF_WRAP(DtCapsuleApproximationAPI);
    TF_WRAP(DtConvexHullApproximationAPI);
}
