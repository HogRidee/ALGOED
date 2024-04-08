/* 
 * File:   main.cpp
 * Author: Ivan
 *
 * Created on 7 de abril de 2024, 17:33
 */

#include <iostream>

using namespace std;

void imprimirAnaquel(int anaquel[][5], int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            cout << anaquel[i][j] << " ";
        }
        cout << endl;
    }
}

void llenarAnaquel(int matriz[][5], int f, int c, int p, int num){
    if(p <= 0) return;
    if(c%2 != 0){
        for(int i = 0;i <= (num/2);i++){
            if(matriz[f][(c/2)+i] == 0 && p>0){
                matriz[f][(c/2)+i] = 5;
                p--;
            }
            if(matriz[f][(c/2)-i] == 0 && p>0){
                matriz[f][(c/2)-i] = 5;
                p--;
            }
        }
    }
    else{
        int a=c/2;
        int b=c/2-1;
        for(int i=0;i<=(num/2);i++){
            if(matriz[f][a+i]==0 && p>0){
                matriz[f][a+i]=5;
                p--;
            }
            if(matriz[f][b-i]==0 && p>0){
                matriz[f][b-i]=5;
                p--;
            }
        }
    }
    llenarAnaquel(matriz, f+1, c, p, num+2);
}

int main(int argc, char** argv) {

    int f = 5;
    int c = 5;
    int p = 16;
    int inicio = 1;
    
    int matriz[][5]{{0,0,0,0,0},
                   {0,0,0,0,0},
                   {0,0,0,1,0},
                   {0,1,0,0,0},
                   {0,0,0,0,0}
    };
    
    llenarAnaquel(matriz, 0, c, p, inicio);
    imprimirAnaquel(matriz, f, c);
    
    return 0;
}

