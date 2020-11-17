#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

int main(int argc, char **argv)
{
    char *ficheiroIn;
    char *ficheiroName;
    char *ficheiroOut;
    int sizeFicheiro;
    Grafo *grafo=NULL;

    if (argc < 2)
    {
        printf("Argumento errado\n");
        exit(0);
    }

    ficheiroIn = (char *)malloc(strlen(argv[1]) + 1);
    strcpy(ficheiroIn, argv[1]);

    if (strcmp(strrchr(ficheiroIn, '.'), ".edge") != 0)
    {
        printf("Extensão de ficheiro errada\n");
        exit(0);
    }

    /*Codigo criacao estrutura*/


    /*Codigo para escrita de ficheiro*/
    sizeFicheiro = strlen(ficheiroIn) - strlen(".edge");

    ficheiroName = (char *) malloc( sizeFicheiro + 1 );
    strncpy( ficheiroName, ficheiroIn, sizeFicheiro );
    ficheiroName[sizeFicheiro] = '\0';

    ficheiroOut = (char *) malloc( sizeFicheiro + strlen(".ladj") + 1 );
    strcpy( ficheiroOut, ficheiroName );
    ficheiroOut = strcat( ficheiroOut, ".ladj" );

    GRAPHprint(grafo, ficheiroOut);

    free(ficheiroIn);
    free(ficheiroName);
    free(ficheiroOut);
    GRAPHdestroy(grafo);

    return 0;
}
