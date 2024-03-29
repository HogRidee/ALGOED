/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 28 de marzo de 2024, 15:57
 */

#include <iostream>
#define MAXCOL 5
#define MAXFIL 4

using namespace std;

int mov[8][2];

void movimientos(){
    mov[0][0] = -1; mov[0][1] = 0;
    mov[1][0] = -1; mov[1][1] = 1;
    mov[2][0] = 0; mov[2][1] = 1;
    mov[3][0] = 1; mov[3][1] = 1;
    mov[4][0] = 1; mov[4][1] = 0;
    mov[5][0] = 1; mov[5][1] = -1;
    mov[6][0] = 0; mov[6][1] = -1;
    mov[7][0] = -1; mov[7][1] = -1;
}

int busca (char tablero[][MAXCOL], char palabra[], int row, int col, int n,
        char tableroVacio[][MAXCOL]){
    int nrow, ncol, j;
    if (tablero[row][col] != palabra[0]){
        return 0;
    }
    
    for (int i = 0; i < 8; i++){
        nrow = row + mov[i][0];
        ncol = col + mov[i][1];
        for (j = 1; j < n; j++){
            if (ncol < 0 or nrow < 0 or ncol >= MAXCOL or nrow >= MAXFIL){
                break;
            }
            if (tablero[nrow][ncol] != palabra[j]){
                break;
            }
            nrow = nrow + mov[i][0];
            ncol = ncol + mov[i][1];
        }
        if (j == n){
            tableroVacio[row][col] = tablero[row][col];
            for(int k = 1; k < n; k++){
                row = row + mov[i][0];
                col = col + mov[i][1];
                tableroVacio[row][col] = tablero[row][col];
            }
            return 1;
        }
    }
    return 0;
}

void pupiletras (char palabra[], char tablero[][MAXCOL], int m, 
        char tableroVacio[][MAXCOL]){
    for (int i = 0; i < MAXFIL; i++){
        for (int j = 0; j < MAXCOL; j++){
            if (busca(tablero, palabra, i, j, m, tableroVacio)){
                cout << "Encontre la palabra en " << i << " " << j << " " << 
                        endl;
            }
        }
    }
}

int main(int argc, char** argv) {
    
    char tablero[][MAXCOL] = {
        {'H', 'H', 'T', 'O', 'H'},
        {'O', 'L', 'O', 'L', 'O'},
        {'L', 'B', 'O', 'L', 'L'},
        {'A', 'A', 'T', 'L', 'A'}
    };
    char tableroVacio[][MAXCOL] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };
    int m = 4;
    char palabra[] = {'H', 'O', 'L', 'A'};
    
    movimientos();
    
    pupiletras(palabra, tablero, m, tableroVacio);
    
    for(int i = 0; i < MAXFIL; i++){
        for(int j = 0; j < MAXCOL; j++){
            cout << tableroVacio[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

