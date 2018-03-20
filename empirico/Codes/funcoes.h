#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <fstream>

long int min( long int x, long int y);

long int sequencial_iterativa( long int *first, long int *last, long int value );

long int binaria_iterativa( long int *first, long int *last, long int value );

long int ternaria_iterativa( long int *first, long int *last, long int value );

long int* ternaria_recursiva( long int *first, long int *last, long int *backup , long int value);

long int JSearch( long int *first, long int *last, long int value );

long int fibonacci( long int *first, long int *last, long int value);
