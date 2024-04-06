/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */
int main(int argc, char** argv) {

    struct Lista lista;
    /*Construimos la lista, la lista esta vacía*/
    construir(lista);
    cout<<esListaVacia(lista)<<endl;
       
    /*Inserta datos comenzando desde el inicio de la lista*/
    insertarAlInicio(lista, 5);
    insertarAlInicio(lista, 3);
    insertarAlInicio(lista, 1);
    imprime(lista);
    
    /*Inserta datos desde el final de la lista*/
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 10);
    imprime(lista);

    /*Insertar en orden los elementos de la lista*/
    insertarEnOrden(lista, 4);
    insertarEnOrden(lista, 2);
    insertarEnOrden(lista, 7);
    imprime(lista);

    /*Elimina un nodo de la lista correspondiente al elemento ingresado*/
    eliminaNodo(lista, 5);
    eliminaNodo(lista, 3);
    imprime(lista);

    /*Elimina el primer nodo de la lista*/
    eliminaCabeza(lista);
    imprime(lista);

    /*Elimina el último nodo de la lista*/
    eliminaCola(lista);
    imprime(lista);

    /*Búsqueda en la lista*/
    int elemento = 10;
    if (seEncuentra(lista, elemento))
        cout << "Sí se encuentra " << elemento << " en la lista" << endl;
    else
        cout << "No se encuentra " << elemento << " en la lista" << endl;

    /*Liberamos la memoria de la lista*/
    destruir(lista);
    /*Muestra los elementos de la lista*/
    imprime(lista);

    
    construir(lista);
    cout<<esListaVacia(lista)<<endl;
       
    /*Crea la lista desde un archivo*/
    insertarAlInicioArchivo("Datos.txt", lista);
    imprime(lista);
    return 0;
}

