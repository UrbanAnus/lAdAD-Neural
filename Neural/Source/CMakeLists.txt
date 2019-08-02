cmake_minimum_required(VERSION 3.11.0)

# Set Cache variables
SET( NEURAL_EXPLICIT_HOST_ID        "unset"     CACHE STRING    "Explicitly set host ID from command line" )
SET( NEURAL_EXPLICIT_COMPILER_ID    "unset"     CACHE STRING    "Explicitly set compiler ID from command line" )
SET( NEURAL_USE_CONFIG              OFF         CACHE BOOL      "Scpecifies wether to use config files for overriding cache variables" )
SET( NEURAL_BUILD_SHARED            OFF         CACHE BOOL      "Sets if we build the library shared or static" )
SET( NEURAL_BUILD_TESTS             OFF         CACHE BOOL      "Sets if we build the test programs" )
SET( NEURAL_BUILD_GUIS              OFF         CACHE BOOL      "Sets if we build the gui programs" )
SET( NEURAL_QT_CMAKE_PATH           "unset"     CACHE STRING    "Indicates the path to Qt cmake package" )


# Display host & compiler
message( "Generating: ${NEURAL_EXPLICIT_HOST_ID} ${NEURAL_EXPLICIT_COMPILER_ID}")

# Generate only Debug and Release configurations for all projects
set( CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING INTERNAL FORCE )

# Generate only x64 configurations for all projects
#set( CMAKE_GENERATOR_PLATFORM x64 )

# Get rid of cmake's ZERO_CHECK for solution
set( CMAKE_SUPPRESS_REGENERATION true )

# Set Debug postfix for all projects
set( CMAKE_DEBUG_POSTFIX d )

# Set Runtime Library for all projects
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

# Set C++ standard options
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create global solution
project( Neural )

#--------------------------------------------
# Flags for Compiler / Platforms
# Flags for CLANG
if( "${NEURAL_EXPLICIT_COMPILER_ID}" STREQUAL "CLANG" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")
    
# Flags for GCC
elseif( "${NEURAL_EXPLICIT_COMPILER_ID}" STREQUAL "GCC" )
    # Specific flags for GNU GCC
    if( "${NEURAL_EXPLICIT_HOST_ID}" STREQUAL "GNU" )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1 -W")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    # Specific flags for MinGW GCC
    elseif( "${NEURAL_EXPLICIT_HOST_ID}" STREQUAL "WIN" )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1 -W")
    endif()

    # Support for alternat drop-in replacement of ld linker with Clang's lld, only for recent GCC ( not 7.3.0 shipped with Qt )
    #set(CMAKE_LINKER lld)
    #SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fuse-ld=lld")
    #SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
    
elseif( "${NEURAL_EXPLICIT_COMPILER_ID}" STREQUAL "MSVC" )
    # Flags for MSVC
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Zi -Gm- -Od -Ob0 -RTC1 -MDd")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -EHsc")
endif()

#--------------------------------------------
# Read Preferences if needed
if( ${NEURAL_USE_CONFIG} )
    #--------------------------------------------
    # Read Default Preferences
    include(${CMAKE_CURRENT_SOURCE_DIR}/../Tools/DefaultConfig.cmake)
    
    #--------------------------------------------
    # IF USING CLANG ON MAC WITH XCODE
    if( ${CMAKE_GENERATOR} STREQUAL "Xcode" )
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../Xcode_Config.cmake)
                message( "ouiouioui")
                include(${CMAKE_CURRENT_SOURCE_DIR}/../../Xcode_Config.cmake)
        endif()
    endif()
    
    #--------------------------------------------
    # IF USING CLANG ON WINDOWS WITH VISUALSTUDIO
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # using Clang
        if( ${CMAKE_GENERATOR} STREQUAL "Visual Studio 15 2017 Win64" )
            if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../VisualStudio_Solution_CLANG_LLVM_Config.cmake)
                include(${CMAKE_CURRENT_SOURCE_DIR}/../../VisualStudio_Solution_CLANG_LLVM_Config.cmake)
            endif()
        endif()

    #--------------------------------------------
    # IF USING GCC
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        # Specific flags for GNU GCC
        if( "${NEURAL_EXPLICIT_HOST_ID}" STREQUAL "GNU" )
            if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../SublimeText_Project_GNU_GCC_Config.cmake)
                include(${CMAKE_CURRENT_SOURCE_DIR}/../../SublimeText_Project_GNU_GCC_Config.cmake)
            endif()
        # Specific flags for MinGW GCC
        elseif( "${NEURAL_EXPLICIT_HOST_ID}" STREQUAL "WIN" )
            if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../MinGW_Makefile_GCC_Config.cmake)
                include(${CMAKE_CURRENT_SOURCE_DIR}/../../MinGW_Makefile_GCC_Config.cmake)
            endif()
        endif()

    #--------------------------------------------
    # IF USING MSVC
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../VisualStudio_Solution_MSVC_Config.cmake)
            include(${CMAKE_CURRENT_SOURCE_DIR}/../../VisualStudio_Solution_MSVC_Config.cmake)
        endif()
    endif()
endif()

#--------------------------------------------
# Qt Options
if( NOT "${NEURAL_QT_CMAKE_PATH}" STREQUAL "default")
    set (CMAKE_PREFIX_PATH ${NEURAL_QT_CMAKE_PATH})
    set (CMAKE_AUTOMOC ON)
endif()

#--------------------------------------------
# Add projects
include(${CMAKE_CURRENT_SOURCE_DIR}/NeuralFrameworkC/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/NeuralFrameworkCPP/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/BasicPerceptronC/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/BasicPerceptronCPP/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/NeuralFrameworkTestC/CMakeLists.txt)

if( ${NEURAL_BUILD_TESTS} )
    if( ${NEURAL_BUILD_GUIS} )
    endif()
endif()

set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT NeuralFrameworkC )
