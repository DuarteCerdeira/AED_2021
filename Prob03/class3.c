#include <stdio.h>

int *funcao_1(int *tab1, int l, int r)
{
  int i, j;
  for (i = l + 1; i <= r; i++)
    for (j = i; j > l; j--)
    {
      int x;
      if (tab1[j] < tab1[j - 1])
      {
        x = tab1[j];
        tab1[j] = tab1[j - 1];
        tab1[j - 1] = x;
      }
    }
  return tab1;
}
