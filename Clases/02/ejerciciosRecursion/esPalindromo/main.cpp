/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 28 de marzo de 2024, 13:48
 */

#include <iostream>

using namespace std;

/*
 * Un palíndromo es una palabra que se escribe exactamente igual , leído en un 
 * sentido o en otro. La palabra level es un palíndromo, por ejemplo.
 * Escribir una función recursiva que devuelva el valor 1(verdadero) si una 
 * palabra es palíndromo y 0(falso) en caso contrario.
 */

int verificarPalindromo(char *palabra, int inicio, int fin){
    if(inicio >= fin) return 1;
    if(palabra[inicio] != palabra[fin]) return 0;
    return verificarPalindromo(palabra, inicio+1, fin-1);
}

int main(int argc, char** argv) {

    int esPalindromo;
    int longitud = 6;
    char palabra[longitud+1] = "levels";
    
    esPalindromo = verificarPalindromo(palabra, 0, longitud-1);
    
    if(esPalindromo){
        cout << "La palabra " << palabra << " es un palindromo" << endl;
    }
    else{
        cout << "La palabra " << palabra << " no es un palindromo" << endl;
    }
    
    return 0;
}

