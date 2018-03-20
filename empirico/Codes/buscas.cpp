#include "funcoes.h"

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

long int binaria_iterativa( long int *first, long int *last, long int value ) // busca binaria iterativa
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
 

long int ternaria_iterativa( long int *first, long int *last, long int value ) // busca ternaria iterativa
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

long int* ternaria_recursiva( long int *first, long int *last,long int *backup, long int value) // busca ternaria recursiva
{
    long int *t1,*t2;

    long int *erro, k;

    k = -1;

    erro = &k;

    while(last-first >= 1){
        
        auto size = last - first;

        t1 =first + ((size)/3);
        t2 = last - ((size)/3);

            if(value < *t1){
                return ternaria_recursiva(first,t1,backup,value);
            }else if(value > *t1 && value < *t2){
                if( t2-t1 > 3){    
                    return ternaria_recursiva(t1,t2,backup,value) ;
                }else{
                    return t1+1;
                }
            }else if(value > *t2){
                return ternaria_recursiva(t2,last,backup,value);      
            }if(*first == value){
                return first;
            }else if(*t1 == value){
                return t1;
            }else if(*t2 == value){
                return t2;
            }else if(*last == value){
                return last;
           }
        }

    return erro;      
}


long int JSearch( long int *first, long int *last, long int value )
{
    /*Variáveis utilizadas para a busca:
    m: tamanho do bloco a ser pulado
    prev: posição do final do bloco anterior
    size: variável utilizada para saber o tamanho maximo do vetor
    */
    long int  m, prev;
    
    long int size = last - first;
		
    prev = 0;    

    m = ceil(sqrt(size));

    /*Aqui é feita a verificação para saber se o elemento procurado é o ultimo do vetor,
    pois a JumpSearch nem sempre verifica a ultima posição durante sua iteração*/
    if(*(last-1) == value){
        return size;
    }

    /*Aqui é feito os "pulos" pelo vetor até que o elemento procurado esteja entre a posição prev e m do vetor.
    Verificando sempre se o valor atual não passou do tamanho maximo do vetor*/
    while(first[min( m, size )] < value)
    {
        prev = m;
        m = m + m;

        if(prev >= size)
        {
            return -1;
        }
    }

    /*Aqui começa a busca pelo elemento desejado dentro do bloco [prev/m]*/
    while(first[prev] < value)
    {
        prev++;

        if(prev == min(size, m))
        {
            return -1;
        }
    }

    //Se o valor foi encontrado, a função retorna ele para a main
    if(first[prev] == value)
    {
        return prev;
    }

    
    //Caso o valo não esteja no vetor, é retornado -1
    return -1;
}

long int fibonacci( long int *first, long int *last, long int value)
{
    /*Variáveis utilizadas para a busca:
    fib_2, fib_1, fib: Variáveis utilizadas para guardar os valores da soma de fibonacci
    size: variável para guardar o temanho desejado para o vetor
    offset: uma compensação para verificar o primeiro valor do bloco, que pode se perder durante a iteração
    i: variável que vai guardar o índice atual na busca, caso o elemento nessa posição seja de ordem menor,
    ele volta um passo na soma de fibonacci, caso seja maior, é voltado dois passos
    */
    int fib_2 = 0;
    int fib_1 = 1;
    int fib = fib_1 + fib_2;

    long int size = last - first;

    while(fib < size)
    {
        fib_2 = fib_1;
        fib_1 = fib;
        fib = fib_1 + fib_2;
    } 

    int offset = -1;
    int i;

    while(fib > 1)
    {
       
        i = min(offset+fib_2, size-1);
 
       
        if(first[i] < value)
        {
            fib  = fib_1;
            fib_1 = fib_2;
            fib_2 = fib - fib_1;
            offset = i;
        }
 
       
        else if(first[i] > value)
        {
            fib  = fib_2;
            fib_1 = fib_1 - fib_2;
            fib_2 = fib - fib_1;
        
        }else{
            return i;
        } 
    }

    if(fib_1 && first[offset+1] == value)
    {
        return offset+1;
    }

    return -1;
}
