#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

void dibujarLinea(int posx, int posy, int tam, char forma);
void nombrePuntaje (int indicePuntaje, int puntaje);
bool continuarLanzando();
void interfazUnJugador(std::string nombreJug, int ronda, int puntajeTotal, int puntosRonda, int nroLanzamiento);

#endif // INTERFAZ_H_INCLUDED
