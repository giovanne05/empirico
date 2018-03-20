#include <iostream>
#include "funcoes.h"
#include <iterator>
#include <vector>
#include <chrono>

double tempo_funcao_sequencial_iterativa(long int *first,long int *last, long int numero);

double tempo_funcao_binaria_iterativa(long int *first, long int *last, long int numero);

double tempo_funcao_ternaria_iterativa(long int *first,long int *last, long int numero);

double tempo_funcao_ternaria_recursiva(long int *first,long int *last,long int numero);

double tempo_funcao_JSearch_iterativa(long int *first,long int *last, long int numero);

double tempo_funcao_fibonacci_iterativa(long int *first,long int *last,long int numero);