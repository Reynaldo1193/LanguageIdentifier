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

    int i = 0;
    for(i=0; i < count; i++){
            printf("Esta es la plabra %d:\t%s\n",i+1,n[i]);
        int espaniol=0,ingles=0,portugues=0,aleman=0,frances=0,italiano=0,chino=0,japones=0;
    }
}
