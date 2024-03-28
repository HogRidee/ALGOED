/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 28 de marzo de 2024, 13:18
 */

#include <iostream>

using namespace std;

/*
 * Implementar una función recursiva que reciba como único parámetro un número 
 * en base 10 y lo imprima en base 2
 */

void cambiarBase(int numero){
    int resto;
    if(numero == 0) return;
    
    resto = numero%2;
    cambiarBase(numero/2);
    cout << resto;
}

int main(int argc, char** argv) {

    int numero = 27;
 
    cambiarBase(numero);
    
    return 0;
}

