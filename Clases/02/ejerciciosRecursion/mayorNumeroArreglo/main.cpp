/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 28 de marzo de 2024, 12:03
 */

#include <iostream>

using namespace std;

/*
 * TAREA: Implementar una función recursiva que permita obtener el mayor número
 * de un arreglo de N números enteros
 */

int obtenerMaximo(int *arreglo, int n, int maximo){
    if (n == 0) return maximo;
    
    if(arreglo[n-1] > maximo){
        maximo = arreglo[n-1];
    }
    
    return obtenerMaximo(arreglo, n-1, maximo);
}

int main(int argc, char** argv) {
    int n = 8, maximo;
    int arreglo[n] = {100, 333, 5, 2, 11, 6, 7, 8};
    
    maximo = obtenerMaximo(arreglo, n, 0);
    
    cout << "El maximo es: " << maximo << endl;
    
    return 0;
}

