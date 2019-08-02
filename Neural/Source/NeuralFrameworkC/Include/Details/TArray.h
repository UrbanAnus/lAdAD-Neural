#ifndef TARRAY_H
#define TARRAY_H
/*************************************************************************
*
*   AdAD-Neural
*__________________
*
* TArray.h
* Layl
* Please refer to LICENSE.md
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////
// TArray struct
#define NEURAL_TArrayStruct( iType, iName ) \
    typedef struct                          \
    {                                       \
        uint32_t        __size;             \
        uint32_t        __capacity;         \
        iType*          __data;             \
    } iName;


/////////////////////////////////////////////////////
// TArray funks
#define NEURAL_TArrayFunctionsForwardDeclaration( iType, iName )        \
    iName  Create ## iName ();                                          \
    iName  Create ## iName ## WithSize( int iSize );                    \
    iName  Create ## iName ## WithData( iType* iData, int iSize );      \
    void  Destroy ## iName ( iName* iPtr );                             \
    iName*  XCreate ## iName ();                                        \
    iName*  XCreate ## iName ## WithSize( int iSize );                  \
    iName*  XCreate ## iName ## WithData( iType* iData, int iSize );    \
    void  XDestroy ## iName ( iName** iPtr2Ptr );                       \
    int   iName ## GetSize( iName* iPtr );                              \
    int   iName ## GetCapacity( iName* iPtr );                          \
    iType iName ## GetElement( iName* iPtr, int iIndex );               \
    void   iName ## SetElement( iName* iPtr, int iIndex, iType iValue );\
    void   iName ## Resize( iName* iPtr, int iSize );                   \
    void   iName ## Realloc( iName* iPtr, int iCapacity );              \
    void   iName ## PushBack( iName* iPtr, iType iValue );              \
    void   iName ## PopBack( iName* iPtr );                             \
    void   iName ## Sanitize( iName* iPtr );                            \
    iName*  iName ## Copy( iName* iSrc );


#define NEURAL_TArrayFunctionsImplementation( iType, iName )                                                    \
    iName                                                                                                       \
    Create ## iName ()                                                                                          \
    {                                                                                                           \
        iName ret;                                                                                              \
        ret.__size      = 0;                                                                                    \
        ret.__capacity  = 1;                                                                                    \
        ret.__data      = NULL;                                                                                 \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName                                                                                                       \
    Create ## iName ## WithSize( int iSize )                                                                    \
    {                                                                                                           \
        if( iSize <= 0 )                                                                                        \
            return  Create ## iName ();                                                                         \
                                                                                                                \
        iName ret;                                                                                              \
        int memspan     = sizeof( iType ) * iSize;                                                              \
        ret.__size      = iSize;                                                                                \
        ret.__capacity  = iSize;                                                                                \
        ret.__data      = malloc( memspan );                                                                    \
        memset( ret.__data, 0, memspan );                                                                       \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName                                                                                                       \
    Create ## iName ## WithData( iType* iData, int iSize )                                                      \
    {                                                                                                           \
        iName ret = Create ## iName ## WithSize( iSize );                                                       \
                                                                                                                \
        if( iData == NULL )                                                                                     \
            return  ret;                                                                                        \
                                                                                                                \
        for( int i = 0; i < iSize; ++i )                                                                        \
            ret.__data[i] = iData[i];                                                                           \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    Destroy ## iName ( iName* iPtr )                                                                            \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        bool allocated = ( iPtr->__capacity > 0 );                                                              \
                                                                                                                \
        if( allocated && iPtr->__data )                                                                         \
            free( iPtr->__data );                                                                               \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName*                                                                                                      \
    XCreate ## iName ()                                                                                         \
    {                                                                                                           \
        iName* ret = malloc( sizeof( iName ) );                                                                 \
        ret->__size      = 0;                                                                                   \
        ret->__capacity  = 0;                                                                                   \
        ret->__data      = NULL;                                                                                \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName*                                                                                                      \
    XCreate ## iName ## WithSize( int iSize )                                                                   \
    {                                                                                                           \
        if( iSize < 0 )                                                                                         \
            return  XCreate ## iName ();                                                                        \
                                                                                                                \
        iName* ret = malloc( sizeof( iName ) );                                                                 \
        int memspan     = sizeof( iType ) * iSize;                                                              \
        ret->__size      = iSize;                                                                               \
        ret->__capacity  = iSize;                                                                               \
        ret->__data      = malloc( memspan );                                                                   \
        memset( ret->__data, 0, memspan );                                                                      \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName*                                                                                                      \
    XCreate ## iName ## WithData( iType* iData, int iSize )                                                     \
    {                                                                                                           \
        iName* ret = XCreate ## iName ## WithSize( iSize );                                                     \
                                                                                                                \
        if( iData == NULL )                                                                                     \
            return  ret;                                                                                        \
                                                                                                                \
        for( int i = 0; i < iSize; ++i )                                                                        \
            ret->__data[i] = iData[i];                                                                          \
                                                                                                                \
        return  ret;                                                                                            \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    XDestroy ## iName ( iName** iPtr2Ptr )                                                                      \
    {                                                                                                           \
        if( iPtr2Ptr == NULL )                                                                                  \
            return;                                                                                             \
                                                                                                                \
        Destroy ## iName ( *iPtr2Ptr );                                                                         \
                                                                                                                \
        iPtr2Ptr = NULL;                                                                                        \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    int                                                                                                         \
    iName ## GetSize( iName* iPtr )                                                                             \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return  0;                                                                                          \
                                                                                                                \
        return  iPtr->__size;                                                                                   \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    int                                                                                                         \
    iName ## GetCapacity( iName* iPtr )                                                                         \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return  0;                                                                                          \
                                                                                                                \
        return  iPtr->__capacity;                                                                               \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iType                                                                                                       \
    iName ## GetElement( iName* iPtr, int iIndex )                                                              \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return  0;                                                                                          \
                                                                                                                \
        if( iIndex < 0 || iIndex >= (int)iPtr->__size )                                                         \
            return  0;                                                                                          \
                                                                                                                \
        return  iPtr->__data[ iIndex ];                                                                         \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## SetElement( iName* iPtr, int iIndex, iType iValue )                                                \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        if( iIndex < 0 || iIndex > (int)iPtr->__size )                                                          \
            return;                                                                                             \
                                                                                                                \
        iPtr->__data[ iIndex ] = iValue;                                                                        \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## Resize( iName* iPtr, int iSize )                                                                   \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        if( iSize >= (int)iPtr->__capacity )                                                                    \
             iName ## Realloc( iPtr, iSize );                                                                \
                                                                                                                \
        iPtr->__size = iSize;                                                                                   \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## Realloc( iName* iPtr, int iCapacity )                                                              \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        iName old = *iPtr;                                                                                      \
        int new_memspan = sizeof( iType ) * iCapacity;                                                          \
        int old_memspan = sizeof( iType ) * old.__capacity;                                                     \
        int min_memspan = new_memspan < old_memspan ? new_memspan : old_memspan;                                \
        iPtr->__capacity = iCapacity;                                                                           \
        if( (int)iPtr->__size > iCapacity )                                                                     \
            iPtr->__size = iCapacity;                                                                           \
        iPtr->__data = malloc( new_memspan );                                                                   \
        uint8_t* arithmetic_pointer = (uint8_t*)iPtr->__data;                                                   \
        memset( arithmetic_pointer + min_memspan, 0, new_memspan - min_memspan );                               \
                                                                                                                \
        if( old.__data )                                                                                        \
        {                                                                                                       \
            memcpy( arithmetic_pointer, old.__data, min_memspan );                                              \
            free( old.__data );                                                                                 \
        }                                                                                                       \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## PushBack( iName* iPtr, iType iValue )                                                              \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        int new_size = iPtr->__size + 1;                                                                        \
        if( new_size >= (int)iPtr->__capacity )                                                                 \
        {                                                                                                       \
            int new_alloc_space = (int)( iPtr->__capacity * 1.5 + 0.5 );                                        \
            iName ## Realloc( iPtr, new_alloc_space );                                                          \
        }                                                                                                       \
                                                                                                                \
        iPtr->__size = new_size;                                                                                \
        iPtr->__data[ new_size - 1 ] = iValue;                                                                  \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## PopBack( iName* iPtr )                                                                             \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        if( iPtr->__size <= 0 )                                                                                 \
            return;                                                                                             \
                                                                                                                \
        int new_size = iPtr->__size - 1;                                                                        \
        new_size = new_size > 0 ? new_size : 0;                                                                 \
        iPtr->__data[ new_size ] = 0;                                                                           \
        iPtr->__size = new_size;                                                                                \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    void                                                                                                        \
    iName ## Sanitize( iName* iPtr )                                                                            \
    {                                                                                                           \
        if( iPtr == NULL )                                                                                      \
            return;                                                                                             \
                                                                                                                \
        iName ## Realloc( iPtr, iPtr->__size );                                                                 \
    }                                                                                                           \
                                                                                                                \
                                                                                                                \
    iName*                                                                                                      \
    iName ## Copy( iName* iSrc )                                                                                \
    {                                                                                                           \
        iName* ret = XCreate ## iName ## WithSize( iSrc->__size );                                              \
        memcpy( ret, iSrc, ret->__size * sizeof( iType ) );                                                     \
        return  ret;                                                                                            \
    }


/////////////////////////////////////////////////////
// TArray Macros
#define  NEURAL_FDECL_TARRAY( iType, iName )                    \
    NEURAL_TArrayStruct( iType, iName )                         \
    NEURAL_TArrayFunctionsForwardDeclaration( iType, iName )

#define  NEURAL_IMP_TARRAY( iType, iName )                      \
    NEURAL_TArrayFunctionsImplementation( iType, iName )        \


#endif // TARRAY_H

