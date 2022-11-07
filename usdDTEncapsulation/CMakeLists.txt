include(pxrConfig)

# Headers and sources
set(PLUGIN_HEADERS
    api.h
    tokens.h
    dtEncapsulation.h
    dtObjectreference.h
    dtScope.h
    dtPhysics.h
    dtCollisionShape.h
    dtSphereApproximationAPI.h
    dtBoxApproximationAPI.h
    dtHollowBoxApproximationAPI.h
    dtCapsuleApproximationAPI.h
    dtConvexHullApproximationAPI.h
)

set(PLUGIN_SOURCES
    tokens.cpp
    dtEncapsulation.cpp
    dtObjectreference.cpp
    dtScope.cpp
    dtPhysics.cpp
    dtCollisionShape.cpp
    dtSphereApproximationAPI.cpp
    dtBoxApproximationAPI.cpp
    dtHollowBoxApproximationAPI.cpp
    dtCapsuleApproximationAPI.cpp
    dtConvexHullApproximationAPI.cpp
)

# Library target
add_library(${USDPLUGIN_NAME} SHARED ${PLUGIN_HEADERS} ${PLUGIN_SOURCES})

# USD directories
set(USD_INCLUDE_DIRECTORY ${USD_BUILD_ROOT}/include)
set(USD_LIB_DIR ${USD_BUILD_ROOT}/lib)

# Include directories
target_include_directories(${USDPLUGIN_NAME} PRIVATE ${USD_INCLUDE_DIRECTORY})

# Link directories
target_link_directories(${USDPLUGIN_NAME} PRIVATE ${USD_LIB_DIR})

# Link libraries
target_link_libraries(${USDPLUGIN_NAME}
	PUBLIC
	tf
	sdf
	usd
    usdGeom
)

# Compile options
target_compile_options(${USDPLUGIN_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/wd4273 /Zi>
        $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:RelWithDebInfo>>:/Ob0 /Od>
)

# Link options
target_link_options(${USDPLUGIN_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/ignore:4217 /ignore:4049>
)


set_target_properties(${USDPLUGIN_NAME} PROPERTIES PREFIX "")

install(TARGETS ${USDPLUGIN_NAME} DESTINATION .)
if (MSVC)
    install(FILES $<TARGET_PDB_FILE:${USDPLUGIN_NAME}> DESTINATION . OPTIONAL)
endif()


install(FILES ${PLUGIN_HEADERS}
    DESTINATION include/${USDPLUGIN_NAME}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/plugInfo.root.json
    DESTINATION usd/ RENAME plugInfo.json
)


# variables that will replace in plugInfo.json
set(PLUG_INFO_LIBRARY_PATH "../../${CMAKE_SHARED_LIBRARY_PREFIX}${USDPLUGIN_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}")
set(PLUG_INFO_RESOURCE_PATH "resources")
set(PLUG_INFO_ROOT "..")
# simply copy plugInfo.json file to cmake_dir/bin dir
# @ONLY prevents the variables swap in the file with ${} syntax
configure_file(plugInfo.json ${CMAKE_BINARY_DIR}/plugInfo.json @ONLY)

install(FILES
    ${CMAKE_BINARY_DIR}/plugInfo.json
    ${CMAKE_CURRENT_SOURCE_DIR}/generatedSchema.usda
    DESTINATION usd/${USDPLUGIN_NAME}/resources
)

install(FILES schema.usda
    DESTINATION usd/${USDPLUGIN_NAME}/resources/${USDPLUGIN_NAME}
)


# Add Python bindings for the schema plugin
set(USDPLUGIN_PYTHON_NAME _${USDPLUGIN_NAME})

file(GLOB WRAPFILES "wrap*.cpp")

add_library(${USDPLUGIN_PYTHON_NAME}
    SHARED
        ${WRAPFILES}
        module.cpp
        moduleDeps.cpp
)

target_link_libraries(${USDPLUGIN_PYTHON_NAME}
    PUBLIC ${USDPLUGIN_NAME}
)

target_compile_definitions(${USDPLUGIN_PYTHON_NAME}
	PRIVATE
	    MFB_PACKAGE_NAME=${USDPLUGIN_NAME}
		MFB_ALT_PACKAGE_NAME=${USDPLUGIN_NAME}
)

if(WIN32)
    set_target_properties(${USDPLUGIN_PYTHON_NAME} PROPERTIES SUFFIX ".pyd")
endif()


set(INSTALL_PYTHONPACKAGE_DIR python/${USDPLUGIN_NAME})


install(
    TARGETS ${USDPLUGIN_PYTHON_NAME}
    DESTINATION ${INSTALL_PYTHONPACKAGE_DIR}
)

install(FILES __init__.py DESTINATION ${INSTALL_PYTHONPACKAGE_DIR})
