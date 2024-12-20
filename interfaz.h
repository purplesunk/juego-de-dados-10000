#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "interfaz.h"
#include "funciones.h"
#include "dibujardados.h"

const char *space = " ";
const char *horizontal = "═";
const char *vertical = "║";
const char *top_left = "╔";
const char *top_right = "╗";
const char *bottom_left = "╚";
const char *bottom_right = "╝";
const char *pipe_left = "╠";
const char *pipe_right = "╣";

void ponerColores(int fondo, int letra) {
    rlutil::setBackgroundColor(fondo);
    rlutil::setColor(letra);
}

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        ponerColores(rlutil::MAGENTA, rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << " >" << texto << "< ";
        ponerColores(rlutil::BLACK, rlutil::WHITE);
    } else {
        ponerColores(rlutil::BLACK, rlutil::WHITE);
        rlutil::locate(posx-2,posy);
        std::cout << "  " << texto << "  ";
    }
    rlutil::setColor(rlutil::BLACK);
}

void dibujarLinea(int posx, int posy, int tam, char forma) {
    for (int i=posx; i<posx+tam; i++) {
        rlutil::locate(i,posy);
        std::cout << forma;
    }
}
void dibujarLineaU(int posx, int posy, int tam, const char *forma) {
    for (int i=posx; i<posx+tam; i++) {
        rlutil::locate(i,posy);
        std::cout << forma;
    }
}

void mostrarPuntaje (int indicePuntaje, int puntaje) {
    rlutil::locate(3,19);
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
            std::cout << "NO OBTUVO NADA, Perdio el puntaje acumulado en esta ronda.";
            break;
    }
}

void teclaParaContinuar(int posy) {
    int centro = rlutil::tcols()/2;
    char aviso[] = "Presione una tecla para continuar.";
    int mitadAviso = strlen(aviso)/2;
    rlutil::locate(centro - mitadAviso , posy);
    std::cout << aviso;
    rlutil::anykey();
}

bool continuarLanzando(int posy) {
    int centro = rlutil::tcols()/2;
    char pregunta[] = "CONTINUAR LANZANDO? (S/N)";
    int mitadPregunta = strlen(pregunta)/2;
    rlutil::locate(centro - mitadPregunta , posy);
    std::cout << pregunta;
    int x = 2;
    do {
        mostrarOpcion("  SI  ", centro-10, posy+1, x == 1);
        mostrarOpcion("  NO  ", centro+5, posy+1, x == 2);
        switch (rlutil::getkey()) {
            case 115:  // s o S
            case 83:
                ponerColores(rlutil::BLACK, rlutil::WHITE);
                return true;
                break;
            case 110:  // n o N
            case 78:
                ponerColores(rlutil::BLACK, rlutil::WHITE);
                return false;
                break;
            case rlutil::KEY_LEFT:
            case 68:
                x = 1;
                break;
            case rlutil::KEY_RIGHT:
            case 67:
                x = 2;
                break;
            case rlutil::KEY_ENTER:
            case 10:
                ponerColores(rlutil::BLACK, rlutil::WHITE);
                switch (x) {
                    case 1:
                        return true;
                        break;
                    case 2:
                        return false;
                        break;
                }
        }
    } while (true);
}

void ingreseNombre(char *nombre, char *nombreJugador, int numJugador) {
    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;
    if (numJugador==0) {
        rlutil::locate(centrox-13, centroy-1);
        std::cout << "Ingrese nombre del jugador: ";
    }
    else {
        rlutil::locate(centrox-14, centroy-1);
        std::cout << "Ingrese nombre del jugador " << numJugador << ": ";
    }
    ponerColores(rlutil::BLUE, rlutil::WHITE);
    dibujarLineaU(centrox-13, centroy+1, 27, space);
    rlutil::locate(centrox-12, centroy+1);
    rlutil::showcursor();
    cargarCadena(nombreJugador, 30);
    for (int i = 0; nombreJugador[i] != '\0'; i++) {
        if (nombreJugador[i] > 96 && nombreJugador[i] < 123) {
            nombreJugador[i]-= 32;
        }
    }
    ponerColores(rlutil::BLACK, rlutil::WHITE);
    separarNombre(nombreJugador, nombre, 15);
    rlutil::hidecursor();
    rlutil::cls();
}

void dibujarCaja(int posx, int posy, int ancho, int alto) {
    for (int i=posx; i<=posx+ancho; i++) {
        rlutil::locate(i,posy);
        if (i==posx) {
            std::cout << top_left;
        }
        else if (i==posx+ancho) {
            std::cout << top_right;
        }
        else {
            std::cout << horizontal;
        }
    }
    for (int i=posx; i<=posx+ancho; i++) {
        rlutil::locate(i,posy+alto);
        if (i==posx) {
            std::cout << bottom_left;
        }
        else if (i==posx+ancho) {
            std::cout << bottom_right;
        }
        else {
            std::cout << horizontal;
        }
    }
    for (int i=posy+1; i<posy+alto; i++) {
        rlutil::locate(posx,i);
        std::cout << vertical;
    }
    for (int i=posy+1; i<posy+alto; i++) {
        rlutil::locate(posx+ancho,i);
        std::cout << vertical;
    }
}

void dibujarCajaTitulo(int posx, int posy, int ancho, int alto, const char* titulo) {
    dibujarCaja(posx, posy, ancho, alto+3);
    dibujarLineaU(posx, posy+2, 1, pipe_left);
    dibujarLineaU(posx+1, posy+2, ancho-1, horizontal);
    dibujarLineaU(posx+ancho, posy+2, 1, pipe_right);
    int anchoTitulo = strlen(titulo);
    if (anchoTitulo > ancho) {
        ancho=anchoTitulo+2;
        rlutil::locate(posx+2, posy+1);
    }
    else {
        int mitadTitulo = anchoTitulo/2;
        rlutil::locate(posx+(ancho/2)-mitadTitulo, posy+1);
    }
    std::cout << titulo;
}

void dibujarInterfaz(char *nombre) {
    int tamConsola = rlutil::tcols();
    int altura = rlutil::trows();
    char titulo[30] = "TURNO DE ";
    strcat(titulo, nombre);
    dibujarCajaTitulo(1, 1, tamConsola - 1, altura - 4, titulo);
    dibujarLineaU(1, 7, 1, pipe_left);
    dibujarLineaU(2,7, tamConsola - 1, horizontal);
    dibujarLineaU(tamConsola, 7, 1, pipe_right);
    dibujarLineaU(1, 18, 1, pipe_left);
    dibujarLineaU(2, 18, tamConsola - 1, horizontal);
    dibujarLineaU(tamConsola, 18, 1, pipe_right);
}

void borrarResultado() {
    int anchoCaja = rlutil::tcols() - 2;
    for (int i = 19; i<=23; i++) {
        dibujarLineaU(2, i, anchoCaja, space);
    }
}

void mostrarDato(int posx, int posy, const char* texto, int dato) {
    rlutil::locate(posx, posy);
    std::cout << texto;
    int posDato = posx + strlen(texto);
    // reiniciar dato
    dibujarLineaU(posDato,posy,5, space);
    rlutil::locate(posDato, posy);
    std::cout << dato;
}

void mostrarDatosLanzamiento(int ronda, int puntajeTotal, int nroLanzamiento, int puntosRonda) {
    mostrarDato(3, 4, "RONDA: ", ronda);
    mostrarDato(3, 6, "PUNTAJE TOTAL: ", puntajeTotal);
    mostrarDato(40, 4, "LANZAMIENTO: ", nroLanzamiento);
    mostrarDato(40, 6, "PUNTOS DE RONDA: ", puntosRonda);
}

void mostrarPuntajeFinal(char *nombreJugador, int puntaje, int  ronda, int lanzamiento, const char *texto) {
    rlutil::cls();
    char titulo[80] = {};
    strcat(titulo, texto);
    strcat(titulo, nombreJugador);
    int anchoTitulo = strlen(titulo);
    int posx = rlutil::tcols()/2-(anchoTitulo/2);
    int posy = rlutil::trows()/2-3;
    dibujarCajaTitulo(posx, posy, strlen(titulo)+2, 3, titulo);
    mostrarDato(posx + 2, posy + 3, "PUNTAJE: ", puntaje);
    mostrarDato(posx + 2, posy + 4, "RONDA: ", ronda);
    mostrarDato(posx + 2, posy + 5, "LANZAMIENTO: ", lanzamiento);
    teclaParaContinuar((posy+3)*2+1);
    rlutil::cls();
}

void entreRonda (int ronda, const char *nombre, int puntaje) {
    rlutil::cls();
    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;
    dibujarCaja(centrox-15, centroy-2, 30, 4);
    mostrarDato(centrox - 13, centroy - 1, "RONDA SIGUIENTE: ", ronda);
    rlutil::locate(centrox - 13, centroy);
    std::cout <<  "JUGADOR: " <<  nombre;
    mostrarDato(centrox - 13, centroy + 1, "PUNTAJE TOTAL: ", puntaje);
    teclaParaContinuar((centroy*2)-1);
    rlutil::cls();
}

void proximoTurno (int ronda, const char *jugador1, const char *jugador2, int puntaje1, int puntaje2, int turno) {
    rlutil::cls();
    int centrox = rlutil::tcols()/2;
    int centroy = rlutil::trows()/2;
    char titulo[40] = " PROXIMO TURNO: ";
    if (turno == 1) {
        strcat(titulo, jugador1);
    }
    else {
        strcat(titulo, jugador2);
    }
    int posx = centrox - 25;
    dibujarCajaTitulo(posx, centroy-3, 50, 3, titulo);
    mostrarDato(posx + 2, centroy, "RONDA: ", ronda);
    rlutil::locate(posx + 2, centroy+1);
    std::cout << "PUNTAJE TOTAL " << jugador1 << ": " << puntaje1;
    rlutil::locate(posx + 2, centroy + 2);
    std::cout << "PUNTAJE TOTAL " << jugador2 << ": " << puntaje2;
    teclaParaContinuar((centroy*2)-1);
    rlutil::cls();
}

#endif // INTERFAZ_H_INCLUDED