/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* IntArray.c
* Layl
* Please refer to LICENSE.md
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "Details/IntArray.h"

/////////////////////////////////////////////////////
// FIntArray funks
//--------------------------------------------------------------------------------------
//-------------------------------------------- Construction / Destruction, Stack Version
FIntArray
CreateIntArray()
{
    FIntArray ret;
    ret.__size      = 0;
    ret.__capacity  = 1;
    ret.__data      = NULL;

    return  ret;
}


FIntArray
CreateIntArrayWithSize( int iSize )
{
    if( iSize <= 0 )
        return  CreateIntArray();

    FIntArray ret;
    int memspan     = sizeof( int ) * iSize;
    ret.__size      = iSize;
    ret.__capacity  = iSize;
    ret.__data      = malloc( memspan );
    memset( ret.__data, 0, memspan );

    return  ret;
}


FIntArray
CreateIntArrayWithData( int* iData, int iSize )
{
    FIntArray ret = CreateIntArrayWithSize( iSize );

    if( iData == NULL )
        return  ret;

    for( int i = 0; i < iSize; ++i )
        ret.__data[i] = iData[i];

    return  ret;
}


void
DestroyIntArray( FIntArray* iPtr )
{
    if( iPtr == NULL )
        return;

    bool allocated = ( iPtr->__capacity > 0 );

    if( allocated && iPtr->__data )
        free( iPtr->__data );
}


//--------------------------------------------------------------------------------------
//--------------------------------------------- Construction / Destruction, Heap Version
FIntArray*
XCreateIntArray()
{
    FIntArray* ret = malloc( sizeof( FIntArray ) );
    ret->__size      = 0;
    ret->__capacity  = 0;
    ret->__data      = NULL;

    return  ret;
}


FIntArray*
XCreateIntArrayWithSize( int iSize )
{
    if( iSize < 0 )
        return  XCreateIntArray();

    FIntArray* ret = malloc( sizeof( FIntArray ) );
    int memspan     = sizeof( int ) * iSize;
    ret->__size      = iSize;
    ret->__capacity  = iSize;
    ret->__data      = malloc( memspan );
    memset( ret->__data, 0, memspan );

    return  ret;
}


FIntArray*
XCreateIntArrayWithData( int* iData, int iSize )
{
    FIntArray* ret = XCreateIntArrayWithSize( iSize );

    if( iData == NULL )
        return  ret;

    for( int i = 0; i < iSize; ++i )
        ret->__data[i] = iData[i];

    return  ret;
}


void
XDestroyIntArray( FIntArray** iPtr2Ptr )
{
    if( iPtr2Ptr == NULL )
        return;

    DestroyIntArray( *iPtr2Ptr );

    iPtr2Ptr = NULL;
}


//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------- Public API
int
IntArrayGetSize( FIntArray* iPtr )
{
    if( iPtr == NULL )
        return  0;

    return  iPtr->__size;
}


int
IntArrayGetCapacity( FIntArray* iPtr )
{
    if( iPtr == NULL )
        return  0;

    return  iPtr->__capacity;
}


int
IntArrayGetElement( FIntArray* iPtr, int iIndex )
{
    if( iPtr == NULL )
        return  0;

    if( iIndex < 0 || iIndex >= (int)iPtr->__size )
        return  0;

    return  iPtr->__data[ iIndex ];
}


void
IntArraySetElement( FIntArray* iPtr, int iIndex, int iValue )
{
    if( iPtr == NULL )
        return;

    if( iIndex < 0 || iIndex > (int)iPtr->__size )
        return;

    iPtr->__data[ iIndex ] = iValue;
}


void
IntArrayResize( FIntArray* iPtr, int iSize )
{
    if( iPtr == NULL )
        return;

    if( iSize >= (int)iPtr->__capacity )
        IntArrayRealloc( iPtr, iSize );

    iPtr->__size = iSize;
}


void
IntArrayRealloc( FIntArray* iPtr, int iCapacity )
{
    if( iPtr == NULL )
        return;

    FIntArray old = *iPtr;
    int new_memspan = sizeof( int ) * iCapacity;
    int old_memspan = sizeof( int ) * old.__capacity;
    int min_memspan = new_memspan < old_memspan ? new_memspan : old_memspan;
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
IntArrayPushBack( FIntArray* iPtr, int iValue )
{
    if( iPtr == NULL )
        return;

    int new_size = iPtr->__size + 1;
    if( new_size >= (int)iPtr->__capacity )
    {
        int new_alloc_space = (int)( iPtr->__capacity * 1.5 + 0.5 ); // Golden Ratio + Ceil
        IntArrayRealloc( iPtr, new_alloc_space );
    }

    iPtr->__size = new_size;
    iPtr->__data[ new_size - 1 ] = iValue;
}


void
IntArrayPopBack( FIntArray* iPtr )
{
    if( iPtr == NULL )
        return;

    if( iPtr->__size <= 0 )
        return;

    int new_size = iPtr->__size - 1;
    new_size = new_size > 0 ? new_size : 0;
    iPtr->__data[ new_size ] = 0;
    iPtr->__size = new_size;
}


void
IntArraySanitize( FIntArray* iPtr )
{
    if( iPtr == NULL )
        return;

    IntArrayRealloc( iPtr, iPtr->__size );
}


FIntArray*
IntArrayCopy( FIntArray* iSrc )
{
    FIntArray* ret = XCreateIntArrayWithSize( iSrc->__size );
    memcpy( ret, iSrc, ret->__size * sizeof( int ) );
    return  ret;
}

