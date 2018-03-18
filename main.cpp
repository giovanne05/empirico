#include "funcoes.h"

int main()
{

	int verif = 1;
	long int  size, numero, i, t, result;

	t = 100000000;

	std::vector<long int> v;

	for( i = 0; i < t; i++)
	{
		v.push_back(i);
	} 

	std::cout<<"Digite o tamanho maximo do vetor para o teste :"<<std::endl;
	std::cin>>size;

	do
	{
		if(size > t)
		{
			std::cout<<"Você digitou um valor inválido, insira novamente: "<<std::endl;
			std::cin>>size;
		}else if(size < t){
			verif = 0;
		}

	}while(verif != 0);

	auto first = &(*v.begin());

	auto last = first + size;

	std::cout<<"Digite o valor a ser buscado: "<<std::endl;
	std::cin>>numero;

	result = JSearch(first, last, numero);

	std::cout<<result;

	return 0;
}