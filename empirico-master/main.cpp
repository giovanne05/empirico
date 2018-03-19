#include "funcoes.h"
#include "tempo.h"


using namespace std;

int main()
{

	//int verif = 1;
	long int  size, numero, *result;
	int i, t; 
	ofstream f1,f2,f3,f4,f5,f6;
	double m1 = 0 , x;

	t = 100000000;
	size = 4000000;

	//teste 

	std::vector<long int> v;
	v.reserve(t);

	for( i = 0; i < t; i++)
	{
		v.push_back(i);
	} 

	/*
	std::cout<<"Digite o tamanho maximo do vetor para o teste :"<<std::endl;
	std::cin>>size;

	do
	{
		if(size > t)
		{
			std::cout<<"Você digitou um valor inválido, insira novamente: "<<std::endl;
			std::cin>>size;
		}else if(size <= t){
			verif = 0;
		}

	}while(verif != 0);

	*/

	auto first = &(*v.begin());

	auto last = first + size;

	std::cout<<"Digite o valor a ser buscado: "<<std::endl;
	std::cin>>numero;

	//result = ternary_s_r(first,last,last,numero);



	//testes.open("testes.txt");

	for (auto i = 1; i <= 25; i++){
		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_sequencial_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}
		f1.open("f1.txt");
		f1 << m1;
		f1.close();

		m1 = 0;
		x = 0;
		
		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_binaria_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}
		f2.open("f2.txt");
		f2 << m1;
		f2.close();

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_ternaria_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f3.open("f3.txt");
		f3<< m1;
		f3.close();

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_ternaria_recursiva(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f4.open("f4.txt");
		f4 << m1;
		f4.close();

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_JSearch_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f5.open("f5.txt");
		f5 << m1;
		f5.close();

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_fibonacci_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f6.open("f6.txt");
		f6 << m1;
		f6.close();

		m1 = 0;
		x = 0;

		size = size + 4000000;
		last = first + size;

	}


	return 0;
}