#include "raylib.h"
#include "mapa.h"
#include <stdio.h>
#include "movimentos.h"

void TROCA_VAZIO(MAPA *mapa, int *x, int *y, int cont1, int cont2){

            char aux;
            if ((*mapa).mapa[*y+cont2][*x+cont1] == '@'||(*mapa).mapa[*y+cont2][*x+cont1] == '+'){
                  aux = (*mapa).mapa[*y+cont2][*x+cont1];
                  (*mapa).mapa[*y+cont2][*x+cont1]=(*mapa).mapa[*y][*x];
                  (*mapa).mapa[*y][*x]= aux;
                  *x=*x+cont1; *y=*y+cont2;
            }
}

void TROCA_CAIXA(int *x, int *y, int cont1, int cont2, MAPA *mapa){

  if(*x+2*cont1>=0 && *x+2*cont1<12 && *y+2*cont2>=0 && *y+2*cont2<12){

          if((*mapa).mapa[*y+cont2][*x+cont1] == 'B'){

              if ((*mapa).mapa[*y+2*cont2][*x+2*cont1] == '@'||(*mapa).mapa[*y+2*cont2][*x+2*cont1] == '+'){
                      if((*mapa).especial_atual[*y+2*cont2][*x+2*cont1]==1){
                          (*mapa).especial_atual[*y+2*cont2][*x+2*cont1]=0;
                      }
                      if((*mapa).especial_atual[*y+cont2][*x+cont1]==0){
                          if((*mapa).especial_inicio[*y+cont2][*x+cont1]==1){
                          (*mapa).especial_atual[*y+cont2][*x+cont1]=1;}
                      }
                      (*mapa).mapa[*y+2*cont2][*x+2*cont1]='B';
                      (*mapa).mapa[*y+cont2][*x+cont1]='P';
                      (*mapa).mapa[*y][*x]= '@';
                      *y=*y+cont2;
                      *x=*x+cont1;  

              }
          }
  }

}

void movimentos_move(int *x,int *y,int gFlag, MAPA *mapa){
    if((*mapa).mapa[*y][*x]=='P'){


    int cont1, cont2;
    if(gFlag == 1)
    {
      cont1=-1; cont2=0;
      if(*x+cont1>=0 && *x+cont1<12 && *y+cont2>=0 && *y+cont2<12){
        TROCA_VAZIO(mapa, x, y, cont1, cont2);}

      if(*x+2*cont1>=0 && *x+2*cont1<12 && *y+2*cont2>=0 && *y+2*cont2<12){
        TROCA_CAIXA(x, y, cont1, cont2, mapa);}


    }
  
    else if(gFlag == 2)
    {
        cont1=1; cont2=0;
      if(*x+cont1>=0 && *x+cont1<12 && *y+cont2>=0 && *y+cont2<12){
        TROCA_VAZIO(mapa, x, y, cont1, cont2);}

      if(*x+2*cont1>=0 && *x+2*cont1<12 && *y+2*cont2>=0 && *y+2*cont2<12){
        TROCA_CAIXA(x, y, cont1, cont2, mapa);}


    }
    else if(gFlag == 3)
    {
        cont1=0; cont2=1;
      if(*x+cont1>=0 && *x+cont1<12 && *y+cont2>=0 && *y+cont2<12){
        TROCA_VAZIO(mapa, x, y, cont1, cont2);}

     if(*x+2*cont1>=0 && *x+2*cont1<12 && *y+2*cont2>=0 && *y+2*cont2<12){
        TROCA_CAIXA(x, y, cont1, cont2, mapa);}


    }
  
    else if(gFlag == 4)
    {
        cont1=0; cont2=-1;
      if(*x+cont1>=0 && *x+cont1<12 && *y+cont2>=0 && *y+cont2<12){
        TROCA_VAZIO(mapa, x, y, cont1, cont2);}

      if(*x+2*cont1>=0 && *x+2*cont1<12 && *y+2*cont2>=0 && *y+2*cont2<12){
        TROCA_CAIXA(x, y, cont1, cont2, mapa);}


    }
    
    }
}