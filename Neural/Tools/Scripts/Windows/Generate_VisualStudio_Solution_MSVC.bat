@echo off

:: Ensure local scope
setlocal

:: Ensure current dir
pushd %~dp0

:: CD 3 steps up to root/Neural
cd ../../../

:: Make Generated dir for generated project if not exist
IF NOT EXIST Generated_VisualStudio_Solution_MSVC ( MKDIR Generated_VisualStudio_Solution_MSVC )

:: Step in Generated dir
cd Generated_VisualStudio_Solution_MSVC

:: Clean cmake garbage if there
IF EXIST CMakeFiles ( rmdir /S /Q CMakeFiles )
IF EXIST cmake_install.cmake ( del cmake_install.cmake )
IF EXIST CMakeCache.txt ( del CMakeCache.txt )

:: Rebuild Project
cmake -G "Visual Studio 15 2017 Win64" -DNEURAL_USE_CONFIG:BOOL=ON -DNEURAL_EXPLICIT_COMPILER_ID:STRING="MSVC" -DNEURAL_EXPLICIT_HOST_ID:STRING="WIN" ../Source

:: Create symbolic link to solution in root
cd ../../
IF EXIST Neural_MSVC.sln ( del Neural_MSVC.sln )
mklink "Neural_MSVC.sln" "Neural\Generated_VisualStudio_Solution_MSVC\Neural.sln"
