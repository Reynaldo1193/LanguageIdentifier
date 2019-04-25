#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void IngresarDatos (char* c);
void Transposicion (char* porCifrar, int tamanio, int llave);
void LanguageIdentifier(char **matriz);
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
  int filas = (int)(tamanio/llave);
  char matriz [llave][filas];
  int count = 0;
  for (int j = 0; j < filas; j++){
    for (int i = 0;  i < llave; i++) {
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
  printf("el numero de filas necesarias es: %d\n",filas );
  printf("\nTu cadena cifrada con la llave %d: \n",llave);
  for (int j = 0; j < llave; j++) {
    for (int i = 0; i < filas; i++) {
      printf("%c",matriz[j][i]);
    }
    //printf("\t\talto\n");
  }
  LanguageIdentifier(matriz);
  printf("\n" );
}

void LanguageIdentifier(char **matriz){
    int indice =0, count=0;
    int espaniol=0;
    char ch, fileWords[25];
    FILE *fp;

    fp = fopen("espaniol.txt", "r"); // read mode

    if (fp == NULL)
    {
      perror("Error while opening the file.\n");
      return 1;
    }

    while((ch = fgetc(fp)) != EOF){
      if (ch == '\n'){
        fileWords[indice+1]='\0';
        //printf("%s\n",fileWords);
        for (int j = 0; j <= count; j++) {
          if(strstr(matriz[j],fileWords) != nullptr ){
             espaniol ++;
             printf("%s\t",matriz[j]);
             printf("%s\n",fileWords);
          }
        }
        memset(fileWords, 0, sizeof(fileWords));
        indice = 0;
      }
      else{
        fileWords[indice] = ch;
        indice++;
      }
    }

    float porcentaje = (((float) espaniol)/((float)count))*100;
    //printf("%d\n",count);
    printf("tienes un %c%.2f de posibilidades de que sea espaniol\n",'%',porcentaje);

    fclose(fp);
    /*for(i=0; i < count; i++){
        printf("Esta es la plabra %d:\t%s\n",i+1,n[i]);
    }*/
    memset(fileWords, 0, sizeof(fileWords));
}
//necreonoteitninnevrutsetnheinnodtohmeoeobesnmrxiubratslelriaerniavsair
