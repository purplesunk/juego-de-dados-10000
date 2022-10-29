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
    dibujarDados(5,10,vec,6);
}


int lanzamiento(int ronda, int puntajeTotal) {
    int nroLanzamiento=1;
    int puntosRonda=0;
    int dados[6];

    bool continuar=true;
    while (continuar) {
        //interfazUnJugador(nombreJug,ronda,puntajeTotal,puntosRonda,nroLanzamiento);
        dibujarDatos(40, 4, "LANZAMIENTO: ", nroLanzamiento, "PUNTOS DE RONDA: ", puntosRonda);
        tiradaDados(dados,6);

        // para ver los numero despues hay que borrarlo:
        rlutil::locate(2,22);
        mostrarVec(dados,6);

        int puntaje=sacarPuntajeTirada(dados,6);
        int puntajeFinal = puntajeTotal + puntaje;

        if (puntaje!=0) {
            if (puntaje == 10000 || puntajeFinal==10000) {
                rlutil::locate(2,17);
                std::cout <<  "GANASTE LA PARTIDA!!\n Presione una tecla para continuar.";
                puntosRonda = -1;
                continuar = false;
                rlutil::anykey();
                rlutil::anykey();
            }
            else {
                if (puntajeFinal > 10000) {
                    puntaje = 0;
                }
                puntosRonda+=puntaje;
                continuar = continuarLanzando();
            }
        }
        else {
            continuar=false;
            rlutil::anykey();
            borrarDados(100);
            return 0;
        }
        borrarDados(100);
        nroLanzamiento++;
    }
    return puntosRonda;
}

int modoUnJugador(char* nombre, int rondaLazamiento[]) {
    int tamConsola=rlutil::tcols();

    dibujarCajaInfo(nombre, tamConsola);

    int puntajeTotal, puntajeObt;
    puntajeTotal = 0;

    while (rondaLazamiento[0] < 10 && puntajeTotal != 10000) {

        rondaLazamiento[0]++;

        //mostrarDatosRonda(rondaLazamiento[0], puntajeTotal);
        dibujarDatos( 3, 4, "RONDA: ", rondaLazamiento[0], "PUNTAJE TOTAL: ", puntajeTotal);

        puntajeObt = lanzamiento(rondaLazamiento[0],puntajeTotal);

        puntajeTotal += puntajeObt;

        if (puntajeObt == -1) {
            puntajeTotal= 10000;
        }
        if (puntajeTotal > 10000) {
            puntajeTotal-=puntajeObt;
        }
    }
    rlutil::cls();
    std::cout << "Puntaje obtenido por "<< nombre << ": " << puntajeTotal << " en ronda " << rondaLazamiento[0] << "\n";
    // mostrarCadena nombreCompleto;
    // puntaje
    // lanzamientos o ronda;
    // comparar con el mejor puntaje y cambiarlo
    // return el puntaje? o no o lo comparo afuera?
    rlutil::anykey();
    rlutil::cls();
    return puntajeTotal;
}
