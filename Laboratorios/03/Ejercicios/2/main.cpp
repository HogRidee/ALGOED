/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 6 de mayo de 2024, 16:36
 */

#include <iostream>

using namespace std;

int cuentaCeros(int *arr, int ini, int fin, int cont){
    if(ini > fin) return cont;
    int med = (ini+fin)/2;
    if(arr[med] == 1){
        return cuentaCeros(arr, med+1, fin, cont);
    }
    else{
        return cuentaCeros(arr, ini, med-1, cont+fin-med+1);
    }
}

int main(int argc, char** argv) {

    int n = 7;
    int arr[n] = {1,1,1,1,0,0,0};
    
    cout << cuentaCeros(arr, 0, n-1, 0) << endl;
    
    return 0;
}

