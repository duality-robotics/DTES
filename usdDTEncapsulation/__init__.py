# from .@USDPLUGIN_PYTHON_NAME@ import *
from pxr import Tf, UsdGeom

Tf.PreparePythonModule()
del Tf, UsdGeom
