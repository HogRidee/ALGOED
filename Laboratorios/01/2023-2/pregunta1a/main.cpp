/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 29 de marzo de 2024, 18:18
 */

#include <iostream>
#include <cmath>

using namespace std;

void cargaBinaria(int numero, int *cromosoma, int n){
    int resto, j;
    for(j = 0; j < n*n; j++){
        cromosoma[j] = 0;
    }
    j = 0;
    while(numero > 0){
        resto = numero%2;
        numero /= 2;
        cromosoma[j] = resto;
        j++;
    }
}

int main(int argc, char** argv) {

    int n = 4;
    int pesoMaximo = 100;
    int contenedores[n*n] = {20, 20, 20, 20, 10, 30, 10, 30, 10, 10, 10, 10, 
        15, 15, 15, 15};
    int valores[n*n] ={10, 10, 10, 50, 80, 10, 10, 20, 20, 20, 20, 20, 
        50, 50, 50, 50};
    int cromosoma[n*n];
    
    int pesoCromosoma;
    int combinaciones;
    int solucionMaxima = -1;
    int valorCromosoma;
    int valorMaximo = 0;
    
    combinaciones = pow(2, n*n);
    
    for (int i = 0; i < combinaciones; i++){
        cargaBinaria(i, cromosoma, n);
        pesoCromosoma = 0;
        valorCromosoma = 0;
        for (int j = 0; j < n*n; j++){
            if(cromosoma[j] == 1){
                pesoCromosoma += contenedores[j];
                valorCromosoma += valores[j];
            }
        }
        if(pesoCromosoma <= pesoMaximo and valorCromosoma > valorMaximo){
            valorMaximo = valorCromosoma;
            solucionMaxima = i;
        }
    }
    
    cargaBinaria(solucionMaxima, cromosoma, n);
    cout << "Solucion" << endl;
    int i = 0;
    for (int j=0; j<n*n; j++){
	if (cromosoma[j]==1){
		cout<< contenedores[j] <<" ";
	}
        else{
            cout << "   ";
        }
        if(i == 3){
            i = 0;
            cout << endl;
        }
        else{
            i++;
        }
    }
    cout << endl;
    i = 0;
    for (int j = 0; j < n*n; j++){
        if (cromosoma[j] == 1){
            cout << valores[j] << " ";
        }
        else{
            cout << "   ";
        }
        if(i == 3){
            i = 0;
            cout << endl;
        }
        else{
            i++;
        }
    }
    
    return 0;
}

