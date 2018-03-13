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
