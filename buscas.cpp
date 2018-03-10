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
int * ternariait( int *first, int *last, int value ) // busca ternaria iterativa
{

	auto size = last - first;
	auto m = ((size/3)-1);
	auto t1 , t2;

	t1 = (m + m);

	if(value == first[m]){
		return &first[m];
	}else if( value < first[m]){
		for( auto i{0}; i < m ; i++){
			if (value == first[i]){
				return &first [i];
			}
		}
	}else if ( value > first[m] && value <= first[t1] ){
		if(value = first[t1]){
			return &first[t1];
		}
		for(auto i{m}; i < t1 ; i++){
			if(value == first[i]){
				return &first[i];
			}
		}
	}else {
		for( auto i{t1}; i <= size; i++ ){
			if(value == first[i]){
				return &first[i];
			}
		}
	}

	return last;

}
