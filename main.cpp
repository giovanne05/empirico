#include <iostream>
#include "funcoes.h"

int main()
{
	int i, size, numero;

	//std::vector<int> vetor

	//std::cout<<"Digite o tamanho do vetor para a busca: "<<std::endl;
	//std::cin>>size;

	//for(i = 0; i < size, i++)
	//{
	//	vetor.push_back(i);
	//}

	long int v = {1, 3, 5, 6, 8, 9, 20, 34};

	long int *first, *last;

	first = &v[1];
	last = v[7];

	int result = fibonacci(first, last, 20);

	std::cout<<result;

	if(result == -1)
	{
		std::cout<<"O número não está no vetor \n";
	}else{
		std::cout<<"O número foi encontrado na posição "<<result<<" do vetor \n";
	}

	return 0;
}
