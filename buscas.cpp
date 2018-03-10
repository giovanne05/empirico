#include <iostream>
#include <iterator>
#include <vector>

int * sliterativa( const int *first, const int *last, int value ) // sequencial iterativa
{
   while (*first != *last){
        if( *first == value){
            return first;
        }
   }

    return last; 
}

int * biterativa( int *first, int *last, int value ) // busca binaria iterativa
{
    auto size = last - first;
    auto m = ((size/2)-1);

    if(value == first[m]){
        return &first[m];
    }else if( value < first[m]){
        for( auto i{0}; i < m ; i++){
            if( value == first[i]){
                return &first[i];
            }
        }
    }else{
        for( auto i{0}; i < m; i++){
            if ( value == first[i]){
                return &first[i];
            }
        }
    }


    return last; // STUB
}