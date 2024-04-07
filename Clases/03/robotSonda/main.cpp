/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 6 de abril de 2024, 17:51
 */

#include <iostream>

using namespace std;

int mapa[][6] = {{0,0,0,1,0,1},
                 {0,0,1,0,0,0},
                 {0,1,0,0,0,1},
                 {1,0,0,0,0,0},
                 {0,1,0,0,0,0},
                 {0,0,0,0,1,0}
};

/*
 derecha: 0,1
 izquierda: 0,-1
 abajo: 1,0
 arriba: -1,0
 */

// 50:40
int busca(int x, int y, int mx, int my, int flagx, int flagy, int n, int m){
    int contador = 0;
    if(x >= n or y >= m or x < 0 or y < 0) return 0;
    if(mapa[x][y] and flagx == 0 and flagy == 0) contador++;
    // movimiento en filas
    if(flagx == 0){
        for(int i = x+1; i < n; i++)
            contador += mapa[i][y];
        for(int i = 0; i < x; i++)
            contador += mapa[i][y];
    }
    // movimiento en columnas
    if(flagy == 0){
        for(int i = y+1; i < m; i++)
            contador += mapa[x][i];
        for(int i = 0; i < y; i++)
            contador += mapa[x][i];
    }
    contador += busca(x+mx, y+my, mx, my, mx, my, n, m);
    return contador;
}

int main(int argc, char** argv) {
    int n = 6, m = 6;
    int x = 3, y = 2;
    
    cout << busca(x, y, 0, 1, 0, 0, n, m);
    
    return 0;
}

