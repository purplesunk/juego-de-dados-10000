#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "interfaz.h"
#include "dibujardados.h"
#include "funciones.h"

void dibujarLinea(int posx, int posy, int tam, char forma) {
    for (int i=posx; i<posx+tam; i++) {
        rlutil::locate(i,posy);
        std::cout << forma;
    }
}

void mostrarPuntaje (int indicePuntaje, int puntaje) {
    rlutil::locate(2,19);
    switch (indicePuntaje) {
        case 0:
            std::cout << "OBTUVISTE UN SEXTETO!";
            break;
        case 1:
            std::cout << "OBTUVISTE UN TRIO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 2:
            std::cout << "OBTUVISTE UN TRIO 1 AMPLIADO! +" << puntaje << " PUNTOS";
            break;
        case 3:
            std::cout << "OBTUVISTE UNA ESCALERA LARGA! +" << puntaje << " PUNTOS";
            break;
        case 4:
            std::cout << "OBTUVISTE UN TRIO 1! +" << puntaje << " PUNTOS";
            break;
        case 5:
            std::cout << "OBTUVISTE UN TRIO " << puntaje/100 << "++! +" << puntaje << " PUNTOS";
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
            std::cout << "Perdio el puntaje acumulado en esta ronda\n Presione una tecla para continuar";
            break;
    }
}

bool continuarLanzando() {
    rlutil::locate(2,20);
    std::cout << "CONTINUAR LANZANDO (S/N)?";
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

void ingreseNombre(char *nombre, char *apellido, char *nombreJugador, int numJugador) {
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
    rlutil::locate(centrox-10, centroy+1);
    rlutil::showcursor();
    cargarCadena(nombreJugador, 25);
    separarNombre(nombreJugador, nombre, 15, apellido, 15);
    mostrarCadena(nombre);
    mostrarCadena(apellido);

    rlutil::anykey();
    rlutil::hidecursor();
    rlutil::cls();

}

void dibujarCaja(int posx, int posy, int ancho, int alto) {

    for (int i=posx; i<=posx+ancho; i++) {

        rlutil::locate(i,posy);

        if (i==posx) {

            std::cout << char(201);

        }
        else if (i==posx+ancho) {

            std::cout << char(187);

        }
        else {

            std::cout << char(205);

        }
    }

    for (int i=posx; i<=posx+ancho; i++) {

        rlutil::locate(i,posy+alto);

        if (i==posx) {

            std::cout << char(200);

        }
        else if (i==posx+ancho) {

            std::cout << char(188);

        }
        else {

            std::cout << char(205);

        }
    }

    for (int i=posy+1; i<posy+alto; i++) {

        rlutil::locate(posx,i);

        std::cout << char(186);
    }

    for (int i=posy+1; i<posy+alto; i++) {

        rlutil::locate(posx+ancho,i);

        std::cout << char(186);
    }

}

void dibujarCajaTitulo(int posx, int posy, int ancho, int alto, const char* titulo) {
    int anchoTitulo = strlen(titulo);
    int mitadTitulo = (posx+ancho)/2 - anchoTitulo/2;

    if (anchoTitulo > ancho) {
        ancho=anchoTitulo+1;
    }

    if (anchoTitulo > ancho/2) {
        mitadTitulo=posx+1;
    }

    dibujarCaja(posx, posy, ancho, alto+3);

    dibujarLinea(posx, posy+2, 1, char(204));

    dibujarLinea(posx+1, posy+2, ancho-1, char(205));

    dibujarLinea(posx+ancho, posy+2, 1, char(185));

    rlutil::locate(mitadTitulo,posy+1);
    std::cout << titulo;
}

void dibujarCajaInfo(char *nombre, int tamConsola) {

    char titulo[30] = "TURNO DE ";

    strcat(titulo, nombre);

    dibujarCajaTitulo(1, 1, tamConsola, 3, titulo);

    //dibujarInfo();
}

/*

void dibujarInfo() {

    rlutil::locate(3,4);
    std::cout << "RONDA: ";

    rlutil::locate(3,6);
    std::cout << "PUNTAJE TOTAL: ";

    rlutil::locate(40,4);
    std::cout << "LANZAMIENTO: ";

    rlutil::locate(40,6);
    std::cout << "PUNTAJE DE RONDA: ";
}

void mostrarDatosRonda(int ronda, int puntajeTotal) {
    dibujarLinea(10,4,2,char(32));
    rlutil::locate(10, 4);
    std::cout << ronda;

    dibujarLinea(18,4,5,char(32));
    rlutil::locate(18, 6);
    std::cout << puntajeTotal;
}

*/

void dibujarDatos(int posx, int posy, const char* texto, int dato, const char* texto2, int dato2) {

    rlutil::locate(posx, posy);
    std::cout << texto;

    int posdato = posx + strlen(texto);

    dibujarLinea(posdato,posy,5,char(32));
    rlutil::locate(posdato, posy);
    std::cout << dato;

    rlutil::locate(posx, posy+2);
    std::cout << texto2;

    int posdato2 = posx + strlen(texto2);

    dibujarLinea(posdato2,posy+2,5,char(32));
    rlutil::locate(posdato2, posy+2);
    std::cout << dato2;
}
