#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "defs.h"

typedef struct edge Edge;

Edge *EDGE(int, int, int);

typedef struct graph Graph;

Graph *GRAPHinit(int);

void GRAPHfill(Graph **, char *);
void GRAPHinsertE(Graph *, Edge *);
void GRAPHprint(Graph *, char *);
void GRAPHdestroy(Graph *);

void GraphClique(Graph *grafo, int);

#endif
