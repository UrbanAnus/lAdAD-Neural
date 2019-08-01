set -e
cd "`dirname "$0"`"

## CD 3 steps up to root/Neural
cd ../../../

## Make Generated dir for generated project if not exist
if [ ! -d Generated_Xcode ]; then 
	mkdir Generated_Xcode
fi

## Step in Generated dir
cd Generated_Xcode

## Clean cmake garbage if there
if [ -d CMakeFiles ]; then 
	rm -r CMakeFiles 
fi
if [ -f cmake_install.cmake ]; then 
	rm cmake_install.cmake 
fi
if [ -f CMakeCache.txt ]; then 
	rm CMakeCache.txt 
fi

## Rebuild Project
cmake -G "Xcode" -DNEURAL_USE_CONFIG:BOOL=ON -DNEURAL_EXPLICIT_COMPILER_ID:STRING="CLANG" -DNEURAL_EXPLICIT_HOST_ID:STRING="MAC" ../Source