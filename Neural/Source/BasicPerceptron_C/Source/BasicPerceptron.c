/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* BasicPerceptron.cpp
* Layl
* Please refer to LICENSE.md
*/

#include "BasicPerceptron.h"

/////////////////////////////////////////////////////
// FBasicPerceptron
FBasicPerceptron* CreateBasicPerceptron( uint8_t iSize )
{
    FBasicPerceptron* ret = malloc( sizeof( FBasicPerceptron ) );
    ret->weights = CreateIntArray( iSize );
    ret->bias = 0;
    return  ret;
}


void DestroyBasicPerceptron( FBasicPerceptron** iPtr2Ptr )
{
    if( iPtr2Ptr == NULL || ( *iPtr2Ptr ) == NULL )
        return;

    DestroyIntArray( &( (*iPtr2Ptr)->weights ) );
    free( (*iPtr2Ptr) );
    (*iPtr2Ptr) = NULL;
}


void BasicPerceptronSetBias( FBasicPerceptron* iPtr, int iValue )
{
    if( iPtr == NULL )
        return;

    iPtr->bias = iValue;
}


int BasicPerceptronGetBias( FBasicPerceptron* iPtr )
{
    if( iPtr == NULL )
        return 0;

    return  iPtr->bias;
}


void BasicPerceptronSetWeight( FBasicPerceptron* iPtr, int iIndex, int iValue )
{
    if( iPtr == NULL )
        return;

    if( iIndex >= 0 && iIndex < iPtr->weights->size )
        iPtr->weights->data[iIndex] = iValue;
}


int BasicPerceptronGetWeight( FBasicPerceptron* iPtr, int iIndex )
{
    if( iPtr == NULL )
        return 0;

    if( iIndex >= 0 && iIndex < iPtr->weights->size )
        return  iPtr->weights->data[iIndex];

    return  0;
}


int BasicPerceptronGetSize( FBasicPerceptron* iPtr )
{
    if( iPtr == NULL )
        return 0;

    return  iPtr->weights->size;
}


int BasicPerceptronCompute( FBasicPerceptron* iPtr, FIntArray* iInput )
{
    if( iInput->size != iPtr->weights->size )
        return 0;

    int ret = 0;
    for( int i = 0; i < iPtr->weights->size; ++i )
        ret += iInput->data[i] * iPtr->weights->data[i];

    return  ret + iPtr->bias;
}

