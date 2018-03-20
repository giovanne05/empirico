#include "funcoes.h"

/*Função auxiliar para encontar o valor mínimo entre dois inteiros, que será utilizada nas funções Jsearch e Fibonacci
*/
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
	/*Esta função é bastante simples, ela recebe três variáveis por parâmetro: first, last e value 
	e com eles ela percorre o vetor linearmente, caso encontre o valor, ela o retorna, caso não encontre, é retornado -1;
	*/
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
	/*Variáveis utilizadas para a função:
	fisrt: ponteiro para o início do vetor;
    last: ponteiro para o final do vetor;
    value: valor que desejamos encontrar no vetor;
    backup: variével de auxílio para guardar o primeiro valor de first;
    t1: valor do índice onde ocorreu a divisão do vetor em duas partes.
	*/
    long int *backup;

    backup = first;
    
    long int *t1;
    
    /*Aqui a função define o valor de t1 como metade do seu tamanho total, daí é verificado se o valor desejado é ou não igual ao valor de t1.
    Caso seja, ele retorna t1.
    Caso seja maior, ele atualiza o valor de first para ser o valor de t1+1 e volta a iterar.
    Caso seja menor, ele atualiza o valor de last para ser o valor de t1-1 e volta a iterar.
    Isso continua até o valor estar na posição de first, last ou t1.  
    */
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

	/*Variáveis utilizadas na função:
	fisrt: ponteiro para o início do vetor;
    last: ponteiro para o final do vetor;
    value: valor que desejamos encontrar no vetor;
    backup: variável de auxílio que guarda o valor absoluto de first;
    t1 e t2: valores necessários para particionar o vetor e realizar a busca ternária.
	*/
	long int *backup;

	backup = first;
    
    long int *t1,*t2;
	

    do{
       
    //Aqui é atualizado o valor de t1 e t2 para que ocupem 1/3 do vetor e seja possível realizar a busca.
	t1 =(last - first)/3 + first;
	t2 = ((last - first)/3)*2 + first;


		/*Aqui é realizada a busca no vetor:
		Caso o valor desejado esteja na posição de first, last, t1 ou t2, retorna-se o valor imediatamente.
		Caso o valor seja menor que t1, o valor de last é atualizado para t1-1 e retornamos a iteração.
		Caso o valor seja maior que t1 e menor que t2, os valor de first é atualizado para t1+1 e last para t2-1 e retorna-se a iteração.
		Caso o valor seja maior que t2, o valor de first é atualizado para t2+1 e a iteração é retomada.
		Caso após toda iteração o valor não for encontrado, é retornado -1
		*/
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

long int* ternaria_recursiva( long int *first, long int *last, long int *backup, long int value) // busca ternaria recursiva
{
   	/*Variáveis utilizadas na função:
   	fisrt: ponteiro para o início do vetor;
    last: ponteiro para o final do vetor;
    value: valor que desejamos encontrar no vetor;
    backup: variável de auxílio que guarda o valor absoluto de first;
    t1 e t2: valores necessários para particionar o vetor e realizar a busca ternária.
    k e erro: variáveis utilizadas para retornar o -1, já que a função retorna um ponteiro, foi-se necessária a criação delas.
	*/
    long int *t1,*t2;

    long int *erro, k;

    k = -1;

    erro = &k;

    /*Similar a vesão iterativa a sua única peculiaridade é a utilização de 4 parâmetros para a chamada da função, 
    devido novamente ao tipo de retorno da função, que tornou necessária a informação armazenada em backup.
    */
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
    fisrt: ponteiro para o início do vetor;
    last: ponteiro para o final do vetor;
    value: valor que desejamos encontrar no vetor;
    m: tamanho do bloco a ser pulado;
    prev: posição do final do bloco anterior;
    size: variável utilizada para saber o tamanho maximo do vetor.
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
    fisrt: ponteiro para o início do vetor;
    last: ponteiro para o final do vetor;
    value: valor que desejamos encontrar no vetor;
    fib_2, fib_1, fib: Variáveis utilizadas para guardar os valores da soma de fibonacci;
    size: variável para guardar o temanho desejado para o vetor;
    offset: uma compensação para verificar o primeiro valor do bloco, que pode se perder durante a iteração;
    i: variável que vai guardar o índice atual na busca, caso o elemento nessa posição seja de ordem menor,
    ele volta um passo na soma de fibonacci, caso seja maior, é voltado dois passos.
    */
    int fib_2 = 0;
    int fib_1 = 1;
    int fib = fib_1 + fib_2;

    long int size = last - first;

    /*Aqui é feita a sequência de fibonacci para que fib tenha um valor maior do que o tamanho de vetor, 
    pois esse é um dos requesitos do algorítimo
    */
    while(fib < size)
    {
        fib_2 = fib_1;
        fib_1 = fib;
        fib = fib_1 + fib_2;
    } 

    int offset = -1;
    int i;

    /*Aqui começa a busca pelo valor desejado, seguindo a definição:
    Primeiramente é atualizado o valor de i para o menor valor entre offset+fib_2 e size-1, o qual servirá de índice de consulta do vetor;
	Caso o valor desejado seja maior do que o valor da posição atual da iteração, retorna-se a sequência de fibonacci para o valor anterior;
	Caso o valor desejado seja menor que o valor da posição atual da iteração, a sequência de fibonacci volta dois valores;
	Caso não seja nem maior nem menor, o valor foi encontrado e o valor de i é retornado.
    */
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

    /*Aqui é onde verificamos se o valor do índice offset+1 e fib_1 é igual ao valor desejado (o que pode ocorrer se o valor for exatamente a ultima posição do vetor),
    caso sejam iguais, é retornado o índice em que esse valor se encontra (offset+1).
    */
    if(fib_1 && first[offset+1] == value)
    {
        return offset+1;
    }

    return -1;
}
