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

int * sequencial_iterativa( const int *first, const int *last, int value ) // sequencial iterativa
{
   while (*first != *last){
        if( *first == value){
            return first;
        }
   }

    return last; 
}

int * binaria_iterativa( long int *first, long int *last, long int value ) // busca binaria iterativa
{
    int i = 0;
    do{
        auto size = last - first;
        auto m = ((size/2)-1);
        
        if(value < vet[m]){
            first = &(vet[i]);
            last = &(vet[m-1]);
        }else if(value > vet[m]){
            first = &(vet[m+1]);
            last = &(vet[size]);
        }
        i++;

   }while(first != value && vet[m] != value && last != value && first != last);

   if(first == value){
        return first;
   }else if(vet[m] == value){
        return vet[m];
   }else if(last == value){
        return last;
   }else{
        return "Elemento nao encontrado";
   }
 
}

int * ternaria_iterativa( long int *first, long int *last, long int value ) // busca ternaria iterativa
{
    
    long int *t1,*t2;

    do{
        auto size = last - first;
        auto m = ((size/3)-1);
        int i = 0;

        first = &(vet[i]);
        last = &(vet[size]);
        t1 = &(vet[m]);
        t2 = &(vet[m+m]);

        if(value < t1){
            i++;
            last = t1;
        }else if(value > t1 && value < t2){
            first = t1;
            last = t2;
        }else if(value > t2){
            first = t2;
            size--;         
        }

   }while(first != value && t1 != value && t2 != value last != value );

   if(first == value){
        return first;
   }else if(t1 == value){
        return t1;
   }else if(t2 == value){
        return t2;
   }else if(last == value){
        return last;
   }else{
        return "Elemento nao encontrado";
   }
 
    
}

int ternaria_recursiva( long int *first, long int *last, long int value ) // busca ternaria iterativa
{
    long int *t1,*t2;

    auto size = last - first;
        auto m = ((size/3)-1);
        int i = 0;

        first = &(vet[i]);
        last = &(vet[size]);
        t1 = &(vet[m]);
        t2 = &(vet[m+m]);

        if(value < t1){
            return ternaria_recursiva(first+1,t1);
        }else if(value > t1 && value < t2){
            return ternaria_recursiva(t1+1,t2-1);
        }else if(value > t2){
            return ternaria_recursiva(t2+1,last);      
        }if(first == value){
            return first;
        }else if(t1 == value){
            return t1;
        }else if(t2 == value){
            return t2;
        }else if(last == value){
            return last;
        }else{
            return -1;
        }
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
