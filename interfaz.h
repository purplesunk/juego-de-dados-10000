#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void dibujarLinea(int posx, int posy, int tam, char forma);
void mostrarPuntaje (int indicePuntaje, int puntaje);
void interfazUnJugador(std::string nombreJug, int ronda, int puntajeTotal, int puntosRonda, int nroLanzamiento);
void ingreseNombre(char *nombre, char *apellido, char *nombreJugador, int numJugador);
bool continuarLanzando();

#endif // INTERFAZ_H_INCLUDED
