/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* Network.c
* Layl
* Please refer to LICENSE.md
*/

#include <stdlib.h>
#include <string.h>
#include "Details/Network.h"

/////////////////////////////////////////////////////
// FNetwork funks
FNetwork  CreateNetwork( FIntArray* iSizes )
{
    FNetwork ret;
    ret.num_layers = iSizes->__size;
    ret.sizes = *IntArrayCopy( iSizes );
    ret.biases = CreateFloatArrayWithSize( ret.num_layers );
    ret.weights = malloc( sizeof( FFloatArray ) * ret.num_layers );
    for( int i = 0; i < ret.num_layers; ++i )
        ret.weights[i] = CreateFloatArrayWithSize( IntArrayGetElement( &ret.sizes, 1 ) );

    return  ret;
}