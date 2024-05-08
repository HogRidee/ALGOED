/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de mayo de 2024, 18:13
 */

#include <iostream>

using namespace std;

int maximo(int a, int b){
    if(a > b) return a;
    else return b;
}

int maximo3(int a, int b, int c){
    return maximo(maximo(a,b), c);
}

int maximaSumaCruzada(int *arr, int ini, int med, int fin){
    int sum = 0;
    int sumIzq = -9999;
    for(int i = med; i >= ini; i--){
        sum += arr[i];
        if(sum >= sumIzq)
            sumIzq = sum;
    }
    sum = 0;
    int sumDer = -9999;
    for(int i = med+1; i <= fin; i++){
        sum += arr[i];
        if(sum > sumDer)
            sumDer = sum;
    }
    return maximo3(sumIzq+sumDer, sumIzq, sumDer);
}

int maximaSuma(int *arr, int ini, int fin){
    if(ini == fin) return arr[ini];
    int med = (ini+fin)/2;
    return maximo3(maximaSuma(arr, ini, med), 
            maximaSuma(arr, med+1, fin), 
            maximaSumaCruzada(arr, ini, med, fin));
}

int main(int argc, char** argv) {

    int arr[] = {-2,-5,6,-2,-3,1,5,-6};
    int n = 8;
    
    cout << maximaSuma(arr, 0, n-1);
    
    return 0;
}

