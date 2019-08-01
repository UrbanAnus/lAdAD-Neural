/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* BasicPerceptron.cpp
* Layl
* Please refer to LICENSE.md
*/

#include <cstring>
#include <assert.h>
#include <vector>
#include <iostream>
#include <stdint.h>

/////////////////////////////////////////////////////
// FBasicPerceptron
// N: number of input
// T: type of the weights & inputs
template< uint8_t N, typename T >
class FBasicPerceptron
{

public:
    // Construction / Destruction
    FBasicPerceptron()
        : mBias( static_cast< T >( 0 ) )
    {
        ClearWeights();
    }

public:
    // Public API
    inline  void    ClearWeights    ()                          { memset( mWeights, 0, mMemSpan );                  }
            void    SetWeight       ( int i, T iValue )         { assert( i >=0 && i < N ); mWeights[i] = iValue;   }
            T       GetWeight       ( int i )                   { assert( i >=0 && i < N ); return  mWeights[i];    }
            void    SetBias         ( T iValue )                { mBias = iValue;                                   }
            T       GetBias         ()                          { return  mBias;                                    }

    T Compute( const std::vector< T >& iInput ) {
        assert( iInput.size() == N );
        T res = static_cast< T >( 0 );
        for( int i = 0; i < N; ++i )
            res += iInput[i] * mWeights[i];
        return  res + mBias;
    }

private:
    // Private Data
    T mWeights[ N ];
    T mBias;

private:
    // Constexpr Data
    static constexpr uint8_t mTypeSize  = sizeof( T );
    static constexpr uint8_t mMemSpan   = mTypeSize * N;
};

int main()
{
    FBasicPerceptron< 2, int > MicroPerceptron;
    MicroPerceptron.SetBias( -3 );
    MicroPerceptron.SetWeight( 0, 2 );
    MicroPerceptron.SetWeight( 1, 2 );
    std::vector< int > inputs = { 1, 0 };
    int result = MicroPerceptron.Compute( inputs );
    std::cout << result << std::endl;
    return  0;
}