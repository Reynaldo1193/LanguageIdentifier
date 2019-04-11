#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void IngresarDatos (char* c);
void Transposicion (char* porCifrar, int tamanio, int llave);
int Menu();

int main() {
  char c []="necreonoteitninnevrutsetnheinnodtohmeoeobesnmrxiubratslelriaerniavsair";
  int llave = 0;

  //IngresarDatos(c);
  int tamanio = strlen(c);

  for(llave = 4;llave <= 8; llave++){
   Transposicion(c,tamanio,llave);
  }
  return 0;
}

void IngresarDatos (char* c){
  printf("Ingrese la caddena a Cifrar: \n");
  fgets(c,255,stdin);
}

void Transposicion (char* porCifrar, int tamanio, int llave){
  char matriz [10][llave];
  int count = 0;
  //printf("%s\n\n",porCifrar);
  for (int i = 0; i < 10; i++){
    for (int j = 0;  j < 10; j++) {
      if(count == tamanio-1){
        matriz[i][j] = '*';
        //printf("%c\n",matriz[i][j]);
      }
      else{
        matriz[i][j] = porCifrar[count];
         //printf("%c\n",matriz[i][j]);
        count++;
      }
    }
  }

  printf("\n\n\nTu cadena cifrada con la llave %d: \n",llave);
  for (int i = 0; i < llave; i++) {
    for (int j = 0; j < llave; j++) {
      printf("%c",matriz[j][i]);
    }
  }
}
//necreonoteitninnevrutsetnheinnodtohmeoeobesnmrxiubratslelriaerniavsair
