#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void dibujarLinea(int posx, int posy, int tam, char forma);

void mostrarPuntaje (int indicePuntaje, int puntaje);

void ingreseNombre(char *nombre, char *apellido, char *nombreJugador, int numJugador);

bool continuarLanzando();

void dibujarCaja(int posx, int posy, int ancho, int alto);

void dibujarCajaTitulo(int posx, int posy, int ancho, int alto, const char* titulo);

void dibujarCajaInfo(char *nombre, int tamConsola);

void dibujarInfo();

void mostrarDatosRonda(int ronda, int puntajeTotal);

void dibujarDatos(int posx, int posy, const char* texto, int dato, const char* texto2, int dato2);

#endif // INTERFAZ_H_INCLUDED
