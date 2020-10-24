#include <stdio.h>

typedef struct _Line_{
  int storage;
  struct _Line_ *next;
} Line;

int *funcao_1(int *tab1, int l, int r)
{
  int i, j;                             
  for (i = l + 1; i <= r; i++)          // 1 + N + (N - 1) = 2N
    for (j = i; j > l; j--) {           // 1 + (N(N - 1) / 2) + 1 + (N(N - 1) / 2) = 2 + 2(N(N - 1) / 2)
      int x;                            
      if (tab1[j] < tab1[j - 1]) {      // | 3(N(N - 1) / 2)
        x = tab1[j];                    // | 2(N(N - 1) / 2)
        tab1[j] = tab1[j - 1];          // | 3(N(N - 1) / 2)
        tab1[j - 1] = x;                // | 2(N(N - 1) / 2)
      }                                 // 10(N(N - 1) / 2)
    }
  return tab1;
}                                       // = 12(N(N - 1) / 2) + 2N + 2


float funcao_2(float *tab2, int l, int r)
{
  int i, j, k, contador=0;                                  // 1
  float v, out=0;                                           // 1
  v = tab2[r]; i = l; j = r;                                // 4
  while (i <= r && test(tab2[i], v, i)) {                   // N + 1 + N = 2N + 1
    out = out + tab2[i];                                    // 3N
    contador += 1;                                          // 2N
    i++;                                                    // N
  }
  printf("Elementos que passam o teste:%d\n", contador);
  printf("A sua soma é %g\n", out);
  for (j = l; j <= r; j++)                                  // 1 + N + 1 + N = 2 + 2N
    for (k = r; k > l+1; k -=(k-l)/2)                       // N + Nlg(N - 1) + N + Nlg(N - 1) = 2Nlg(N - 1) + 2N
      tab2[j] += tab2[k];                                   // 3Nlg(N - 1)
  return out;
}                                                           // 12N + 5Nlg(N - 1) + 9

int funcao_3(int N)
{
  if (N < 1)
    return 0;
  else return N + funcao_3(N/2);
}

void funcao_4 (Line* mat, int N) 
{
  if (N == 0) return;
    mat->storage = (int*) malloc (N * sizeof(int));
  if (mat->storage == NULL) {
    fprintf(stderr,"ERRO: Memoria insuficientenn");
    exit(2);
  }
  mat->next = (Line*) malloc(1*sizeof(Line));
  if (mat->next == NULL) {
    fprintf(stderr,"ERRO: Memoria insuficientenn");
    exit(3);
  }
  funcao_4(mat->next, N-1);
}