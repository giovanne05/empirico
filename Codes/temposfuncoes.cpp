#include "tempo.h"

double tempo_funcao_sequencial_iterativa(long int *first,long int *last,long int numero){

auto start = std::chrono::steady_clock::now();


sequencial_iterativa(first, last, numero);

auto end = std::chrono::steady_clock::now();

double x = std::chrono::duration <double, std::milli> (end-start).count();

return x; 

}

double tempo_funcao_binaria_iterativa(long int *first, long int *last, long int numero){

auto start = std::chrono::steady_clock::now();

binaria_iterativa(first,last,numero);

auto end = std::chrono::steady_clock::now();

double x = std::chrono::duration <double, std::milli> (end-start).count();

return x; 

}

double tempo_funcao_ternaria_iterativa(long int *first,long int *last, long int numero){

auto start = std::chrono::steady_clock::now();

ternaria_iterativa(first,last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count();

return x; 

}

double tempo_funcao_ternaria_recursiva(long int *first,long int *last,long int numero){

auto start = std::chrono::steady_clock::now();

ternaria_recursiva(first, last, last, numero);

auto end = std::chrono::steady_clock::now();

double x = std::chrono::duration <double, std::milli> (end-start).count();

return x; 

}

double tempo_funcao_JSearch_iterativa(long int *first,long int *last, long int numero){

auto start = std::chrono::steady_clock::now();

JSearch(first,last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count();

return x; 

}

double tempo_funcao_fibonacci_iterativa(long int *first,long int *last,long int numero){

auto start = std::chrono::steady_clock::now();

fibonacci(first,last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count();

return x ; 

}

