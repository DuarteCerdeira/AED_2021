#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adjmatrix.h"

int main(int argc, char **argv)
{
  char *ficheiroIn;
  char *ficheiroName;
  char *ficheiroOut;
  int sizeFicheiro;

  Graph *grafo = NULL;

  if (argc < 2) {
    printf("Argumento errado\n");
    exit(0);
  }

  ficheiroIn = (char *) malloc(strlen(argv[1]) + 1);
  strcpy(ficheiroIn, argv[1]);

  if (strcmp( strrchr(ficheiroIn, '.'), ".adj" ) != 0) {
    printf("Extensão de ficheiro errada\n");
    exit(0);
  }

  GRAPHfill(&grafo, ficheiroIn);

  sizeFicheiro = strlen(ficheiroIn) - strlen(".adj");

  ficheiroName = (char *) malloc( sizeFicheiro + 1 );
  strncpy( ficheiroName, ficheiroIn, sizeFicheiro );
  ficheiroName[sizeFicheiro] = '\0';

  ficheiroOut = (char *) malloc( sizeFicheiro + strlen(".edge") + 1 );
  strcpy( ficheiroOut, ficheiroName );
  ficheiroOut = strcat( ficheiroOut, ".edge" );

  GRAPHprint(grafo, ficheiroOut);

  free(ficheiroIn);
  free(ficheiroName);
  free(ficheiroOut);
  GRAPHdestroy(grafo);

  return 0;
}
