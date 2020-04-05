/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: apala
 *
 * Created on 31 marzo 2020, 17.45
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define R 100
#define C 100
using namespace std;

/*
 * 
 */
void ChiediDimensioni(char *, int *);
void NumSDP(int*, int);
void Input(int[][C], int);
bool Controllo(int[][C], int, int);
void Output(char *, int[][C], int);
int main() {
    int dim;
    int Mat[R][C];
    int nsdp = 0;
    char msg[64];
    snprintf(msg, 64, "Inserire dimensioni della matrice: ");
    ChiediDimensioni(msg, &dim);
    NumSDP(&nsdp, dim);
    Input(Mat, dim);
    if(Controllo(Mat, dim, nsdp))
        cout << endl << "La matrice è una matrice quadrata triangolare superiore" << endl;
    else
        cout << endl << "La matrice non è una matrice quadrata triangolare superiore" << endl;
    snprintf(msg, 64, "Stampa della Matrice:");
    Output(msg, Mat, dim);
    return 0;
}
void ChiediDimensioni(char *msg, int *dim){
    cout << msg << endl;
    bool cont;
    do{
        cont = 1;
        cout << "Inserire il numero di righe e di colonne della matrice ( 0 < n < 100): ";
        cin >> *dim;
        if(*dim > 0 && *dim < 100)
            cont = 0;
        else
            cout << "La dimensione delle righe e delle colonne inserita non è corretta!\n Il numero inserito deve essere maggiore di 0 e minore di 100\nRiprova!" << endl;
    }while(cont);
}
void NumSDP(int *n, int dim){
    int nd = dim - 1;
    for(short i = 0; i < dim; i++){
      *n += nd - i;
    }
}
bool Controllo(int m[][C], int d, int nsdp){
    int temp = 0;
    short c = 0;
    for(short i = 0; i < d; i++){
        for(short j = i + 1; j < d; j++){
            if(m[j][i] == 0)
                c++;
        }
    }
    if(c == nsdp)
        return 1;
    else 
        return 0;
}
void Input(int m[][C], int d){
    for(short i = 0; i < d; i++){
        for(short j = 0; j < d; j++){
            cout << "Inserire numero nella cella " << i << "||" << j << " della matrice:";
            cin >> m[i][j];
        }
    }
}
void Output(char *msg, int m[][C], int d){
    cout << endl << msg << endl;
    for(short i = 0; i < d; i++){
        for(short j = 0; j < d; j++){
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}