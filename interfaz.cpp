#include <iostream>
#include "rlutil.h"
#include "interfaz.h"
#include "dibujardados.h"

void dibujarLinea(int posx, int posy, int tam, char forma) {
    for (int i=posx; i<posx+tam; i++) {
        rlutil::locate(i,posy);
        std::cout << forma;
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
    int tamHorizontal = rlutil::tcols();
    int columna = tamHorizontal/4;
    borrarDados(tamHorizontal);
    dibujarLinea(1,1,tamHorizontal,char(205));
    rlutil::locate(2,2);
    std::cout << "Turno de " << nombreJug;
    rlutil::locate(columna,2);
    std::cout << "\tRonda N° " << ronda;
    rlutil::locate(columna*2,2);
    std::cout << "\tPuntaje total: " << puntajeTotal << " puntos";
    rlutil::locate(2,4);
    std::cout << "Puntaje de ronda: " << puntosRonda;
    rlutil::locate(columna*2,4);
    std::cout << "Lanzamiento N° " << nroLanzamiento;
}
