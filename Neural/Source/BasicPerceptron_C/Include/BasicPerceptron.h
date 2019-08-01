#ifndef BASICPERCEPTRON_H
#define BASICPERCEPTRON_H
/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* BasicPerceptron.cpp
* Layl
* Please refer to LICENSE.md
*/

#include "IntArray.h"

/////////////////////////////////////////////////////
// FBasicPerceptron
struct FBasicPerceptron
{
    FIntArray*  weights;
    int         bias;
};
typedef struct FBasicPerceptron FBasicPerceptron;

FBasicPerceptron* CreateBasicPerceptron( uint8_t iSize );
void DestroyBasicPerceptron( FBasicPerceptron** iPtr2Ptr );
void BasicPerceptronSetBias( FBasicPerceptron* iPtr, int iValue );
int BasicPerceptronGetBias( FBasicPerceptron* iPtr );
void BasicPerceptronSetWeight( FBasicPerceptron* iPtr, int iIndex, int iValue );
int BasicPerceptronGetWeight( FBasicPerceptron* iPtr, int iIndex );
int BasicPerceptronGetSize( FBasicPerceptron* iPtr );

#endif // BASICPERCEPTRON_H

