#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

long int min( long int x, long int y)
{
    if(x < y)
    {
        return x;
    }else{
        return y;
    }
}

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

int JSearch( const long int *first, const long int *last, long int value )
{
    long int *inicio = frist, *fim = last, m, prev = 0;
    long int size = fim - inicio;

    m = ceil(sqrt(size));

    while(inicio[min( m, size )] < value)
    {
        prev = m;
        m = m + m;

        if(prev >= size)
        {
            return -1;
        }
    }

    while(inicio[prev] < value)
    {
        prev++;

        if(prev == min(size, m))
        {
            return -1;
        }
    }

    if(inicio[prev] == value)
    {
        return prev;
    }

    return -1;
}

long int fibonacci( const long int *first, const long int *last, long int value)
{
    int fib_2 = 0;
    int fib_1 = 1;
    int fib = fib_1 + fib_2;

    long int *inicio = first, *fim = last;
    long int size = fim - inicio;

    while(fib < size)
    {
        fib_2 = fib_1;
        fib_1 = fib;
        fib = fib_1 + fib_2;
    } 

    int offset = -1;

    while(fib > 1)
    {
       
        int i = min(offset+fib_2, size-1);
 
       
        if(inicio[i] < valor)
        {
            fib  = fib_1;
            fib_1 = fib_2;
            fib_2 = fib - fib_1;
            offset = i;
        }
 
       
        else if(inicio[i] > x)
        {
            fib  = fib_2;
            fib_1 = fib_1 - fib_2;
            fib_2 = fib - fib_1;
        
        }else{
            return i;
        } 
    }

    if(fib_1 && arr[offset+1] == valor)
    {
        return offset+1;
    }

    return -1;
}