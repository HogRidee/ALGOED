/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 9 de mayo de 2024, 10:36
 */

#include <iostream>

using namespace std;

int buscaMax(int *arr, int ini, int fin){
    int med = (ini+fin)/2;
    if(ini >= fin) return arr[ini];
    if(arr[med] > arr[med+1])
        buscaMax(arr, ini, med);
    else
        buscaMax(arr, med+1, fin);
}

int main(int argc, char** argv) {

    int arr[] = {8,10,20,80,100,200,400,500,3,2,1};
    int n = 11;
    
    cout << buscaMax(arr, 0, n-1);
    
    return 0;
}

