#ifndef INTARRAY_H
#define INTARRAY_H
/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* IntArray.h
* Layl
* Please refer to LICENSE.md
*/

#include <stdint.h>

/////////////////////////////////////////////////////
// FIntArray struct
typedef struct
{
    uint32_t __size;
    uint32_t __capacity;
    int*     __data;
} FIntArray;


/////////////////////////////////////////////////////
// FIntArray funks

// Construction / Destruction, Stack Version
FIntArray  CreateIntArray();
FIntArray  CreateIntArrayWithSize( int iSize );
FIntArray  CreateIntArrayWithData( int* iData, int iSize );
void  DestroyIntArray( FIntArray* iPtr );

// Heap version
FIntArray*  XCreateIntArray();
FIntArray*  XCreateIntArrayWithSize( int iSize );
FIntArray*  XCreateIntArrayWithData( int* iData, int iSize );
void  XDestroyIntArray( FIntArray** iPtr2Ptr );

// Public API
int  IntArrayGetSize( FIntArray* iPtr );
int  IntArrayGetCapacity( FIntArray* iPtr );
int  IntArrayGetElement( FIntArray* iPtr, int iIndex );
void  IntArraySetElement( FIntArray* iPtr, int iIndex, int iValue );
void  IntArrayResize( FIntArray* iPtr, int iSize );
void  IntArrayRealloc( FIntArray* iPtr, int iCapacity );
void  IntArrayPushBack( FIntArray* iPtr, int iValue );
void  IntArrayPopBack( FIntArray* iPtr );
void  IntArraySanitize( FIntArray* iPtr );

#endif // INTARRAY_H

