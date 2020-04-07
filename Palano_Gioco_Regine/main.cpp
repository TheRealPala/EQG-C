/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: apala
 *
 * Created on 30 marzo 2020, 9.55
 */

/*
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
typedef struct M{
    bool M_OTTO [8][8];
    int M_CORD [8][2];
}cord;

using namespace std;


void RiempiM(cord *);
void StampaM(cord *);
void GenP(cord*);
void CMPIns(cord*);
void M(cord*);
bool CMPR(cord*, short, short);
bool CMPC(cord*, short, short);
bool CMPD(cord*, short, short);
int main(int argc, char** argv) {
    srand(time(NULL));
    cord gioco;
    M(&gioco);
    return 0;
}
void M(cord *g){
    RiempiM(g);
    GenP(g);
    CMPIns(g);
    StampaM(g);
}
void RiempiM(cord *g){
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            g->M_OTTO[i][j] = 0;
        }
    }
}
void StampaM(cord *g){
    cout << "Matrice Riempita:" << endl;
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            cout << "\t" << g->M_OTTO[i][j];
        }
        cout << endl;
    }
}
void GenP(cord *g){
    short gx = rand() % 7;
    short gy = rand() % 7;
    g->M_CORD[0][0] = gx;
    g->M_CORD[0][1] = gy;
    g->M_OTTO[gx][gy] = 1;
    cout << "Cella generata: " << gx << "||" << gy << endl;
}
void CMPIns(cord *g){
    short mx = 0;
    short my = 0;
    int cond = 0;
    int cmpr = 0;
    int cmpd = 0;
    int cmpc = 0;
    for(short i = 0; i < 8; i++){
        cond = 0;
        cout << "Cella n: " << i << endl;
        for(mx = 0; mx < 7; mx++){
            if (cond == 3){
                break;
            }
            for(my = 0; my < 7; my++){
                cout << "Posizione Controllata: " << mx <<"||" << my << endl;
                cmpr = CMPR(g, mx, my);
                cmpd = CMPD(g, mx, my);
                cmpc = CMPC(g, mx, my);
                cond = cmpr + cmpd + cmpc;
                if(cond == 3){
                    g->M_OTTO[mx][my] = 1;
                    cout << "CELLA "<< mx << " RIEMPITA CORRETAMENTE" << endl;
                    break;
                }
            }
        }
    }
}
bool CMPR(cord *g, short r, short c){
    short cont = 0;
    cout << "CMPR: ";
    for(short i = 0; i < 8; i++){
        if(g->M_OTTO[r][i] == 0)
            cont++;
    }
    cout << cont << endl;
    if(cont == 8)
        return 1;
    else
        return 0;
}
bool CMPC(cord *g, short r, short c){
    short cont = 0;
    cout << "CMPC: ";
    for(short i = 0; i < 8; i++){
        if(g->M_OTTO[i][c] == 0)
            cont++;
    }
    cout << cont << endl;
    if(cont == 8)
        return 1;
    else
        return 0;
}
bool CMPD(cord *g, short r, short c){
    cout << "CMPD: ";
    short pos = 0; //1 se è sotto la DP, 2 se è nella DP, 3 se è sopra la DP
    short cont = 0;
    short dxi = r;
    short dyi = c;
    short dxf = r;
    short dyf = c;
    short d = 0;
    if(c < r)
        pos = 1;
    else if (c > r)
        pos = 3;
    else if (c == r)
        pos = 2;
    switch(pos){
        case 1:
            for(short i = c; i > 0; i-- ){
                dxi--;
                dyi--;
            }
            for(short i = r; i < 7; i++ ){
                dxf++;
                dyf++;
            }
            d = dxf - dxi;
            for(short i = dxi, j = dyi; i < d; i++){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
            if(cont == d)
                return 1;
            else
                return 0;
            break;
        case 2:
            for(short i = 0; i < 8; i++){
                if(g->M_OTTO[i][i] == 0){
                    cont ++;
                }
            }
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
            if(cont == 8)
                return 1;
            else{
                return 0;
            }
            break;
        case 3:
            for(short i = r; i > 0; i--){
                dxi--;
                dyi--;
            }
            for(short i = c; i < 7; i++){
                dxf++;
                dyf++;
            }
            d = dyf - dxi;
            for(short i = dxi, j = dyi; i < d; i++){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
            if(cont == d)
                return 1;
            else
                return 0;
            break;
    }
}
 */ 

 
 
//CODEBLOCK CODE
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#define DEBUG //scommentare questa riga per tutto il debug
typedef struct M{
    bool M_OTTO [8][8];
    int M_CORD [10][2];
}cord;

using namespace std;


void RiempiM(cord *);
void StampaM(cord *);
void GenP(cord *);
void CMPIns(cord *);
void M(cord *);
bool CMPR(cord *, short, short);
bool CMPC(cord *, short, short);
bool CMPD(cord *, short, short);
bool CMPDS(cord *, short, short);
int main(int argc, char** argv) {
    srand(time(NULL));
    cord gioco;
    M(&gioco);
    return 0;
}
void M(cord *g){
    RiempiM(g);
    GenP(g);
    CMPIns(g);
    StampaM(g);
}
void RiempiM(cord *g){
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            g->M_OTTO[i][j] = 0;
        }
    }
}
void StampaM(cord *g){
    cout << "Matrice Riempita:" << endl;
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            cout << "\t" << g->M_OTTO[i][j];
        }
        cout << endl;
    }
#ifdef DEBUG
    cout << "Cordinate CELLE RIEMPITE: \nOrdine \tCordX \tCordY" << endl;
    for(short i = 0; i < 8; i++){
            cout << i + 1 << " \t" << g->M_CORD[i][0] << " \t" << g->M_CORD[i][1] << endl;
    }
#endif
}
void GenP(cord *g){
    short gx = rand() % 6;
    short gy = rand() % 6;
    g->M_CORD[0][0] = gx;
    g->M_CORD[0][1] = gy;
    g->M_OTTO[gx][gy] = 1;
#ifdef DEBUG
    cout << "Cella generata: " << gx << "||" << gy << endl;
#endif
}
void CMPIns(cord *g){
    short mx = 0;
    short my = 0;
    int cond = 0;
    int cmpr = 0;
    int cmpd = 0;
    int cmpc = 0;
    int cmpds = 0;
    for(short i = 0; i < 7; i++){
        cond = 0;
#ifdef DEBUG
        cout << "Cella n: " << i << endl;
#endif
        for(mx = 0; mx < 8; mx++){
            if (cond == 4){
                break;
            }
            for(my = 0; my < 8; my++){
#ifdef DEBUG
                cout << "Posizione Controllata: " << mx <<"||" << my << endl;
#endif
                cmpr = CMPR(g, mx, my);
                cmpd = CMPD(g, mx, my);
                cmpc = CMPC(g, mx, my);
                cmpds = CMPDS(g, mx, my);
                cond = cmpr + cmpd + cmpc + cmpds;
                if(cond == 4){
                    g->M_OTTO[mx][my] = 1;
                    g->M_CORD[i + 1][0] = mx;
                    g->M_CORD[i + 1][1] = my;
#ifdef DEBUG
                    cout << endl << endl << "CELLA "<< mx << " RIEMPITA CORRETAMENTE CON CORDINATE\t" << mx << "||" << my << endl << endl;
#endif
                    //system ("color 0F");
                    break;
                }
            }
        }
    }
}
bool CMPR(cord *g, short r, short c){
    short cont = 0;
#ifdef DEBUG
    cout << "CMPR: ";
#endif
    for(short i = 0; i < 8; i++){
        if(g->M_OTTO[r][i] == 0)
            cont++;
    }
#ifdef DEBUG
    cout << cont << endl;
#endif
    if(cont == 8)
        return 1;
    else
        return 0;
}
bool CMPC(cord *g, short r, short c){
    short cont = 0;
#ifdef DEBUG
    cout << "CMPC: ";
#endif
    for(short i = 0; i < 8; i++){
        if(g->M_OTTO[i][c] == 0)
            cont++;
    }
#ifdef DEBUG
    cout << cont << endl;
#endif
    if(cont == 8)
        return 1;
    else
        return 0;
}
bool CMPD(cord *g, short r, short c){
#ifdef DEBUG
    cout << "CMPD: ";
#endif 
    short pos = 0; //1 se è sotto la DP, 2 se è nella DP, 3 se è sopra la DP
    short cont = 0;
    short dxi = r;
    short dyi = c;
    short dxf = r;
    short dyf = c;
    short d = 0;
    if(c < r)
        pos = 1;
    else if (c > r)
        pos = 3;
    else if (c == r)
        pos = 2;
    switch(pos){
        case 1:
            for(short i = c; i > 0; i-- ){
                dxi--;
                dyi--;
            }
            for(short i = r; i < 7; i++ ){
                dxf++;
                dyf++;
            }
            d = dxf - dxi;
            for(short i = dxi, j = dyi; i <= d; i++, j++){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif 
            if(cont >= d)
                return 1;
            else
                return 0;
            break;
        case 2:
            dxi = dyi = 0;
            for(short i = 0; i < 8; i++){
                if(g->M_OTTO[i][i] == 0){
                    cont ++;
                }
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont >= 8)
                return 1;
            else{
                return 0;
            }
            break;
        case 3:
            for(short i = r; i > 0; i--){
                dxi--;
                dyi--;
            }
            for(short i = c; i < 7; i++){
                dxf++;
                dyf++;
            }
            d = dyf - dyi;
            for(short i = dxi, j = dyi; i < d; i++,j++){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont >= d)
                return 1;
            else
                return 0;
            break;
    }
}
bool CMPDS(cord *g, short r, short c){
#ifdef DEBUG
    cout << "CMPDS: ";
#endif
    short pos = 0;
    short src = r + c; // 1 se sopra ds, 2 se sulla ds, 3 se sotto ds
    short cont = 0;
    short dxi = r;
    short dyi = c;
    short dxf = r;
    short dyf = c;
    short d = 0;
    if(src < 7)
        pos = 1;
    else if(src > 7)
        pos = 3;
    else
        pos = 2;
    switch(pos){
        case 1:
             for(short i = r; i > 0; i-- ){
                dxi--;
                dyi++;
            }
            for(short i = c; i > 0; i-- ){
                dxf++;
                dyf--;
            }
            d = dxf - dxi;
            for(short i = dxi, j = dyi; j > 0; i++, j--){
                if(g->M_OTTO[i][j] == 0){
                    cont++;
                }
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont >= d)
                return 1;
            else
                return 0;
            break;
        case 2:
            for(short i = 0, j = 7; i < 8; i++, j--){
                if(g->M_OTTO[i][j] == 0){
                    cont ++;
                }
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont >= 8)
                return 1;
            else{
                return 0;
            }
            break;
        case 3:
            for(short i = c; i < 7; i++ ){
                dxi--;
                dyi++;
            }
            for(short i = r; i < 7; i++ ){
                dxf++;
                dyf--;
            }
            d = dxf - dxi;
            for(short i = dxi, j = dyi; i < 7; i++, j-- ){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont >= d)
                return 1;
            else
                return 0;
    }
    
}
 