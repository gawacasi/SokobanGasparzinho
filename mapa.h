#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"
typedef struct{
    Texture2D imagem;
    Vector2 coordenada;
} Quadrado;

char **mapa_caractere(int level);

void mapa_desenhando(char **mapa);


#endif