/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 8 de abril de 2024, 10:52 AM
 */

#include <iostream>

#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

using namespace std;

void ordenarec(Pila &pila1, int n){
    int max, valor, i = n;
    Pila pila2;
    construir(pila2);
    if(esPilaVacia(pila1) or n == 1) return;
    max = desapilar(pila1);
    i--;
    while(i > 0){
        valor = desapilar(pila1);
        if(max < valor){
            apilar(pila2, max);
            max = valor;
        }
        else{
            apilar(pila2, valor);
        }
        i--;
    }
    apilar(pila1, max);
    while(!esPilaVacia(pila2)){
        valor = desapilar(pila2);
        apilar(pila1, valor);
    }
    destruirPila(pila2);
    ordenarec(pila1, n-1);
}

void pasapila(Pila &pila1, Pila &pila2){
    int valor, n;
    while(!esPilaVacia(pila1)){
        valor = desapilar(pila1);
        n = 0;
        while(!esPilaVacia(pila1)){
            apilar(pila2, valor);
            valor = desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2) and n > 0){
            apilar(pila1, desapilar(pila2));
            n--;
        }
        apilar(pila2, valor);
    }
}

void hanoi(int n, Pila &A, Pila &B, Pila &C){
    if (n == 0) return;
    hanoi(n-1, A, C, B);
    apilar(C, desapilar(A));
    hanoi(n-1, B, A, C);
}

int main(int argc, char** argv) {

    Pila pila, pila2, pila3;
    construir(pila);
    construir(pila2);
    apilar(pila, 5);
    apilar(pila, 4);
    apilar(pila, 3);
    apilar(pila, 2);
    apilar(pila, 1);
    imprimir(pila);
    
//    ordenarec(pila, longitud(pila));
//    imprimir(pila);
//    
//    pasapila(pila, pila2);
//    imprimir(pila2);
    construir(pila3);
    hanoi(longitud(pila), pila, pila2, pila3);
    imprimir(pila3);
    
    return 0;
}

