#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "gameplay.h"
#include "interfaz.h"
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
    int centrox = (rlutil::tcols()/2)-12;
    int centroy = (rlutil::trows()/2)-2;

    //int mejorPuntaje[3];
    //char nombreMejorPuntaje[25];

    do {
        setDefault();
        rlutil::hidecursor();

        mostrarOpcion("   MODO UN JUGADOR      ", centrox, centroy,   y == 0);
        mostrarOpcion("   MODO DOS JUGADORES   ", centrox, centroy+1, y == 1);
        mostrarOpcion("   MEJORES PUNTAJES     ", centrox, centroy+2, y == 2);
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



                        char nombreJugador[25];
                        char nombre[15];
                        char apellido[15];
                        ingreseNombre(nombre, apellido, nombreJugador, 0);

                        int rondaLazamiento[2]={};

                        int puntaje;

                        puntaje =  modoUnJugador(nombre, rondaLazamiento);

                        // comparar puntaje con mejorPuntaje

                    }
                    break;

                    case Opciones::MODO_DOS_JUGADORES: {
                        dibujarCaja(3,2,10,4);
                        dibujarCajaTitulo(15,6,20,5,"asdasddsddd d");
                        dibujarCajaTitulo(40,10,10,0,"hola xdxd");
                        rlutil::anykey();
                        rlutil::cls();

                    }
                    break;

                    case Opciones::MEJOR_PUNTAJE: {
                        rlutil::cls();
                        dibujarCajaTitulo(centrox,centroy,24,2,"MEJOR PUNTAJE");
                        rlutil::anykey();
                        rlutil::cls();
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
