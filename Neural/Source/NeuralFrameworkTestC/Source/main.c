/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* main.c
* Layl
* Please refer to LICENSE.md
*/

#include <stdio.h>
#include <NeuralFrameworkC>
#include "Details/Arrays.h"


int main()
{
    FIntArray   int_arr     = CreateFIntArray();
    FFloatArray float_arr   = CreateFFloatArray();
    FDoubleArray double_arr = CreateFDoubleArray();
    FIntArrayRealloc( &int_arr, 20 );
    FFloatArrayRealloc( &float_arr, 20 );
    FDoubleArrayRealloc( &double_arr, 20 );

    for( int i = 0; i < 20; ++i )
    {
        FIntArrayPushBack( &int_arr, i );
        FFloatArrayPushBack( &float_arr, ( i / 19.f ) );
        FDoubleArrayPushBack( &double_arr, ( i / 19.0 ) );
    }

    for( int i = 0; i < 20; ++i )
    {
        printf( "%i %f %f\n", FIntArrayGetElement( &int_arr, i ), FFloatArrayGetElement( &float_arr, i ), FDoubleArrayGetElement( &double_arr, i ) );
    }

    DestroyFIntArray( &int_arr );
    DestroyFFloatArray( &float_arr );
    DestroyFDoubleArray( &double_arr );


    return  0;
}