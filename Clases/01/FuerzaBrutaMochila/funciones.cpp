#include "funciones.hpp"

void cargaBinaria(int numero, int *cromosoma){
    int i, aux;
    
    for(i = 0; i < nObjetos; i++) 
        cromosoma[i] = 0;
    
    i = 0;
    
    while(numero > 0){
        aux = numero%2;
        numero /= 2;
        cromosoma[i] = aux;
        i++;
    }
}

