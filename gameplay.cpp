#include <iostream>
#include <string>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "gameplay.h"
#include "dibujardados.h"

std::string ingreseNombre(char numJugador) {
    std::string nombreJug;
    if (numJugador==0) {
        std::cout << "Ingrese nombre del jugador: ";
    }
    else {
        std::cout << "Ingrese nombre del jugador " << numJugador << ": ";
    }
    std::cin >> nombreJug;

    return nombreJug;
}

int comprobarMas3Num(int vec[], int tam, int puntaje) {
    int maximo=0;
    for (int i=0; i<tam; i++) {
        if ((vec[i]>=3) && (i+1>maximo)) {
            maximo=i+1;
        }
    }
    if (maximo!=0) {
        return maximo*puntaje;
    }
    else {
        return 0;
    }
}

int comprobarCantDado(int vec[], int pos, int cant, int puntaje) {
    if (vec[pos-1]==cant) {
        return puntaje;
    }
    else {
        return 0;
    }
}

int comprobarEscalera(int vec[], int tam, int puntaje) {
    if (!hayCeros(vec,tam)) {
        return puntaje;
    }
    else {
        return 0;
    }
}

int sacarPuntaje(int vec[], int tam) {
    int puntajeObtenido[10];
    puntajeObtenido[0]=comprobarCantDado(vec, 1, 6, 10000);
    puntajeObtenido[1]=comprobarCantDado(vec, 1, 5, 2000);
    puntajeObtenido[2]=comprobarCantDado(vec, 1, 4, 2000);
    puntajeObtenido[3]=comprobarEscalera(vec, tam, 1500);
    puntajeObtenido[4]=comprobarCantDado(vec, 1, 3, 1000);
    puntajeObtenido[5]=comprobarMas3Num(vec, tam, 100);
    puntajeObtenido[6]=comprobarCantDado(vec, 1, 2, 200);
    puntajeObtenido[7]=comprobarCantDado(vec, 1, 1, 100);
    puntajeObtenido[8]=comprobarCantDado(vec, 5, 2, 100);
    puntajeObtenido[9]=comprobarCantDado(vec, 5, 1, 50);
    return maxVector(puntajeObtenido,10);
}


int cantNumDados(int vec[], int tam) {
    int cantNumeros[6] = {};
    int indice;
    for (int i=0; i<tam; i++) {
        indice = vec[i]-1;
        cantNumeros[indice]++;
    }
    return sacarPuntaje(cantNumeros,6);
}


void tiradaDados(int vec[],int tam) {
    cargarVectorRandom(vec,tam,tam);
    dibujarDados(vec,tam);
}

bool continuarLanzando() {
    char siNo;
    std::cout << "\n¿CONTINUAR LANZANDO (S/N)?";
    std::cin >> siNo;

    switch (siNo) {
        case 'S':
        case 's':
            return true;
        break;
        case 'N':
        case 'n':
            return false;
        break;
    }
}

void interfazUnJugador(std::string nombreJug, int ronda, int puntajeTotal, int puntosRonda, int nroLanzamiento) {
    linea();
    std::cout << "Turno de " << nombreJug << "   ";
    std::cout << "Ronda N° " << ronda << "   ";
    std::cout << "Puntaje total: " << puntajeTotal << " puntos\n";
    linea();
    std::cout << "Puntaje de ronda: " << puntosRonda;
    std::cout << "\nLanzamiento N° " << nroLanzamiento << "\n";
    linea();
}

int lanzamiento(int ronda, int puntajeTotal, std::string nombreJug) {
    int puntosRonda=0;
    int nroLanzamiento=1;
    bool continuar=true;
    int dados[6];
    while (continuar) {
        rlutil::cls();
        interfazUnJugador(nombreJug,ronda,puntajeTotal,puntosRonda,nroLanzamiento);
        tiradaDados(dados,6);
        int puntaje=cantNumDados(dados,6);
        if (puntaje!=0) {
            std::cout << " + " << puntaje << " PUNTOS\n";
            puntosRonda+=puntaje;
            continuar = continuarLanzando();
        }
        else {
            std::cout << "Perdió el puntaje acumulado en esta ronda\n";
            continuar=false;
            rlutil::anykey();
            return 0;
        }
        nroLanzamiento++;
    }
    return puntosRonda;
}

void modoUnJugador() {
    std::string nombreJug;
    nombreJug = ingreseNombre((char)0);

    int ronda, puntajeTotal, puntajeObt;
    ronda = 1;
    puntajeTotal = 0;

    while (ronda <= 10 && puntajeTotal != 10000) {
        puntajeObt = lanzamiento(ronda,puntajeTotal,nombreJug);
        puntajeTotal += puntajeObt;
        if (puntajeTotal > 10000) {
            puntajeTotal-=puntajeObt;
        }
        ronda++;
        std::cout << "Presione una tecla para continuar\n";
        rlutil::anykey();
    }
    linea();
    std::cout << "Puntaje obtenido por "<< nombreJug << ": " << puntajeTotal<< "\n";
    linea();
}
