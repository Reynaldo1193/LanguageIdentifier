#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main () {
    char texto[1000];
    printf("Ingresa el texto:\n");
    fgets(texto,1000,stdin);

    // Returns first token
    char *token = strtok(texto, " ");
    char n[20][50];
    int count=0;

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        strcpy(n[count],token);
        token = strtok(NULL, " ");
        count++;
    }

    //Begining the reading of the files
    int i = 0,indice=0;
    int espaniol=0,ingles=0,portugues=0,aleman=0,frances=0,italiano=0,chino=0,japones=0;
    char ch, fileWords[25];
    FILE *fp;

    fp = fopen("espaniol.txt", "r"); // read mode

    if (fp == NULL)
    {
      perror("Error while opening the file.\n");
      return 1;
    }

    //printf("The contents of the file are:\n");

    while((ch = fgetc(fp)) != EOF){
      if (ch == '\n'){
        fileWords[indice+1]='\0';
        //printf("%s\n",fileWords);
        for (int j = 0; j <= count; j++) {
          if(strcmp(fileWords,n[j]) == 0){
             espaniol ++;
             printf("%s\t",n[j]);
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
