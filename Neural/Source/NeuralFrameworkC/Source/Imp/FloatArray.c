/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* FloatArray.c
* Layl
* Please refer to LICENSE.md
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Details/FloatArray.h"

/////////////////////////////////////////////////////
// FFloatArray funks
//--------------------------------------------------------------------------------------
//-------------------------------------------- Construction / Destruction, Stack Version
FFloatArray
CreateFloatArray()
{
    FFloatArray ret;
    ret.__size      = 0;
    ret.__capacity  = 1;
    ret.__data      = NULL;

    return  ret;
}


FFloatArray
CreateFloatArrayWithSize( int iSize )
{
    if( iSize <= 0 )
        return  CreateFloatArray();

    FFloatArray ret;
    int memspan     = sizeof( float ) * iSize;
    ret.__size      = iSize;
    ret.__capacity  = iSize;
    ret.__data      = malloc( memspan );
    memset( ret.__data, 0, memspan );

    return  ret;
}


FFloatArray
CreateFloatArrayWithData( float* iData, int iSize )
{
    FFloatArray ret = CreateFloatArrayWithSize( iSize );

    if( iData == NULL )
        return  ret;

    for( int i = 0; i < iSize; ++i )
        ret.__data[i] = iData[i];

    return  ret;
}


void
DestroyFloatArray( FFloatArray* iPtr )
{
    if( iPtr == NULL )
        return;

    bool allocated = ( iPtr->__capacity > 0 );

    if( allocated && iPtr->__data )
        free( iPtr->__data );
}


//--------------------------------------------------------------------------------------
//--------------------------------------------- Construction / Destruction, Heap Version
FFloatArray*
XCreateFloatArray()
{
    FFloatArray* ret = malloc( sizeof( FFloatArray ) );
    ret->__size      = 0;
    ret->__capacity  = 0;
    ret->__data      = NULL;

    return  ret;
}


FFloatArray*
XCreateFloatArrayWithSize( int iSize )
{
    if( iSize < 0 )
        return  XCreateFloatArray();

    FFloatArray* ret = malloc( sizeof( FFloatArray ) );
    int memspan     = sizeof( float ) * iSize;
    ret->__size      = iSize;
    ret->__capacity  = iSize;
    ret->__data      = malloc( memspan );
    memset( ret->__data, 0, memspan );

    return  ret;
}


FFloatArray*
XCreateFloatArrayWithData( float* iData, int iSize )
{
    FFloatArray* ret = XCreateFloatArrayWithSize( iSize );

    if( iData == NULL )
        return  ret;

    for( int i = 0; i < iSize; ++i )
        ret->__data[i] = iData[i];

    return  ret;
}


void
XDestroyFloatArray( FFloatArray** iPtr2Ptr )
{
    if( iPtr2Ptr == NULL )
        return;

    DestroyFloatArray( *iPtr2Ptr );

    iPtr2Ptr = NULL;
}


//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------- Public API
int
FloatArrayGetSize( FFloatArray* iPtr )
{
    if( iPtr == NULL )
        return  0;

    return  iPtr->__size;
}


int
FloatArrayGetCapacity( FFloatArray* iPtr )
{
    if( iPtr == NULL )
        return  0;

    return  iPtr->__capacity;
}


float
FloatArrayGetElement( FFloatArray* iPtr, int iIndex )
{
    if( iPtr == NULL )
        return  0;

    if( iIndex < 0 || iIndex >= (int)iPtr->__size )
        return  0;

    return  iPtr->__data[ iIndex ];
}


void
FloatArraySetElement( FFloatArray* iPtr, int iIndex, float iValue )
{
    if( iPtr == NULL )
        return;

    if( iIndex < 0 || iIndex > (int)iPtr->__size )
        return;

    iPtr->__data[ iIndex ] = iValue;
}


void
FloatArrayResize( FFloatArray* iPtr, int iSize )
{
    if( iPtr == NULL )
        return;

    if( iSize >= (int)iPtr->__capacity )
        FloatArrayRealloc( iPtr, iSize );

    iPtr->__size = iSize;
}


void
FloatArrayRealloc( FFloatArray* iPtr, int iCapacity )
{
    if( iPtr == NULL )
        return;

    FFloatArray old = *iPtr;
    int new_memspan = sizeof( float ) * iCapacity;
    int old_memspan = sizeof( float ) * old.__capacity;
    int min_memspan = min( new_memspan, old_memspan );
    iPtr->__capacity = iCapacity;
    if( (int)iPtr->__size > iCapacity )
        iPtr->__size = iCapacity;
    iPtr->__data = malloc( new_memspan );
    uint8_t* arithmetic_pointer = (uint8_t*)iPtr->__data;
    memset( arithmetic_pointer + min_memspan, 0, new_memspan - min_memspan );

    if( old.__data )
    {
        memcpy( arithmetic_pointer, old.__data, min_memspan );
        free( old.__data );
    }
}


void
FloatArrayPushBack( FFloatArray* iPtr, float iValue )
{
    if( iPtr == NULL )
        return;

    int new_size = iPtr->__size + 1;
    if( new_size >= (int)iPtr->__capacity )
    {
        int new_alloc_space = (int)( iPtr->__capacity * 1.5 + 0.5 ); // Golden Ratio + Ceil
        FloatArrayRealloc( iPtr, new_alloc_space );
    }

    iPtr->__size = new_size;
    iPtr->__data[ new_size - 1 ] = iValue;
}


void
FloatArrayPopBack( FFloatArray* iPtr )
{
    if( iPtr == NULL )
        return;

    if( iPtr->__size <= 0 )
        return;

    int new_size = max( iPtr->__size - 1, 0 );
    iPtr->__data[ new_size ] = 0;
    iPtr->__size = new_size;
}


void
FloatArraySanitize( FFloatArray* iPtr )
{
    if( iPtr == NULL )
        return;

    FloatArrayRealloc( iPtr, iPtr->__size );
}


FFloatArray*
FloatArrayCopy( FFloatArray* iSrc )
{
    FFloatArray* ret = XCreateFloatArrayWithSize( iSrc->__size );
    memcpy( ret, iSrc, ret->__size * sizeof( float ) );
    return  ret;
}

