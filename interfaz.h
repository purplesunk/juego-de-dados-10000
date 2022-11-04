#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void ponerColores (int fondo, int letra);

void dibujarLinea(int posx, int posy, int tam, char forma);

void ingreseNombre(char *nombre, char *nombreJugador, int numJugador);

void mostrarPuntaje (int indicePuntaje, int puntaje);

bool continuarLanzando(int posy);

void dibujarInterfaz(char *nombre);

void borrarResultado();

void mostrarDato(int posx, int posy, const char* texto, int dato);

void entreRonda (int ronda, const char *nombre, int puntaje);

void proximoTurno (int ronda, const char *jugador1, const char *jugador2, int puntaje1, int puntaje2, int turno);

void teclaParaContinuar(int posy);

void mostrarPuntajeFinal(char *nombreJugador, int puntaje, int  ronda, int lanzamiento, const char *texto);

void mostrarDatosLanzamiento(int ronda, int puntajeTotal, int nroLanzamiento, int puntosRonda);

void tirandoDados();

#endif // INTERFAZ_H_INCLUDED
