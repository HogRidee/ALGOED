/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 25 de marzo de 2024, 10:34 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void triangulo(int a, int b){
    if (a > b) return;
    
    for (int i = 0; i < a; i++){
        cout << "*";
    }
    cout << endl;
    triangulo(a+1, b);
    
    for (int i = 0; i < a; i++){
        cout << "*";
    }
    cout << endl;
}

int main(int argc, char** argv) {

    triangulo(3, 5);
    
    return 0;
}

