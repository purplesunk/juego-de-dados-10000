#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "gameplay.h"
#include "dibujardados.h"
#include "interfaz.h"

int comprobar3Num(int vec[], int tam, int puntaje) {

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

void cantNumDados(int vecNum[], int vecCant[], int tam) {
    int indice;

    for (int i=0; i<tam; i++) {

        indice = vecNum[i]-1;

        vecCant[indice]++;

    }
}

int sacarPuntajeTirada(int vec[], int tam) {

    int cantNumeros[6] = {};
    cantNumDados(vec, cantNumeros, tam);

    int posiblePuntaje[10];

    posiblePuntaje[0]=comprobarCantDado(cantNumeros, 1, 6, 10000);

    posiblePuntaje[1]=comprobarCantDado(cantNumeros, 1, 5, 2000);

    posiblePuntaje[2]=comprobarCantDado(cantNumeros, 1, 4, 2000);

    posiblePuntaje[3]=comprobarEscalera(cantNumeros, tam, 1500);

    posiblePuntaje[4]=comprobarCantDado(cantNumeros, 1, 3, 1000);

    posiblePuntaje[5]=comprobar3Num(cantNumeros, tam, 100);

    posiblePuntaje[6]=comprobarCantDado(cantNumeros, 1, 2, 200);

    posiblePuntaje[7]=comprobarCantDado(cantNumeros, 1, 1, 100);

    posiblePuntaje[8]=comprobarCantDado(cantNumeros, 5, 2, 100);

    posiblePuntaje[9]=comprobarCantDado(cantNumeros, 5, 1, 50);


    int puntajeObtenido = maxVector(posiblePuntaje,10);

    int indicePuntaje = 10;

    if (puntajeObtenido != 0) {

        indicePuntaje = (posMaxVector(posiblePuntaje,10))-1;

    }

    mostrarPuntaje(indicePuntaje, puntajeObtenido);

    return puntajeObtenido;
}


void tiradaDados(int vec[],int tam) {
    cargarVectorRandom(vec,tam,6);
}

int validarRonda (int puntajeObtenido, int puntajeFinal, int puntosRonda, bool &continuar) {
    int altoConsola = rlutil::trows();

    if ( puntajeObtenido !=0 ) {

        if (puntajeObtenido == 10000 || puntajeFinal==10000) {

            rlutil::locate(3,20);
            std::cout <<  "LLEGASTE A LOS 10000!! GANASTE LA PARTIDA!!";

            puntosRonda = -1;
            continuar = false;

            teclaParaContinuar(altoConsola-2);

        }
        else if (puntajeFinal > 10000) {

            rlutil::locate(3,20);
            std::cout << "Te pasaste de los 10000, ronda finalizada.";

            continuar = false;
            puntosRonda = 0;
            teclaParaContinuar(altoConsola-2);

        }
        else {

            puntosRonda+=puntajeObtenido;
            continuar = continuarLanzando(altoConsola-2);

        }

    }
    else {

        continuar=false;
        teclaParaContinuar(altoConsola-2);
        puntosRonda = 0;

    }

    return puntosRonda;
}


int lanzamiento(int  ronda, int &nroLanzamiento, int puntajeTotal) {

    int dados[6];
    int puntosRonda=0;

    nroLanzamiento=0;

    bool continuar=true;

    while (continuar) {

        nroLanzamiento++;
        mostrarDatosLanzamiento(ronda, puntajeTotal, nroLanzamiento, puntosRonda);

        tiradaDados(dados,6);
        dibujarDados(5,10,dados,6);

        int puntajeObtenido=sacarPuntajeTirada(dados,6);
        int puntajeFinal = puntajeTotal + puntosRonda + puntajeObtenido;

        puntosRonda = validarRonda(puntajeObtenido, puntajeFinal, puntosRonda, continuar);

        borrarDados();
        borrarResultado();
    }

    return puntosRonda;

}


int validarPuntaje (int puntajeObtenido, int puntajeTotal, int ronda, int nroLanzamiento, int &rondaPuntajeObtenido, int &lanzamientoPuntajeObtenido) {
    puntajeTotal += puntajeObtenido;

    if (puntajeObtenido == -1) {
        puntajeTotal= 10000;
    }

    if (puntajeObtenido != 0) {
        rondaPuntajeObtenido = ronda;
        lanzamientoPuntajeObtenido = nroLanzamiento;
    }

    return puntajeTotal;
}

void modoUnJugador(int mejorPuntaje[], char *nombreMejorPuntaje) {

    char nombreJugador[30];
    char nombre[15];
    ingreseNombre(nombre, nombreJugador, 0);

    int ronda = 0;
    int nroLanzamiento;

    int puntajeTotal = 0;
    int puntajeObtenido;

    int rondaPuntajeObtenido;
    int lanzamientoPuntajeObtenido;

    while (ronda < 10 && puntajeTotal != 10000) {

        ronda++;

        entreRonda(ronda, nombre, puntajeTotal);

        dibujarInterfaz(nombre);

        puntajeObtenido = lanzamiento(ronda, nroLanzamiento, puntajeTotal);

        puntajeTotal = validarPuntaje (puntajeObtenido, puntajeTotal, ronda, nroLanzamiento, rondaPuntajeObtenido, lanzamientoPuntajeObtenido);

    }

    mostrarPuntajeFinal(nombreJugador, puntajeTotal, rondaPuntajeObtenido, lanzamientoPuntajeObtenido, " PUNTAJE OBTENIDO POR ");

    compararMejorPuntaje(nombreMejorPuntaje, mejorPuntaje, nombreJugador, puntajeTotal, rondaPuntajeObtenido, lanzamientoPuntajeObtenido);

}

void modoDosJugadores(int mejorPuntaje[], char *nombreMejorPuntaje) {

    char nombreCompletoJugador1[30];
    char nombreJugador1[15];
    ingreseNombre(nombreJugador1, nombreCompletoJugador1, 1);

    char nombreCompletoJugador2[30];
    char nombreJugador2[15];
    ingreseNombre(nombreJugador2, nombreCompletoJugador2, 2);


    int puntajeJugador1 = 0;
    int lanzamientoJugador1 = 0;
    int rondaJugador1 = 0;

    int puntajeJugador2 = 0;
    int lanzamientoJugador2 = 0;
    int rondaJugador2 = 0;

    int ronda = 0;
    int nroLanzamiento;
    int puntajeObtenido;

    while (ronda < 10 && puntajeJugador1 != 10000 && puntajeJugador2 != 10000) {
        ronda++;

        proximoTurno(ronda, nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, 1);

        dibujarInterfaz(nombreJugador1);

        puntajeObtenido = lanzamiento(ronda, nroLanzamiento, puntajeJugador1);

        puntajeJugador1 = validarPuntaje(puntajeObtenido, puntajeJugador1, ronda, nroLanzamiento, rondaJugador1, lanzamientoJugador1);

        if (puntajeJugador1 == 10000) {
            break;
        }

        proximoTurno(ronda, nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, 2);

        dibujarInterfaz(nombreJugador2);

        puntajeObtenido = lanzamiento(ronda, nroLanzamiento, puntajeJugador2);

        puntajeJugador2 = validarPuntaje(puntajeObtenido, puntajeJugador2, ronda, nroLanzamiento, rondaJugador2, lanzamientoJugador2);

    }

    int vecJugador1[3] = { puntajeJugador1, rondaJugador1, lanzamientoJugador1};

    compararMejorPuntaje(nombreCompletoJugador1, vecJugador1, nombreCompletoJugador2, puntajeJugador2, rondaJugador2, lanzamientoJugador2);

    mostrarPuntajeFinal(nombreCompletoJugador1, vecJugador1[0], vecJugador1[1], vecJugador1[2], " GANA LA PARTIDA: ");

    compararMejorPuntaje(nombreMejorPuntaje, mejorPuntaje, nombreCompletoJugador1, vecJugador1[0], vecJugador1[1], vecJugador1[2]);
}
