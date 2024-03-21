/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 21 de marzo de 2024, 11:37
 */

#include "funciones.hpp"

/*
 * Ahora vamos a tener varias mochilas donde podemos guardar objetos
 */

int main(int argc, char** argv) {

    int objetos[nObjetos] = {1, 2, 4, 1, 12};
    // los valores son el precio de venta de cada objeto
    int valores[nObjetos] = {100, 50, 40, 90, 30};
    int cromosoma[nObjetos];

    int pesoCromosoma;
    int pesoMochila = 15;
    int combinaciones;
    int solucionMaxima = -1;
    int valorCromosoma;
    int valorMaximo = 0;
    
    combinaciones = pow(2, nObjetos);
    
    for(int i = 1; i < combinaciones; i++){
        cargaBinaria(i, cromosoma);
        pesoCromosoma = 0;
        valorCromosoma = 0;
        for(int j = 0; j < nObjetos; j++){
            if(cromosoma[j] == 1){
                pesoCromosoma += objetos[j];
                valorCromosoma += valores[j];
            }
        }
        if(pesoCromosoma <= pesoMochila and valorCromosoma > valorMaximo){
            solucionMaxima = i;
            valorMaximo = valorCromosoma;
        }
    }
    
    cargaBinaria(solucionMaxima, cromosoma);
    cout << "Solucion" << endl;
    for (int i = 0; i < nObjetos; i++){
        cout << cromosoma[i];
    }
    cout << endl;
    for (int j=0; j<nObjetos; j++){
	if (cromosoma[j]==1){
		cout<<objetos[j]<<" ";
	}
    }
    cout << endl;
    for (int j = 0; j < nObjetos; j++){
        if (cromosoma[j] == 1){
            cout << valores[j] << " ";
        }
    }
    
    return 0;
}


