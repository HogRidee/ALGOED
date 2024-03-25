/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 25 de marzo de 2024, 11:04 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int robot(int x, int y, int n, int m, int tablero[][3]){
    int derecha = -999999, abajo = -999999;
    
    if (x == n-1 and y == m-1) return tablero[x][y];
    
    if (y+1 < m){
        derecha = robot(x, y+1, n, m, tablero);
    }
    if (x+1 < n){
        abajo = robot(x+1, y, n, m, tablero);
    }
    
    if (derecha > abajo){
        return derecha + tablero[x][y];
    }
    return abajo + tablero[x][y];   
}

int main(int argc, char** argv) {

    int n = 3, m = 3;
    int tablero[][3] = { {3, 8, 6},
                         {3, 10, 2},
                         {0, 9, 1}};
    
    cout << "El resultado es: " << robot(0, 0, n, m, tablero) << endl;
    
    return 0;
}

