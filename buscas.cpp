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

long int sequencial_iterativa( long int *first, long int *last, long int value ) // sequencial iterativa
{
   while (first != last){
        if( *first == value){        
			 return *first;
        }
		first++;
   }

    return -1; 
}

int binaria_iterativa( long int *first, long int *last, long int value ) // busca binaria iterativa
{
    long int *backup;

    backup = first;
    
    long int *t1;
    

    do{
       
    t1 =(last - first)/2 + first;


        if(value == *t1){
            return t1 - backup;
        }else if(value == *first){
            return first - backup;      
        }else if(value == *last){
            return last - backup;   
        }else if(value < *t1){
            last = t1 -1;
        }else if(value > *t1){
            first = t1 + 1;
        }

    
    }while(first<=last);

return -1;
    
}
 

int ternaria_iterativa( long int *first, long int *last, long int value ) // busca ternaria iterativa
{

	long int *backup;

	backup = first;
    
    long int *t1,*t2;
	

    do{
       
	t1 =(last - first)/3 + first;
	t2 = ((last - first)/3)*2 + first;


		if(value == *t1){
			return t1 - backup;
		}else if(value == *t2){
			return t2 - backup;
		}else if(value == *first){
			return first - backup;		
		}else if(value == *last){
			return last - backup;	
		
		}else if(value<*t1){
			last = t1 -1;
		
		}else if(value>*t1 && value<*t2){
			first = t1 + 1;
			last = t2 - 1;
		
		}else if(value > *t2){
			first = t2 + 1;
		}

	
	}while(first<=last);

return -1;
    
}



long int ternaria_recursiva( long int *first, long int *last, long int value, long int *backup) // busca ternaria recursiva
{
    long int *t1,*t2;

    auto size = last - first;
        auto m = ((size/3)-1);

       
     
        t1 = &first[m];
        t2 = &first[m+m];

        if(value < *t1){
            return ternaria_recursiva(first+1,t1,value,backup);
        }else if(value > *t1 && value < *t2){
            return ternaria_recursiva(t1+1,t2-1,value,backup) ;
        }else if(value > *t2){
            return ternaria_recursiva(t2+1,last,value,backup);      
        }if(*first == value){
            return first - backup;
        }else if(*t1 == value){
            return t1 - backup;
        }else if(*t2 == value){
            return t2 - backup;
        }else if(*last == value){
            return last - backup;
        }else{
			return -1;
		}
        
}

int JSearch( long int *first, long int *last, long int value )
{
    long int *inicio, *fim, m, prev;
    
    inicio = first;
    fim = last;

    long int size = fim - inicio;
		
    prev = 0;    

    m = ceil(sqrt(size));

    if(*fim == value){
        return size;
    }

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

long int fibonacci( long int *first, long int *last, long int value)
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
 
       
        if(inicio[i] < value)
        {
            fib  = fib_1;
            fib_1 = fib_2;
            fib_2 = fib - fib_1;
            offset = i;
        }
 
       
        else if(inicio[i] > value)
        {
            fib  = fib_2;
            fib_1 = fib_1 - fib_2;
            fib_2 = fib - fib_1;
        
        }else{
            return i;
        } 
    }

    if(fib_1 && inicio[offset+1] == value)
    {
        return offset+1;
    }

    return -1;
}
