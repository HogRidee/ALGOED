/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 16 de mayo de 2024, 11:27
 */

#include <iostream>

#include "Lista.h"
#include "funciones.h"

using namespace std;


void fusionarListas(Lista &tad, Lista &pedidos){
    if(esListaVacia(pedidos)){
        pedidos.cabeza = tad.cabeza;
        pedidos.cola = tad.cola;
        pedidos.longitud = tad.longitud;
    }
    else{
        if(pedidos.cola->elemento < tad.cabeza->elemento){
            pedidos.cola->siguiente = tad.cabeza;
            pedidos.cola = tad.cola;
        }
        else{
            
        }
    }
}

int main(int argc, char** argv) {

    Lista lunes;
    Lista martes;
    Lista miercoles;
    Lista jueves;
    Lista viernes;
    Lista pedidos;
    
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    construir(pedidos);
    
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
    
    fusionarListas(lunes, pedidos);
    fusionarListas(martes, pedidos);
    
    imprime(pedidos);
    
    return 0;
}

