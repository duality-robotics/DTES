cmake_minimum_required(VERSION 3.18)
set(USDPLUGIN_NAME usdDTEncapsulation)

project(${USDPLUGIN_NAME} VERSION 0.1 LANGUAGES CXX)

# Options
option(USE_CXX11_ABI "Use C++11 ABI" ON)
# option(INSTALL_TO_USD_DIR "Install to USD directory" OFF)

# Global Settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


set(CMAKE_INSTALL_PREFIX "./install" CACHE PATH "..." FORCE)

if(NOT MSVC AND DEFINED USE_CXX11_ABI)
    add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
endif()


set(CMAKE_MODULE_PATH
    ${USD_BUILD_ROOT}
	${CMAKE_MODULE_PATH}
)

add_subdirectory(usdDTEncapsulation)
