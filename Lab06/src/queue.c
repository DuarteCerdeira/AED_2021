/******************************************************************************
* (c) 2010-2020 AED Team

* Last mod: abl 2020-05-26
*
* DESCRIPTION
*	Auxiliary functions for Tree lab - QUEUE
*
******************************************************************************/

#include "Item.h"
#include "tree.h"
#include "queue.h"

struct _element {
  Item this;
  int level;
  struct _element *next;
};

struct _queue {
  Element *first;
  Element *last;
};


/******************************************************************************
 * QueueNew()
 *
 * Arguments:
 *
 * Returns: a pointer to Queue
 * Side-Effects: none
 *
 * Description: creates an empty queue
 *
 *****************************************************************************/

Queue *QueueNew()
{
  Queue * q = malloc(sizeof(Queue));
  q->first = NULL;
  q->last = NULL;
  return q;
}


/******************************************************************************
 * InsertLast()
 *
 * Arguments: queue - a queue
 *            this - a "node" to insert last in the queue
 *
 * Returns: void
 * Side-Effects: none
 *
 * Description: inserts an element at the end of a queue
 *
 *****************************************************************************/

void InsertLast(Queue* queue, Item this)
{
  Element *elem;

  if (queue == NULL || this == NULL)
     return;

  elem = malloc(sizeof(Element));
  elem->this = this;
  elem->next = NULL;
  if (queue == NULL)
     return;
  if (queue->last != NULL)
     queue->last->next = elem;
  queue->last = elem;
  if (queue->first == NULL)
     queue->first = elem;

  return;
}


/******************************************************************************
 * GetFirst()
 *
 * Arguments: queue - a queue
 *
 * Returns: pointer to first node in queue
 * Side-Effects: none
 *
 * Description: prints the tree in the Breathfirst format
 *
 *****************************************************************************/

Item GetFirst(Queue* queue)
{
  Element *q = queue->first;
  Item this = (Item) NULL;

  if (queue->first != NULL) {
     queue->first = queue->first->next;

     this = q->this;
     free(q);
  }

  return this;
}

