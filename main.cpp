include <iostream>
#include "funcoes.h"
#include <iterator>
#include <vector>

int main()
{
	int  size, numero;
	long int *first, *last,i,t;

	t = 10000000;

	std::vector<long int> v;

	for( i = 0; i < t; i++)
	{
		v.push_back(i);
	} 

	pos = v.begin();

	std::cout<<pos;

	return 0;
}

