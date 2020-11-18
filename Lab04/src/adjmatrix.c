#include <stdio.h>
#include <stdlib.h>

#include "adjmatrix.h"

struct edge {
  int v1;
  int v2;
  int weight;
};

struct graph {
  int V;
  int E;
  int *valency;
  int **adjmatrix;
};

Edge *EDGE(int v1, int v2, int cost)
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
  G -> adjmatrix = (int **) malloc(V * sizeof(int *));
  for (i = 0; i < V; i++) {
    G -> adjmatrix[i] = (int *) malloc(V * sizeof(int));
    for (j = 0; j < V; j++)
      G -> adjmatrix[i][j] = 0;
    G -> valency[i] = 0;
  }

  return G;
}

void GRAPHfill(Graph **G, char *ficheiro)
{
  FILE *f;
  int V = 0;
  int c = 0;
  int i, j;

  f = fopen(ficheiro, "r");

  fscanf(f, "%d", &V);

  *G = GRAPHinit(V);

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++) {
      fscanf(f, "%d", &c);
      if (c != 0 && i < j)
        GRAPHinsertE(*G, EDGE(i, j, c));
    }
  fclose(f);
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

  free(E);
}

void GRAPHprint(Graph *G, char *ficheiro)
{
  int i, j,graumaximus=0;
  double densidade=(double)(G->E)/G->V;
  FILE *f;

  f = fopen(ficheiro, "w");

  fprintf(f, "%d %d\n", G -> V, G -> E);

  for (i = 0; i < G -> V; i++)
    for (j = 0; j < G -> V; j++) {
      if (G -> adjmatrix[i][j] != 0 && i < j)
        fprintf(f, "%d %d %d\n", i, j, G -> adjmatrix[i][j]);
    }
  
  for (i = 0; i < G->V; i++)  
    if(graumaximus<G->valency[i])
      graumaximus=G->valency[i];

  printf("%.3lf %d\n",densidade,graumaximus);

  fclose(f);
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
