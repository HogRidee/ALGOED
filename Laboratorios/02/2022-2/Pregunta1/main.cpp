/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 21 de abril de 2024, 11:11
 */

#include <iostream>
#include <fstream>

using namespace std;

#include "Lista.h"
#include "Nodo.h"
#include "funciones.h"

void fusionListas(Lista &lunes, Lista &martes, Lista &miercoles, Lista &jueves, 
        Lista &viernes, Lista &sabado);

int main(int argc, char** argv) {

    Lista lunes, martes, miercoles, jueves, viernes, sabado;
    
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    construir(sabado);
    
    insertarAlFinal(lunes, 8, 6);
    insertarAlFinal(lunes, 10, 14);
    insertarAlFinal(lunes, 12, 1);
    
    insertarAlFinal(martes, 9, 3);
    insertarAlFinal(martes, 11, 8);
    
    insertarAlFinal(miercoles, 8, 2);
    insertarAlFinal(miercoles, 9, 5);
    insertarAlFinal(miercoles, 10, 10);
    
    insertarAlFinal(jueves, 14, 13);
    insertarAlFinal(jueves, 15, 9);
    insertarAlFinal(jueves, 16, 11);
    
    insertarAlFinal(viernes, 17, 4);
    insertarAlFinal(viernes, 18, 12);
    insertarAlFinal(viernes, 19, 7);
    
    fusionListas(lunes, martes, miercoles, jueves, viernes);
    
    imprime(sabado);
    
    destruir(lunes);
    destruir(martes);
    destruir(miercoles);
    destruir(jueves);
    destruir(viernes);
    destruir(sabado);
    
    return 0;
}

