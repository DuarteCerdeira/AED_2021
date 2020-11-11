#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "defs.h"

typedef struct edge Edge;

Edge *EDGE(int, int, Item);

typedef struct graph Graph;

Graph *GRAPHinit(int);

void GRAPHinsertE(Graph *, Edge *);
void GRAPHprint(Graph *, char **);
void GRAPGdestroy(Graph *);

#endif
