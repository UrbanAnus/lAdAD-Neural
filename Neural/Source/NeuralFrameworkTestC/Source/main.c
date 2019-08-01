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

int main()
{
    FIntArray   int_arr     = CreateIntArray();
    FFloatArray float_arr   = CreateFloatArray();

    for( int i = 0; i < 20; ++i )
    {
        IntArrayPushBack( &int_arr, i );
        FloatArrayPushBack( &float_arr, ( i / 19.f ) );
    }

    for( int i = 0; i < 20; ++i )
    {
        printf( "%i %f\n", IntArrayGetElement( &int_arr, i ), FloatArrayGetElement( &float_arr, i ) );
    }

    DestroyIntArray(    &int_arr );
    DestroyFloatArray(  &float_arr );


    return  0;
}