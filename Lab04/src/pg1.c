#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adjmatrix.h"

int main(int argc, char **argv)
{
  char *ficheiroIn;
  char *ficheiroName
  char *ficheiroOut;
  int ficheiroSize;

  Graph *grafo;
  Edge *aresta;

  FILE *in;

  if (argc < 2) {
    printf("Argumento errado");
    exit(0);
  }

  ficheiroIn = (char *) malloc(strlen(argv[1]) + 1);
  ficheiroName = (char *) malloc(ficheiroSize + 1);
  ficheiroOut = (char *) malloc(ficheiroSize + strlen(".edge") + 1);

  strcpy(ficheiroIn, argv[1]);
  if (strmcp(strrchr(ficheiroIn, '.'), ".adj") != 0) {
    printf("Extensao de ficheiro errada");
    exit(0);
  }

  ficheiroSize = strlen(ficheiroIn) - strlen(".adj");

  strncpy(ficheiroName, ficheiroIn, ficheiroSize);
  strcpy(ficheiroOut, ficheiroName);
  strcat(ficheiroOut, ".edge");

  in = fopen(ficheiroIn, "r");




  return 0;
}
