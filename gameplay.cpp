#include <iostream>
#include <string>
#include "rlutil.h"
#include "funciones.h"
#include "menu.h"
#include "gameplay.h"
#include "dibujardados.h"

std::string ingreseNombre(int numJugador) {
    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;
    std::string nombreJug;
    if (numJugador==0) {
        rlutil::locate(centrox-13, centroy-1);
        std::cout << "Ingrese nombre del jugador: ";
    }
    else {
        rlutil::locate(centrox-14, centroy-1);
        std::cout << "Ingrese nombre del jugador " << numJugador << ": ";
    }
    rlutil::locate(centrox, centroy+1);
    rlutil::showcursor();
    std::cin >> nombreJug;
    rlutil::hidecursor();
    rlutil::cls();
    return nombreJug;
}

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

void nombrePuntaje (int indicePuntaje, int puntaje) {
    rlutil::locate(2,16);
    switch (indicePuntaje) {
        case 0:
            std::cout << "OBTUVISTE UN SEXTETO!";
            break;
        case 1:
            std::cout << "OBTUVISTE UN TRÍO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 2:
            std::cout << "OBTUVISTE UN TRÍO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 3:
            std::cout << "OBTUVISTE UNA ESCALERA LARGA! +" << puntaje << " PUNTOS";
            break;
        case 4:
            std::cout << "OBTUVISTE UN TRÍO 1! +" << puntaje << " PUNTOS";
            break;
        case 5:
            std::cout << "OBTUVISTE UN TRÍO " << puntaje/100 << "++! +" << puntaje << " PUNTOS";
            break;
        case 6:
            std::cout << "OBTUVISTE UN JUEGO DE UNO! +" << puntaje << " PUNTOS";
            break;
        case 7:
            std::cout << "OBTUVISTE UN JUEGO DE UNO! +" << puntaje << " PUNTOS";
            break;
        case 8:
            std::cout << "OBTUVISTE UN JUEGO DE CINCO! +" << puntaje << " PUNTOS";
            break;
        case 9:
            std::cout << "OBTUVISTE UN JUEGO DE CINCO! +" << puntaje << " PUNTOS";
            break;
        case 10:
            std::cout << "Perdió el puntaje acumulado en esta ronda\n Presione una tecla para continuar";
            break;
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

    nombrePuntaje(indicePuntaje, puntajeObtenido);
    return puntajeObtenido;
}


void tiradaDados(int vec[],int tam) {
    cargarVectorRandom(vec,tam,6);
    dibujarDados(vec,tam);
}

bool continuarLanzando() {
    rlutil::locate(2,18);
    std::cout << "¿CONTINUAR LANZANDO (S/N)?";
    do {
        switch (rlutil::getkey()) {
            case 115:  // s o S
            case 83:
                return true;
                break;
            case 110:  // n o N
            case 78:
                return false;
                break;
        }
    } while (true);
}

void interfazUnJugador(std::string nombreJug, int ronda, int puntajeTotal, int puntosRonda, int nroLanzamiento) {
    int tamañoHorizontal = rlutil::tcols();
    int columna = tamañoHorizontal/4;

    borrarDados(tamañoHorizontal);
    drawCharLine(tamañoHorizontal,1,1,R"(—)");
    rlutil::locate(2,2);
    std::cout << "Turno de " << nombreJug;
    rlutil::locate(columna,2);
    std::cout << "\tRonda N° " << ronda;
    rlutil::locate(columna*2,2);
    std::cout << "\tPuntaje total: " << puntajeTotal << " puntos";
    drawCharLine(tamañoHorizontal,3,1,R"(—)");
    rlutil::locate(2,4);
    std::cout << "Puntaje de ronda: " << puntosRonda;
    rlutil::locate(columna*2,4);
    std::cout << "Lanzamiento N° " << nroLanzamiento;
    drawCharLine(tamañoHorizontal,5,1,R"(—)");
}

int lanzamiento(int ronda, int puntajeTotal, std::string nombreJug) {
    int nroLanzamiento=1;
    int puntosRonda=0;
    int dados[6];

    bool continuar=true;
    while (continuar) {
        interfazUnJugador(nombreJug,ronda,puntajeTotal,puntosRonda,nroLanzamiento);
        tiradaDados(dados,6);

        // para ver los numero despues hay que borrarlo:
        rlutil::locate(2,20);
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
            return 0;
        }
        nroLanzamiento++;
    }
    return puntosRonda;
}

void modoUnJugador() {
    rlutil::cls();
    std::string nombreJug;
    nombreJug = ingreseNombre(0);

    int ronda, puntajeTotal, puntajeObt;
    ronda = 0;
    puntajeTotal = 0;

    while (ronda < 10 && puntajeTotal != 10000) {
        ronda++;
        puntajeObt = lanzamiento(ronda,puntajeTotal,nombreJug);
        puntajeTotal += puntajeObt;

        if (puntajeObt == -1) {
            puntajeTotal= 10000;
        }
        if (puntajeTotal > 10000) {
            puntajeTotal-=puntajeObt;
        }
    }
    rlutil::cls();
    linea();
    std::cout << "Puntaje obtenido por "<< nombreJug << ": " << puntajeTotal<< " en ronda " << ronda << "\n";
    linea();
    rlutil::anykey();
}
