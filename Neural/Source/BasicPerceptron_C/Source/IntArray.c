/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* IntArray.c
* Layl
* Please refer to LICENSE.md
*/

#include "IntArray.h"

/////////////////////////////////////////////////////
// FIntArray
FIntArray* CreateIntArray( uint8_t iSize )
{
    FIntArray* ret = malloc( sizeof( FIntArray ) );
    int memspan = iSize * sizeof( int );
    ret->size = iSize;
    ret->data = malloc( memspan );
    memset( ret->data, 0, memspan );
    return  ret;
}


void DestroyIntArray( FIntArray** iArray )
{
    if( iArray == NULL || ( *iArray ) == NULL )
        return;

    free( (*iArray)->data );
    free( (*iArray) );
    *iArray = NULL;
}

