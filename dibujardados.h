#ifndef DIBUJARDADOS_H_INCLUDED
#define DIBUJARDADOS_H_INCLUDED

#include <iostream>
#include "rlutil.h"
#include "interfaz.h"
#include "dibujardados.h"

const char *top = "▀";
const char *bottom = "▄";
const char *space = " ";

void dibujarUno(int posx, int posy) {
    dibujarLineaU(posx+3,posy+1,1, top);
}

void dibujarDos(int posx, int posy) {
    dibujarLineaU(posx+1,posy,1, bottom);
    dibujarLineaU(posx+5,posy+1,1, bottom);
}

void dibujarTres(int posx, int posy) {
    dibujarUno(posx, posy);
    dibujarDos(posx, posy);
}

void dibujarCuatro(int posx, int posy) {
    dibujarDos(posx, posy);
    dibujarLineaU(posx+5,posy,1, bottom);
    dibujarLineaU(posx+1,posy+1,1, bottom);
}

void dibujarCinco(int posx, int posy) {
    dibujarUno(posx, posy);
    dibujarCuatro(posx, posy);
}

void dibujarSeis(int posx, int posy) {
    dibujarCuatro(posx, posy);
    dibujarLineaU(posx+3,posy,1, bottom);
    dibujarLineaU(posx+3,posy+1,1, bottom);
}

void elegirNumero(int posx, int posy, int num) {
    switch (num) {
        case 1:
            dibujarUno(posx, posy);
            break;
        case 2:
            dibujarDos(posx, posy);
            break;
        case 3:
            dibujarTres(posx, posy);
            break;
        case 4:
            dibujarCuatro(posx, posy);
            break;
        case 5:
            dibujarCinco(posx, posy);
            break;
        case 6:
            dibujarSeis(posx, posy);
            break;
    }
}

void dibujarSombraDado(int posx, int posy) {
    ponerColores(rlutil::CYAN, rlutil::BLACK);
    dibujarLineaU(posx,posy+2,1,bottom);

    ponerColores(rlutil::CYAN, rlutil::BLUE);
    dibujarLineaU(posx+1,posy+2,6,bottom);

    ponerColores(rlutil::BLACK, rlutil::BLUE);
    dibujarLineaU(posx+7,posy,1,bottom);

    rlutil::setBackgroundColor(rlutil::BLUE);
    dibujarLineaU(posx+7,posy+1,1, space);
    dibujarLineaU(posx+7,posy+2,1, space);
}

void dibujarFormaDado(int posx, int posy) {
    rlutil::setBackgroundColor(rlutil::CYAN);
    dibujarLineaU(posx,posy,7  , space);
    dibujarLineaU(posx,posy+1,7, space);
    dibujarLineaU(posx,posy+2,7, space);
}

void dibujarDado(int posx, int posy, int num) {
    dibujarFormaDado(posx, posy);
    dibujarSombraDado(posx, posy);
    ponerColores(rlutil::CYAN, rlutil::BLACK);
    elegirNumero(posx, posy, num);
    ponerColores(rlutil::BLACK, rlutil::WHITE);
}

void dibujarDados(int posx, int posy, int vec[], int cantDados) {
    int espacioParaDado=rlutil::tcols()/(cantDados*3);
    int gap = 5;
    for (int i=0; i<cantDados; i++) {
        int inicioEspacio = posx + (espacioParaDado+7) * i;
        int posXdado = (rand()% espacioParaDado) + gap + inicioEspacio;
        int posYdado = rand()%5 + posy;
        dibujarDado(posXdado, posYdado, vec[i]);
    }
}

void borrarDados() {
    for (int i=9; i<18; i++) {
        dibujarLineaU(1,i,rlutil::tcols()-5, space);
    }
}

#endif // DIBUJARDADOS_H_INCLUDED