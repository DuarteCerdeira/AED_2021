/******************************************************************************
 *
 * File Name: queue.h
 *	      (c) 2010 AED
 * Author:    AED team
 * Revision:  v2.3 ACR
 *            v4.0 AED Team, Nov 2019
 *
 * NAME
 *     queue.h - prototypes
 *
 * SYNOPSIS
 *     #include <stdlib.h>
 *     #include <stdio.h>
 *     #include <string.h>
 *
 * DESCRIPTION
 *		Definitions useful to implement breath scan
 *
 * DIAGNOSTICS
 *
 *****************************************************************************/

#ifndef QUEUE
#define QUEUE

#include "Item.h"

typedef struct _queue Queue;
typedef struct _element Element;


Queue *QueueNew();               /* creates empty list */
Item GetFirst(Queue*);           /* get first element of the queue */
void InsertLast(Queue*, Item);   /* insertion at the end of queue */

#endif

