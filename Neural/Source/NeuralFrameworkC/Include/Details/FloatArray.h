#ifndef FLOATARRAY_H
#define FLOATARRAY_H
/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* FloatArray.h
* Layl
* Please refer to LICENSE.md
*/

#include <stdint.h>

/////////////////////////////////////////////////////
// FFloatArray struct
typedef struct
{
    uint32_t __size;
    uint32_t __capacity;
    float*   __data;
} FFloatArray;


/////////////////////////////////////////////////////
// FFloatArray funks

// Construction / Destruction, Stack Version
FFloatArray  CreateFloatArray();
FFloatArray  CreateFloatArrayWithSize( int iSize );
FFloatArray  CreateFloatArrayWithData( float* iData, int iSize );
void  DestroyFloatArray( FFloatArray* iPtr );

// Heap version
FFloatArray*  XCreateFloatArray();
FFloatArray*  XCreateFloatArrayWithSize( int iSize );
FFloatArray*  XCreateFloatArrayWithData( float* iData, int iSize );
void  XDestroyFloatArray( FFloatArray** iPtr2Ptr );

// Public API
int  FloatArrayGetSize( FFloatArray* iPtr );
int  FloatArrayGetCapacity( FFloatArray* iPtr );
float  FloatArrayGetElement( FFloatArray* iPtr, int iIndex );
void  FloatArraySetElement( FFloatArray* iPtr, int iIndex, float iValue );
void  FloatArrayResize( FFloatArray* iPtr, int iSize );
void  FloatArrayRealloc( FFloatArray* iPtr, int iCapacity );
void  FloatArrayPushBack( FFloatArray* iPtr, float iValue );
void  FloatArrayPopBack( FFloatArray* iPtr );
void  FloatArraySanitize( FFloatArray* iPtr );

#endif // FLOATARRAY_H

