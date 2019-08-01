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
#include "BasicPerceptron.h"
#include "IntArray.h"

int main()
{
    FBasicPerceptron* microPerceptron = CreateBasicPerceptron( 2 );
    BasicPerceptronSetBias( microPerceptron, -3 );
    BasicPerceptronSetWeight( microPerceptron, 0, 2 );
    BasicPerceptronSetWeight( microPerceptron, 0, 2 );
    FIntArray* inputs = CreateIntArray( 2 );
    inputs->data[0] = 1;
    inputs->data[1] = 0;
    int result = BasicPerceptronCompute( microPerceptron, inputs );
    DestroyBasicPerceptron( &microPerceptron );
    printf( "%i", result );

    return  0;
}