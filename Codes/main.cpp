#include "funcoes.h"
#include "tempo.h"


using namespace std;

int main()
{

	long int  size, numero;
	int i, t; 
	ofstream f1,f2,f3,f4,f5,f6;
	double m1 = 0 , x;

	t = 100000000;
	size = 4000000;

	std::vector<long int> v;
	v.reserve(t);

	for( i = 0; i < t; i++)
	{
		v.push_back(i);
	} 


	auto first = &(*v.begin());

	auto last = first + size;

	std::cout<<"Digite o valor a ser buscado: "<<std::endl;
	std::cin>>numero;
	
	f1.open("f1.txt");


	for (auto i = 1; i <= 25; i++){

		f1<<size<<", ";

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_sequencial_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}
		
		f1 << m1<<", ";
		
		m1 = 0;
		x = 0;
		
		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_binaria_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}
		
		f1 << m1<<", ";

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_ternaria_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f1 << m1<<", ";

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_ternaria_recursiva(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f1 << m1<<", ";

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_JSearch_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f1 << m1<<", ";

		m1 = 0;
		x = 0;

		for (auto j = 1 ; j <= 100 ; j++){
			x = tempo_funcao_fibonacci_iterativa(first, last, numero);
			m1 = m1 + ((x+m1)/j);
		}

		f1 << m1<<" ";

		m1 = 0;
		x = 0;

		size = size + 4000000;
		last = first + size;

		f1 << m1<<std::endl;

	}
	
	f1.close();
	
	return 0;
}