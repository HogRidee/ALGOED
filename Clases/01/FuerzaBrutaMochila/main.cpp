/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 20 de marzo de 2024, 14:34
 */
#include "funciones.hpp"

using namespace std;

int main(int argc, char** argv) {

    int objetos[nObjetos] = {1, 2, 4, 1, 12};
    int cromosoma[nObjetos];

    int pesoCromosoma;
    int pesoMochila = 15;
    int solucion = 0;
    int combinaciones;
    
    combinaciones = pow(2, nObjetos);
    
    for(int i = 1; i < combinaciones; i++){
        cargaBinaria(i, cromosoma);
        pesoCromosoma = 0;
        for(int j = 0; j < nObjetos; j++){
            if(cromosoma[j] == 1){
                pesoCromosoma += objetos[j];
            }
        }
        if(pesoCromosoma == pesoMochila){
            solucion = i;
        }
    }
    
    cargaBinaria(solucion, cromosoma);
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
    
    return 0;
}

