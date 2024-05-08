/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de mayo de 2024, 17:48
 */

#include <iostream>

using namespace std;

int buscaMin(int *arr, int ini, int fin){
    int med = (ini+fin)/2;
    if(ini >= fin) return arr[ini];
    if(arr[med] < arr[med+1])
        return buscaMin(arr, ini, med);
    else
        return buscaMin(arr, med+1, fin);
}

int main(int argc, char** argv) {

    int n = 6;
    int arr[n] = {5,6,1,2,3,4};
    
    cout << buscaMin(arr, 0, n-1);
    
    return 0;
}

