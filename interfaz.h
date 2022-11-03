#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void dibujarLinea(int posx, int posy, int tam, char forma);

void mostrarPuntaje (int indicePuntaje, int puntaje);

void ingreseNombre(char *nombre, char *nombreJugador, int numJugador);

bool continuarLanzando(int posy);

void dibujarCaja(int posx, int posy, int ancho, int alto);

void dibujarCajaTitulo(int posx, int posy, int ancho, int alto, const char* titulo);

void dibujarCajaInfo(char *nombre, int tamConsola);

void dibujarInfo();

void dibujarDatos(int posx, int posy, const char* texto, int dato, const char* texto2, int dato2);

void borrarResultado();

void teclaParaContinuar(int posy);

void mostrarPuntajeObtenido(int posx, int posy, char *nombreJugador, int puntaje, int  ronda, int lanzamiento, const char *texto);

void entreRonda (int posx, int posy, int ronda, const char *nombre, int puntaje);

void proximoTurno (const char *jugador1, const char *jugador2, int puntaje1, int puntaje2, int turno);

#endif // INTERFAZ_H_INCLUDED
