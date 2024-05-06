/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 6 de mayo de 2024, 9:13
 */

#include <iostream>

using namespace std;

 int encontrarSolo(int *arr, int ini, int fin){
     int solo;
     if(ini >= fin) return solo;
     int med = (ini+fin)/2;
     if(arr[med] == arr[med+1]){
         solo = encontrarSolo(arr, ini, med);
     }
     else{
         if(arr[med] != arr[med-1]) return arr[med];
         solo = encontrarSolo(arr, med, fin);
     }
 }

int main(int argc, char** argv) {
    int n = 11, elemento;
    int arreglo[n] = {1,1,3,3,4,5,5,7,7,8,8};
    
    elemento = encontrarSolo(arreglo, 0, n-1);
    
    cout << "El elemento que está solo es " << elemento << endl;
    
    return 0;
}

