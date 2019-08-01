#ifndef NETWORK_H
#define NETWORK_H
/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* Network.h
* Layl
* Please refer to LICENSE.md
*/

#include <stdint.h>
#include "Details/IntArray.h"
#include "Details/FloatArray.h"

/////////////////////////////////////////////////////
// FNetwork struct
typedef struct
{
    int num_layers;
    FIntArray    sizes;
    FFloatArray  biases;
    FFloatArray* weights;
} FNetwork;


/////////////////////////////////////////////////////
// FNetwork funks
FNetwork  CreateNetwork( FIntArray* iSizes );


#endif // NETWORK_H

