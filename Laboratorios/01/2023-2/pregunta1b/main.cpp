/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 30 de marzo de 2024, 9:31
 */

#include <iostream>
#define MAXFIL 4
#define MAXCOL 10

using namespace std;

int mov[4][2];

void movimientos(){
    mov[0][0] = -1; mov[0][1] = 0;
    mov[1][0] = 0; mov[1][1] = 1;
    mov[2][0] = 1; mov[2][1] = 0;
    mov[3][0] = 0; mov[3][1] = -1;
}

bool busca(char tablero[][MAXCOL], char palabra[], int n, int row, int col){
    int nrow, ncol, j = 0;
    bool encontrado = false;
    char c[4] = {'X', 'X', 'X'};
    for (int k = 0; k < 3; k++){
        if(tablero[row][col] == palabra[k] && c[k] == 'X'){
            encontrado = true;
            c[k] = tablero[row][col];
            break;
        }
    }
    if (!encontrado) return false;
    for (int i = 0; i < 4; i++){
        nrow = row + mov[i][0];
        ncol = col + mov[i][1];
        for (j = 1; j < n; j++){
            if(ncol < 0 or nrow < 0 or ncol >= MAXCOL or nrow >= MAXFIL)
                break;
            encontrado = false;
            for(int k = 0; k < 3; k++){
                if(tablero[nrow][ncol] == palabra[k] && c[k] == 'X'){
                    encontrado = true;
                    c[k] = tablero[nrow][ncol];
                    break;
                }
            }
            if(!encontrado)break;
            nrow = nrow + mov[i][0];
            ncol = ncol + mov[i][1];
        }
        if(j == n) return true;
    }
    return false;
}

void robotMarinero(char tablero[][MAXCOL], char palabra[], int n){
    for (int i = 0; i < MAXFIL; i++){
        for (int j = 0; j < MAXCOL; j++){
            if(busca(tablero, palabra, n, i, j)){
                cout << i << ", " << j << "    ";
            }
        }
    }
}

int main(int argc, char** argv) {

    char tablero[][MAXCOL] = {
        {'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H'},
        {'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K'},
        {'O', 'P', 'N', 'Y', 'O', 'K', 'F', 'H', 'C', 'K'},
        {'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'},
    };
    movimientos();

    int n = 3;
    char palabra[] = {'H', 'S', 'O'};

    robotMarinero(tablero, palabra, n);

    return 0;
}

