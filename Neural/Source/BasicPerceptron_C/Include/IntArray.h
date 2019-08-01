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

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/////////////////////////////////////////////////////
// FIntArray
struct FIntArray
{
    uint8_t     size; // Size
    int*        data; // Elements
};
typedef struct FIntArray FIntArray;

FIntArray* CreateIntArray( uint8_t iSize );
void DestroyIntArray( FIntArray** iArray );

#endif // INTARRAY_H

