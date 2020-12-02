/******************************************************************************
 * File Name: simproc.c
 *	      (c) 2010 AED
 * Author:    AED Team
 * Revision:  v2.3 ACR
 *            v3.0 LMS
 * NAME
 *      Heap (Acervo)
 * SYNOPSIS
 *	#include <stdlib.h>
 *	#include <stdio.h>
 *	#include <malloc.h>
 * DESCRIPTION Exemple of client using  heap for storing a set of Integers
 * tested
 *****************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

typedef struct _proc_data
{
  int pid;
  int prio;
} ProcData;
int currPID = 0;

/* This is just an example; change as required for your application */
int Heapsize = 16;

/******************************************************************************
 * PrintNumero()
 *
 * Arguments: hi - pointer to number to be printed, masked as an item
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: Print function with abstract type to be passed as argument;
 *              Prints a number
 *
 *****************************************************************************/

void PrintNum(Item hi)
{
  ProcData *proc = (ProcData *)hi;

  printf("[7m%3d[0m/[1m%3d[0m ", proc->pid, proc->prio);

  return;
}

/******************************************************************************
 * PrintProcData()
 *
 * Arguments: h - heap representing process data
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: Prints header for process data and call print of heap
 *
 *****************************************************************************/

int PrintProcData(Heap *h)
{
  int status = 0;
  printf("+------------+\n");
  printf("|   index    |\n");
  printf("+------------+\n");
  printf("| pid / prio |\n");
  printf("+------------+");
  status = PrintHeap(h);

  return (status);
}

/******************************************************************************
 * LessNumero()
 *
 * Arguments: a, b - 2 Items to be compared
 * Returns: Integer with the results of the comparison
 * Side-Effects: none
 *
 * Description: Comparison function with abstract type to be passed as argument;
 *              Function is specific for "int" variables
 *
 *****************************************************************************/

int LessNum(Item a, Item b)
{
  ProcData *proca = (ProcData *)a;
  ProcData *procb = (ProcData *)b;
  int aa, bb;

  aa = proca->prio;
  bb = procb->prio;

  return (aa < bb);
}

/******************************************************************************
 * InsertNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the insert option
 *
 *****************************************************************************/

void InsertNum(Heap *h)
{
  ProcData *proc;
  int num, status;

  printf("Number: ");
  status = scanf("%d", &num);
  if (status == 1)
  {
    proc = (ProcData *)malloc(sizeof(ProcData));
    proc->pid = currPID;
    proc->prio = num;
    currPID++;
    if (Insert(h, (Item)proc) == 0)
      free(proc);
    printf("\nFinal Heap\n");
    (void)PrintProcData(h);
  }

  return;
}

/******************************************************************************
 * DirectInsertNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the insert option
 *
 *****************************************************************************/

void DirectInsertNum(Heap *h)
{
  ProcData *proc;
  int num, status;

  printf("Number: ");
  status = scanf("%d", &num);
  if (status == 1)
  {
    proc = (ProcData *)malloc(sizeof(ProcData));
    proc->pid = currPID;
    proc->prio = num;
    currPID++;
    if (Direct_Insert(h, (Item)proc) == 0)
      free(proc);
    printf("\nFinal Heap\n");
    (void)PrintProcData(h);
  }

  return;
}

/******************************************************************************
 * ModifyNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the modify option
 *
 *****************************************************************************/

void ModifyNum(Heap *h)
{
  int index;
  int novovalor;
  ProcData *newproc = (ProcData *)malloc(sizeof(ProcData)), *oldproc;

  printf("Index of the element to change: ");
  scanf("%d", &index);
  printf("New priority: ");
  scanf("%d", &novovalor);
  oldproc = (ProcData *)GetIndex(h, index);
  if (oldproc != (ProcData *)NULL)
  {
    newproc->pid = oldproc->pid;
    newproc->prio = novovalor;
    Modify(h, index, (Item)newproc);
  }
  (void)PrintProcData(h);

  return;
}

/******************************************************************************
 * RemoveMaxNum()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the removemax option
 *
 *****************************************************************************/

void RemoveMaxNum(Heap *h)
{
  (void)RemoveMax(h);
  (void)PrintProcData(h);

  return;
}

/******************************************************************************
 * HeapSortOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the heapsort option
 *
 *****************************************************************************/

void HeapSortOption(Heap *h)
{
  HeapSort(h);
  (void)PrintProcData(h);

  return;
}

/******************************************************************************
 * VerifyHeapOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the verify heap option
 *
 *****************************************************************************/

void VerifyHeapOption(Heap *h)
{
  if (PrintProcData(h) != 0)
  {
    if (VerifyHeap(h))
      printf("*************** It is an heap\n");
    else
      printf("*************** It is not an heap\n");
  }
  return;
}

/******************************************************************************
 * HeapifyOption()
 *
 * Arguments: h - pointer to heap
 * Returns: void
 * Side-Effects: none
 *
 * Description: Interface for the heapify option
 *
 *****************************************************************************/

void HeapifyOption(Heap *h)
{
  Heapify(h);
  (void)PrintProcData(h);

  return;
}

/******************************************************************************
 * Example()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Example heap of size Heapsize, automatic insert from 0 to 11
 *
 *****************************************************************************/

void Example(Heap *h)
{
  ProcData *proc;
  int i, n = Heapsize;

  for (i = 0; i < n; i++)
  {
    proc = (ProcData *)malloc(sizeof(ProcData));
    proc->pid = currPID;
    proc->prio = i;
    currPID++;
    if (Insert(h, (Item)proc) == 0)
      free(proc);
  }
  printf("\nFinal Heap\n");
  (void)PrintProcData(h);

  return; /*h */
}

/******************************************************************************
 * Help()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Print menu help
 *
 *****************************************************************************/

void Help()
{
  printf("----------------------------------------------------------------------------------------\n");
  printf("insert:        i - insert a number in the heap ensuring the heap condition\n");
  printf("modify:        m - modify an heap element and restores the heap condition\n");
  printf("removemax:     r - remove the first element of the heap and restores the heap condition\n");
  printf("direct insert: d - insert a number in the heap without ensuring the heap condition\n");
  printf("verify:        v - verify if it is an heap\n");
  printf("print:         p - print the heap\n");
  printf("heapify:       f - restore the heap condition\n");
  printf("sort:          s - sort the heap\n");
  printf("example:       e - heap example with 16 numbers\n");
  printf("clean:         c - clean the heap (removes all elements)\n");
  printf("help:          h - show this help\n");
  printf("quit:          q - quit\n");
  printf("----------------------------------------------------------------------------------------\n");

  return;
}

/******************************************************************************
 * PrintOptions()
 *
 * Arguments: none
 * Returns: void
 * Side-Effects: none
 *
 * Description: Print interface, provides Heap operation options
 *
 *****************************************************************************/

void PrintOptions()
{
  printf("----------------\n    OPTIONS\n----------------\n");
  printf("insert:        i   ||   direct insert: d\n");
  printf("modify:        m   ||   removemax:     r\n");
  printf("verify:        v   ||   print:         p\n");
  printf("heapify:       f   ||   sort:          s\n");
  printf("example:       e   ||   clean:         c\n");
  printf("help:          h   ||   quit:          q\n");
  printf("prio remove:   x\n\n");

  return;
}


  void PriorityRemove(Heap *h)
{
  int prio;
  ProcData *prio_limit = (ProcData *)malloc(sizeof(ProcData));

  printf("Threshold priority: ");
  scanf("%d", &prio);
  prio_limit->pid = -1;
  prio_limit->prio = prio;
  SortedPrioRemove(h, (Item)prio_limit);
  (void)PrintProcData(h);

  free(prio_limit);
  return;
}

/******************************************************************************
 * main()
 *
 * Arguments: argc - number of comand line arguments
 *            argc - array of pointers to command line arguments
 * Returns: success or error
 * Side-Effects: none
 *
 * Description: Main interface, allow the choice of available operations
 *				insert, modify, removemax, sort and exit
 *
 *****************************************************************************/

int main(int argc, char **argv)
{
  char command[2];
  Heap *h;

  /* Heapsize instantiated and initialized at the top of this file */
  h = NewHeap(Heapsize, LessNum, PrintNum);

  while (!feof(stdin))
  {
    PrintOptions();
    printf("Heap> ");
    scanf("%s", command);
    switch (command[0])
    {
    case 'i':
      InsertNum(h);
      break;
    case 'm':
      ModifyNum(h);
      break;
    case 'r':
      RemoveMaxNum(h);
      break;
    case 's':
      HeapSortOption(h);
      break;
    case 'e':
      Example(h);
      break;
    case 'p':
      (void)PrintProcData(h);
      break;
    case 'd':
      DirectInsertNum(h);
      break;
    case 'v':
      VerifyHeapOption(h);
      break;
    case ('f'):
      HeapifyOption(h);
      break;
    case ('c'):
      CleanHeap(h);
      break;
    case 'h':
      Help();
      break;
    case 'q':
      FreeHeap(h);
      return 0;
    case 'x':
      PriorityRemove(h);
      break;
    default:
      printf("\nInvalid option \"%s\"; please insert a valid option\n\n",
             command);
    }
  }

  return 0;
}
