/******************************************************************************
* (c) 2010-2020 AED Team
* Revisions: v2.1 ACR / v3.0 AED Team Out 2013 / v4.0 AED Team, Nov 2019
* Last mod: abl 2020-05-19
*
* DESCRIPTION
*	Auxiliary functions for Tree lab
*
* COMMENTS
*   Code for distribution
******************************************************************************/

#include <limits.h>
#include "tree.h"
#include "queue.h"


struct _Node {
  int value;
  int level;
  struct _Node *left, *right;
};




/******************************************************************************
 * AllocNode()
 *
 * Arguments: (none)
 * Returns: new node
 * Side-Effects: none
 *
 * Description: allocates space for a new node
 *
 *****************************************************************************/

Node *AllocNode() {
  return ((Node *) malloc(sizeof(Node)));
}


/******************************************************************************
 * NewNode()
 *
 * Arguments: integer
 * Returns: new node
 * Side-Effects: none
 *
 * Description: creates a new node with a integer value
 *
 *****************************************************************************/

Node *NewNode(int num)
{
  Node *aux;

  if (num==-1)
    return NULL;

  aux = AllocNode();
  aux->value = num;
  aux->level = -1;
  aux->right = aux->left = NULL;

  return aux;
}


/******************************************************************************
 * Construct()
 *
 * Arguments: input file and filename
 * Returns: pointer to root node of the tree
 * Side-Effects: none
 *
 * Description: constructs a tree reading integer numbers from file
 *
 *****************************************************************************/

Node *Construct(FILE *fp, char * filename)
{
  Node *nodeRoot;
  int num;

  if (fscanf(fp,"%d", &num) == EOF)  {
    fprintf(stderr,
            "File %s has an insufficient number of values.  Please correct.\n",
            filename);
    exit(0);
  }

  if ((nodeRoot = NewNode(num)) != NULL) {
    /* links to child */
    nodeRoot->left  = Construct(fp, filename);
    nodeRoot->right = Construct(fp, filename);
  }

  return nodeRoot;
}


/******************************************************************************
 * FreeTree()
 *
 * Arguments: node - a tree root
 *
 * Returns: void
 * Side-Effects: none
 *
 * Description: frees the tree
 *
 *****************************************************************************/

void FreeTree(Node * root)
{
  if (root != NULL) {
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
  }
}


/******************************************************************************
 * spaces()
 *
 * Arguments: n - number of spaces
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints n spaces
 *
 *****************************************************************************/

void spaces(int n)
{
  int i;

  for (i = 0; i < n; i++)
    printf("  ");
  return;
}


/******************************************************************************
 * PreFixed()
 *
 * Arguments: root - root of the tree
 *	      n - height of the tree
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints the tree in the PreFix format
 *
 *****************************************************************************/

void PreFixed(Node *root, int n)
{
  if (root != NULL) {
    spaces(n);
    printf("%d\n", root->value);
    PreFixed(root->left, n + 1);
    PreFixed(root->right, n + 1);
  }

  return;
}


/******************************************************************************
 * InFixed()
 *
 * Arguments: root - root of the tree
 *	      n - height of the tree
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints the tree in the InFix format
 *
 *****************************************************************************/

void InFixed(Node *root, int n)
{

  /* Insert code */

  return;
}


/******************************************************************************
 * PosFixed()
 *
 * Arguments: root - root of the tree
 *	      n - height of the tree
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints the tree in the PosFix format
 *
 *****************************************************************************/

void PosFixed(Node *root, int n)
{

  /* Insert code */

  return;
}


/******************************************************************************
 * sweepDepth()
 *
 * Arguments: root - root of the tree
 *	      n - height of the tree
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints the tree in the depthfirst format
 *
 *****************************************************************************/

void sweepDepth(Node *root, int n)
{

  /* Insert code */

  return;
}


/******************************************************************************
 * sweepBreadth()
 *
 * Arguments: root - root of the tree
 *
 * Returns: void
 * Side-Effects: none
 *
 * Description: prints the tree in the Breathfirst format
 *
 *****************************************************************************/

void sweepBreadth(Node *root)
{

  /* Insert code */

  return;
}

/******************************************************************************
 * IsTreeOrdered()
 *
 * Arguments: node - a tree root
 *
 *
 * Returns: Boolean (TRUE if the tree is ordered, FALSE otherwise)
 * Side-Effects: none
 *
 * Description: checks if a tree is ordered
 *
 *****************************************************************************/

Boolean isTreeOrdered(Node * root)
{

  /* Insert code */

  return TRUE;
}


/******************************************************************************
 * IsTreeBalanced()
 *
 * Arguments: node - a tree root
 *
 *
 * Returns: Boolean (TRUE if the tree is AVL balanced, FALSE otherwise)
 * Side-Effects: none
 *
 * Description: checks if a tree is AVL balanced
 *
 *****************************************************************************/

Boolean isTreeBalanced(Node * root)
{

  /* Insert code */

  return FALSE;
}
