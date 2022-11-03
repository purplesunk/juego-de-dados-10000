#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "gameplay.h"
#include "interfaz.h"
#include "funciones.h"
#include "menu.h"

void setDefault() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

void mostrarOpcion(const char* texto, int posx, int posy, bool seleccionado) {
    if (seleccionado) {
        rlutil::setBackgroundColor(rlutil::MAGENTA);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout << " " << (char)62 << texto << (char)60 << " ";
        setDefault();
    }
    else {
        setDefault();
        rlutil::locate(posx-2,posy);
        std::cout << "  " << texto << "  ";
    }
    rlutil::setColor(rlutil::BLACK);
}

enum Opciones {
    MODO_UN_JUGADOR = 0,
    MODO_DOS_JUGADORES = 1,
    MEJOR_PUNTAJE = 2,
    SALIR = 3
};

int menu() {
    rlutil::cls();
    int y = 0;

    int centroH = rlutil::tcols()/2;
    int centroV = rlutil::trows()/2;

    int centrox = centroH-12;
    int centroy = centroV-2;

    // 0 = puntaje, 1 = ronda, 2 = lanzamiento
    int mejorPuntaje[3] {};
    char nombreMejorPuntaje[30] = {};

    do {
        setDefault();
        rlutil::hidecursor();

        mostrarOpcion("   MODO UN JUGADOR      ", centrox, centroy,   y == 0);
        mostrarOpcion("   MODO DOS JUGADORES   ", centrox, centroy+1, y == 1);
        mostrarOpcion("   MEJOR PUNTAJE        ", centrox, centroy+2, y == 2);
        mostrarOpcion("   SALIR                ", centrox, centroy+3, y == 3);


        switch (rlutil::getkey()) {

            case 15:  // ABAJO
            case 66:  //
                y++;
                if (y>3) {
                    y=3;
                }
                break;

            case 14:  // ARRIBA
            case 65:  //
                y--;

                if (y<0) {

                    y=0;

                }
                break;

            case 1:  // ENTER
            case 10: //
                rlutil::cls();
                setDefault();
                switch(y){
                    case Opciones::MODO_UN_JUGADOR: {



                        char nombreJugador[30];
                        char nombre[15];
                        ingreseNombre(nombre, nombreJugador, 0);

                        int rondaLazamiento[2]={};

                        int puntaje;

                        puntaje =  modoUnJugador(nombre, rondaLazamiento);

                        mostrarPuntajeObtenido(centroH, centroV, nombreJugador, puntaje, rondaLazamiento[0], rondaLazamiento[1], " PUNTAJE OBTENIDO POR ");

                        compararMejorPuntaje(nombreMejorPuntaje, mejorPuntaje, nombreJugador, puntaje, rondaLazamiento);

                    }
                    break;

                    case Opciones::MODO_DOS_JUGADORES: {

                        char nombreCompletoJugador1[30];
                        char nombreJugador1[15];
                        ingreseNombre(nombreJugador1, nombreCompletoJugador1, 1);

                        char nombreCompletoJugador2[30];
                        char nombreJugador2[15];
                        ingreseNombre(nombreJugador2, nombreCompletoJugador2, 2);

                        int ronda = 0;

                        int puntajeJugador1 = 0;

                        int puntajeJugador2 = 0;

                        while (ronda < 10) {
                            ronda++;

                            proximoTurno(nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, 1);
                            teclaParaContinuar((centroV*2)-1);
                            rlutil::cls();


                            proximoTurno(nombreJugador1, nombreJugador2, puntajeJugador1, puntajeJugador2, 2);
                            teclaParaContinuar((centroV*2)-1);
                            rlutil::cls();

                        }

                    }
                    break;

                    case Opciones::MEJOR_PUNTAJE: {
                        rlutil::cls();

                        if (nombreMejorPuntaje[0] == '\0') {

                            char aviso[] = "No se ha jugado ninguna partida.";

                            rlutil::locate(centroH - (strlen(aviso)/2), centroV);
                            std::cout << aviso;

                            teclaParaContinuar(centroV+1);

                            rlutil::cls();

                        }
                        else {

                            mostrarPuntajeObtenido(centroH, centroV, nombreMejorPuntaje, mejorPuntaje[0], mejorPuntaje[1], mejorPuntaje[2], " MEJOR PUNTAJE POR ");

                        }


                    }
                    break;

                    case Opciones::SALIR: {
                        setDefault();
                        rlutil::cls();
                        return 0;
                    }
                    break;
                }
                break;
        }

    } while (true);
}
