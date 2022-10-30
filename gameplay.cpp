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


int lanzamiento(int  rondaLazamiento[], int puntajeTotal) {
    int puntosRonda=0;
    int dados[6];

    rondaLazamiento[1]=1;

    bool continuar=true;

    while (continuar) {

        dibujarDatos(40, 4, "LANZAMIENTO: ", rondaLazamiento[1], "PUNTOS DE RONDA: ", puntosRonda);

        tiradaDados(dados,6);

        dibujarDados(5,10,dados,6);

        int puntajeObtenido=sacarPuntajeTirada(dados,6);

        int puntajeFinal = puntajeTotal + puntosRonda + puntajeObtenido;

        if ( puntajeObtenido !=0 ) {

            if (puntajeObtenido == 10000 || puntajeFinal==10000) {

                rlutil::locate(2,20);
                std::cout <<  "GANASTE LA PARTIDA!!";

                puntosRonda = -1;

                continuar = false;

                teclaParaContinuar(22);

            }
            else if (puntajeFinal > 10000) {

                rlutil::locate(3,20);
                std::cout << "Te pasaste de los 10000, ronda finalizada.";

                continuar = false;

                puntosRonda = 0;

                teclaParaContinuar(22);

            }
            else {

                puntosRonda+=puntajeObtenido;

                continuar = continuarLanzando(22);

            }

        }
        else {

            continuar=false;

            teclaParaContinuar(22);

            borrarResultado();

            borrarDados();

            return 0;
        }



        borrarDados();

        borrarResultado();

        rondaLazamiento[1]++;

    }

    return puntosRonda;

}

int modoUnJugador(char* nombre, int rondaLazamiento[]) {

    int tamConsola=rlutil::tcols();

    dibujarCajaInfo(nombre, tamConsola);

    int puntajeTotal = 0;
    int puntajeObt;

    while (rondaLazamiento[0] < 10 && puntajeTotal != 10000) {

        rondaLazamiento[0]++;

        dibujarDatos( 3, 4, "RONDA: ", rondaLazamiento[0], "PUNTAJE TOTAL: ", puntajeTotal);

        puntajeObt = lanzamiento(rondaLazamiento,puntajeTotal);

        puntajeTotal += puntajeObt;

        if (puntajeObt == -1) {
            puntajeTotal= 10000;
        }
        if (puntajeTotal > 10000) {
            puntajeTotal-=puntajeObt;
        }
    }

    rlutil::cls();

    return puntajeTotal;
}
