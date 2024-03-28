/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 28 de marzo de 2024, 13:05
 */

#include <iostream>

using namespace std;

/*
 * Implementar una función recursiva que indique si un número dado se encuentra 
 * en un arreglo de N números enteros
 */

void buscarNumero(int *arreglo, int buscado, int n, bool &seEncontro){
    if(n == 0) return;
    
    if(buscado == arreglo[n-1]){
        seEncontro = true;
    }
    
    buscarNumero(arreglo, buscado, n-1, seEncontro);
}

int main(int argc, char** argv) {
    int n = 9;
    int buscado = 0;
    int arreglo[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool seEncontro = false;
    
    buscarNumero(arreglo, buscado, n, seEncontro);
    
    if(seEncontro){
        cout << "El numero " << buscado << " se encuentra en el arreglo" << endl;
    }
    else{
        cout << "El numero " << buscado << " no se encuentra en el arreglo" 
                << endl;
    }
    
    return 0;
}

