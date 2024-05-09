/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 9 de mayo de 2024, 10:46
 */

#include <iostream>

using namespace std;

int fusionarContar(int *arr, int *aux, int ini, int med, int fin) {
    int i = ini;
    int j = med;
    int k = ini;
    int cont = 0;
    while((i <= med-1) and (j <= fin)) {
        if(arr[i] <= arr[j])
            aux[k++] = arr[i++]; //aux[k]=arr[i]; i++; k++;
        else{
            aux[k++] = arr[j++];
            cont = cont + (med - i);
        }
    }
    while(i <= med - 1)
        aux[k++] = arr[i++];
    while(j <= fin)
        aux[k++] = arr[j++];
    for(i = ini; i <= fin; i++)
        arr[i] = aux[i];
    return cont;
}

int contarInversiones(int *arr, int *aux, int ini, int fin) {
    int cont = 0;
    if(fin > ini){
        int med = (fin+ini)/ 2;
        cont += contarInversiones(arr, aux, ini, med);
        cont += contarInversiones(arr, aux, med + 1, fin);
        cont += fusionarContar(arr, aux, ini, med + 1, fin);
    }
    return cont;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    int aux[5];
    
    cout << contarInversiones(arr, aux, 0, n - 1) << endl;  // Output: 3

    return 0;
}