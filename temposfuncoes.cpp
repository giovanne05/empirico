#include <iostream>
#include "funcoes.h"
#include <iterator>
#include <vector>
#include <chrono>

void tempofuncaoiterativa(long int *first,long int *last,long int numero){

auto start = std::chrono::steady_clock::now();

long int sequencial_iterativa(*first,*last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count()

std::cout<< x;

return ; 

}

/*void tempofuncaoiterativa(*first,*last,numero){

auto start = std::chrono::steady_clock::now();

long int binaria_iterativa(*first,*last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count()

return ; 

}

void tempofuncaoiterativa(*first,*last,numero){

auto start = std::chrono::steady_clock::now();

long int ternaria_iterativa(*first,*last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count()

return ; 

}

void tempofuncaoiterativa(*first,*last,numero){

auto start = std::chrono::steady_clock::now();

long int JSearch(*first,*last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count()

return ; 

}

void tempofuncaoiterativa(*first,*last,numero){

auto start = std::chrono::steady_clock::now();

long int fibonacci(*first,*last,numero);

auto end = std::chrono::steady_clock::now();
double x = std::chrono::duration <double, std::milli> (end-start).count()

return ; 

}
*/
