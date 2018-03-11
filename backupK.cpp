int JSearch( const long int *first, const long int *last, long int value )
{
    long int inicio = frist, fim = last, m, prev = 0;
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