/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 6 de mayo de 2024, 9:13
 */

#include <iostream>

using namespace std;

void encontrarSolo(int *arr, int ini, int fin){
    if(ini > fin) return;
    if(ini == fin){
         cout << arr[ini];
         return;
    }
    int med = (ini+fin)/2;
    if(med%2 == 0){
        if(arr[med] == arr[med+1])
            encontrarSolo(arr, med+2, fin);
        else
            encontrarSolo(arr, ini, med);
    }
    else{
        if(arr[med] == arr[med+1])
            encontrarSolo(arr, ini, med-1);
        else
            encontrarSolo(arr, med+1, fin);
    }
}

int main(int argc, char** argv) {
    int n = 11;
    int arreglo[n] = {1,1,3,3,4,5,5,7,7,8,8};
    
    encontrarSolo(arreglo, 0, n-1);
    
    return 0;
}

