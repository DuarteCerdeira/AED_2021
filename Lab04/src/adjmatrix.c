#include <stdio.h>
#include <stdlib.h>

#include "adjmatrix.h"

struct edge {
  int v1;
  int v2;
  Item weight;
};

struct graph {
  int V;
  int E;
  int *valency;
  int **adjmatrix;
};

Edge *EDGE(int v1, int v2, Item cost)
{
  Edge *E = (Edge *) malloc(sizeof(struct edge));
  E -> v1 = v1;
  E -> v2 = v2;
  E -> weight = cost;
  return E;
}


Graph *GRAPHinit(int V)
{
  int i, j;
  Graph *G = (Graph *) malloc(sizeof(struct graph));
  G -> V = V;
  G -> E = 0;
  G -> valency = (int *) malloc(V * sizeof(int));
  G -> adjmatrix = (Edge **) malloc(V * sizeof(int *));
  for (i = 0; i < V; i++) {
    for (j = 0; j < V; j++)
      G -> adjmatrix[i][j] = 0;
    G -> valency[i] = 0;
  }

  return G;
}

void GRAPHinsertE(Graph *G, Edge *E)
{
  int i = E -> v1;
  int j = E -> v2;
  int w = E -> weight;

  G -> adjmatrix[i][j] = w;
  G -> valency[i]++;
  G -> adjmatrix[j][i] = w;
  G -> valency[j]++;
  G -> E++;
}

void GRAPHprint(Graph *G, char **ficheiro)
{
  int i, j;
  FILE *fpt;

  fpt = fopen(ficheiro, "w");

  for (i = 0; i < G -> V; i++)
    for (J = 0; j < G -> V; j++)
      if (G -> adjmatrix[i][j] != 0 && i < j)
        fprintf(fpt, "%d %d %d\n", i, j, G -> adjmatrix[i][j]);

  fclose(fpt);
}

void GRAPHdestroy(Graph *G)
{
  int i;

  for (i = 0; i < G -> V; i++)
    free(G -> adjmatrix[i]);
  free(G -> adjmatrix);
  free(G -> valency);
  free(G);
}
