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
// branch prova
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <windows.h>
//#define DEBUG //scommentare questa riga per tutto il debug
typedef struct M{
    bool M_OTTO [8][8];
    bool M_CL[8][8];
    int M_CORD [10][4];
}cord;

using namespace std;


void RiempiM(cord *, cord *);
void StampaM(cord *);
void GenP(cord *);
void CMPIns(cord *, char *, int *);
void M(cord *, cord *);
bool CMPR(cord *, short, short);
bool CMPC(cord *, short, short);
bool CMPD(cord *, short, short);
bool CMPDS(cord *, short, short);
bool InsUt(cord *); // utente
void InsFRC(cord *);// utente
void Sfida(cord *, cord *);
bool Chiedi();
void SM(cord *, cord*);
bool InsCPU(cord *);
int main(int argc, char** argv) {
    cord gioco;
    cord utente;
    SM(&gioco, &utente);
    return 0;
}
void SM(cord *g, cord *u){
    fflush(stdin);
    Sfida(g, u);
}
void M(cord *g, cord *u){
    cout << "Sto calcolando ...." << endl;
    char msg[64];
    int fun[3] = {0, 0, 0};
    do{
        fun[0] = 0;
        RiempiM(g, u);
        srand(time(NULL));
        GenP(g);
        CMPIns(g, msg, fun);
        fun[2] = fun[2] + 1;
    }while(fun[0] < 6);
    //StampaM(g, msg);
}
void RiempiM(cord *g, cord *u){
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            g->M_OTTO[i][j] = 0;
        }
    }
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            u->M_OTTO[i][j] = 0;
        }
    }
    /*
    for(short i = 0; i < 10; i++){
        for(short j = 0; j < 2; j++){
            g->M_CORD[i][j] = 0;
        }
    }
    */
}
void StampaM(cord *g){
    cout << endl << "Matrice del vincitore: \n" << endl;
    for(short i = 0; i < 8; i++){
        for(short j = 0; j < 8; j++){
            cout << "\t" << g->M_OTTO[i][j];
        }
        cout << endl;
    }
#ifdef DEBUG
    //cout << "Cordinate CELLE RIEMPITE: \nOrdine \tCordX \tCordY" << endl;
    //for(short i = 0; i < 7; i++){
      //      cout << i << " \t" << g->M_CORD[i][0] << " \t" << g->M_CORD[i][1] << endl;
    //}
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
void CMPIns(cord *g, char *msg, int *fun){
    short mx = 0;
    short my = 0;
    short cond = 0;
    short cmpr = 0;
    short cmpd = 0;
    short cmpc = 0;
    short cmpds = 0;
    int out = 0;
    for(short k = 0; k < 6; k++){
            cond = 0;
    #ifdef DEBUG
            cout << "Cella n: " << k + 1 << endl;
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
                        fun[0] = fun[0] + 1;
                        g->M_OTTO[mx][my] = 1;
                        g->M_CORD[k + 1][0] = mx;
                        g->M_CORD[k + 1][1] = my;
    #ifdef DEBUG      
                        cout << endl << endl << "CELLA "<< k + 1  << " RIEMPITA CORRETAMENTE CON CORDINATE\t" << mx << "||" << my << endl << endl;
    #endif
                        break;
                    }
                }
            }
    }
#ifdef DEBUG
    cout << "Valore contatore dei controlli fun[0]: " << fun[0] << endl;
#endif
    if(fun[2] == 1){
        snprintf(msg, 64, "La matrice è stata riempita con successo al primo tentativo!");
    }
    else{
        out = fun[2] + 1;
        snprintf(msg, 64, "La matrice è stata riempita con successo dopo %d tentativi", out);
    }
}

bool CMPR(cord *g, short r, short c){ //controllo riga
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
bool CMPC(cord *g, short r, short c){ // controllo colonna
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
bool CMPD(cord *g, short r, short c){ //controllo diagonale con orientamento uguale alla principale
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
    cont = 0;
    d = 0;
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
            for(short i = dxi, j = dyi; i < 7; i++, j++){
                if(g->M_OTTO[i][j] == 0)
                    cont = cont + 1;
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif 
            if(cont > (d - 1))
                return 1;
            else
                return 0;
            break;
        case 2:
            dxi = dyi = 0;
            dxf = dyf = 7;
            for(short i = 0; i < 8; i++){
                if(g->M_OTTO[i][i] == 0){
                    cont ++;
                }
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont > 7)
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
            for(short i = dxi, j = dyi; j < 7; i++,j++){
                if(g->M_OTTO[i][j] == 0)
                    cont++;
            }
#ifdef DEBUG
            cout <<"\tPOS: " << pos << "\tCont: " << cont << "\tDXI: " << dxi <<"\tDYI: " << dyi << "\tDXF: " << dxf <<"\tDYF: " << dyf << endl;
#endif
            if(cont > (d - 1))
                return 1;
            else
                return 0;
            break;
    }
}
bool CMPDS(cord *g, short r, short c){ // controllo diagonale con orientamento uguale a la diagonale secondaria
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
            if(cont > (d - 1))
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
            if(cont > 7)
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
            if(cont > (d - 1))
                return 1;
            else
                return 0;
    }
    
}
bool InsUt(cord *g){ //utente , vuole u come parametro attuale
    int mx = 0;
    int my = 0;
    bool cmp;
    cout << "Riempi una cella !\nLe posizioni inziano da 1 e finiscono ad 8" << endl;
    do{
        cmp = 1;
        cout << "Inserire cordinata della riga che vuoi popolare: ";
        fflush(stdin);
        cin >> mx;
        if( mx >= 1 && mx <= 8)
            cmp = 0;
        else{
            cout << "La cordinata della riga inserita non è valida! \nLe posizioni inziano da 1 e finiscono ad 8 ! " << endl;
        }
    }while(cmp);
    do{
        cmp = 1;
        cout << "Inserire cordinata della colonna che vuoi popolare: ";
        fflush(stdin);
        cin >> my;
        if( my >= 1 && my <= 8)
            cmp = 0;
        else{
            cout << "La cordinata della colonna inserita non è valida! \nLe posizioni inziano da 1 e finiscono ad 8 ! " << endl;
        }
    }while(cmp);
    mx--;
    my--;
    if(CMPR(g,  mx, my) && CMPC(g, mx, my) && CMPD(g, mx, my) && CMPDS(g, mx, my)){
        g->M_OTTO[mx][my] = 1;
        return 1;
    }
    else{
        return 0;
    }

}
void InsFRC(cord *g){
    int mx = 0;
    int my = 0;
    bool cmp;
    cout << "\nInserire cordinate della prima cella che vuoi popolare -non puoi sbagliare :)-!\nLe posizioni inziano da 1 e finiscono ad 8" << endl;
    do{
        cmp = 0;
        cout << "Inserire cordinata della riga che vuoi popolare: ";
        fflush(stdin);
        cin >> mx ;
        if( mx < 1 || mx > 8){
            cmp = 1;
            cout << "La cordinata della riga inserita non è valida! \nLe posizioni inziano da 1 e finiscono ad 8 ! " << endl;
        }
    }while(cmp);
    do{
        cmp = 1;
        cout << "Inserire cordinata della colonna che vuoi popolare: ";
        fflush(stdin);
        cin >> my;
        if( my >= 1 && my <= 8)
            cmp = 0;
        else{
            cout << "La cordinata della colonna inserita non è valida! \nLe posizioni inziano da 1 e finiscono ad 8 ! " << endl;
        }
    }while(cmp);
    mx--;
    my--;
    g->M_OTTO[mx][my] = 1;
}
void Sfida(cord *g, cord *u){
    srand(time(NULL));
    int puntU = 1;
    int puntC = 1;
    int tent = 0;
    bool cmp = 1;
    short turno = 1;
    RiempiM(g, u);
    srand(time(NULL));
    GenP(g); 
    InsFRC(u); 
    do{
        cout << endl << "Turno n°: " << turno << endl;
        turno++;
        cout <<  endl << "Punti utente: " << puntU << " || Punti cpu: " << puntC << " || Tentativi: " << (tent + 1) << "\nCelle rimanenti all' utente:  " << (7 - puntU) << " || Celle rimanenti alla cpu: " << (7 - puntC) << endl; 
        if(InsUt(u)){
            cout << "Hai guadagnato un punto! " << endl;
            puntU++;
        }
        else if (Chiedi()){
            cmp = 1;
            tent ++;
        }
        else{
            cmp = 0;
        }
        if(InsCPU(g)){
            cout << "La cpu ha guadagnato un punto!" << endl;
            puntC++;
        }
        else{
            cout << "La cpu ha sbagliato !" << endl;
        }
    }while(puntU < 7 && puntC < 7 && cmp);
    if(puntU >= 7){
        cout << "Hai vinto!, Tentativi utilizzati: " << tent << endl;
        StampaM(u);
    }
    else if (puntC >= 7){
        cout << "Hai perso, la cpu ti ha battuto ! " << endl;
        StampaM(g);
    }
    else if (!cmp){
        cout << "Ti sei arreso! Punti effettuati: " << puntU << " || Tentativi utilizzati: " << tent << endl;
    }
}
bool Chiedi(){
    char ris[5];
    bool cris;
    cout << "Hai sbagliato !" << endl;
    do{
        cris = 0;
        cout << "Vuoi continuare(si/no) ? **Ripartirai da dove ti sei fermato e verrà aggiunto un tentativo**\n";
        fflush(stdin);
        cin >> ris;
        system("Sleep 0.1");
        if(!strcmp(ris,"si") || !strcmp(ris,"Si") || !strcmp(ris,"SI") ||  !strcmp(ris,"sì") || !strcmp(ris,"Sì") || !strcmp(ris,"S") || !strcmp(ris,"s") || !strcmp(ris,"NO") || !strcmp(ris,"no") || !strcmp(ris,"n") || !strcmp(ris,"N")|| !strcmp(ris,"No") )
        {
            cris = 0;
        }     
        else{
            cout << endl <<  "Risposta non valida" << endl;
            cris = 1;
        }
    }while(cris);
    if(!strcmp(ris,"si") || !strcmp(ris,"Si") || !strcmp(ris,"SI") ||  !strcmp(ris,"sì") || !strcmp(ris,"Sì") || !strcmp(ris,"S") || !strcmp(ris,"s")){
        return 1;
    }
    else{
        return 0;
    }

}
bool InsCPU(cord *g){
    int mx = rand() % 7;
    int my = rand() % 7;
    if(CMPR(g,  mx, my) && CMPC(g, mx, my) && CMPD(g, mx, my) && CMPDS(g, mx, my)){
        g->M_OTTO[mx][my] = 1;
        return 1;
    }
    else
        return 0;   
}