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
  if (root != NULL) {
    InFixed(root -> left, n + 1);
    spaces(n);
    printf("%d\n", root -> value);
    InFixed(root -> right, n + 1);
  }

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
  if (root != NULL) {
    PosFixed(root -> left, n + 1);
    PosFixed(root -> right, n + 1);
    spaces(n);
    printf("%d\n", root -> value);
  }

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
  if (root == NULL)
    return;

  spaces(n);
  printf("%d\n", root -> value);
  sweepDepth(root -> left, n + 1);
  sweepDepth(root -> right, n + 1);

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
  int n = 0;
  Node *h = root;
  Queue *q = QueueNew();

  root -> level = 0;
  while (h != NULL) {
    n = h -> level;
    spaces(n);
    printf("%d\n", h -> value);
    if (h -> left) {
      InsertLast(q, h -> left);
      h -> left -> level = n + 1;
    }
    if (h -> right) {
      InsertLast(q, h -> right);
      h -> right -> level = n + 1;
    }

    h = GetFirst(q);
  }
  free(q);

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


Boolean isOrdered(Node *root, int min, int max)
{
  if (root == NULL)
    return TRUE;

  if (root -> value < min || root -> value > max)
    return FALSE;

  if (isOrdered(root -> left, min, root -> value) && isOrdered(root -> right, root -> value, max))
    return TRUE;

  return FALSE;
}

Boolean isTreeOrdered(Node * root)
{
  return isOrdered(root, INT_MIN, INT_MAX);
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

int TreeHeight(Node * root)
{
  int lh = 0, rh = 0;

  if (root == NULL)
   return 0;

  lh = TreeHeight(root -> left);
  rh = TreeHeight(root -> right);

  return lh > rh ? lh + 1 : rh + 1;

}

Boolean isTreeBalanced(Node * root)
{
  int lh, rh;

  if (root == NULL)
    return TRUE;

  if (root -> left == NULL && root -> right == NULL)
    return TRUE;

  lh = TreeHeight(root -> left);
  rh = TreeHeight(root -> right);

  if (lh - rh > 1 || lh - rh < -1)
    return FALSE;

  if (isTreeBalanced(root -> left) && isTreeBalanced(root -> right))
    return TRUE;

  return FALSE;
}

void removeFirstLeaf(Node *root)
{
  Node *aux, *left, *right;
  Queue *q;

  if (root == NULL)
    return;

  aux = root;
  q = QueueNew();

  while (aux != NULL) {
    left = aux -> left;
    right = aux -> right;

    if (left)
      InsertLast(q, left);
    if (right)
      InsertLast(q, right);

    if (left -> left == NULL && left -> right == NULL) {
      aux -> left = NULL;
      free(left);
      return;
    }
    if (right -> left == NULL && right -> right == NULL) {
      aux -> right = NULL;
      free(right);
      return;
    }
    
    aux = GetFirst(q);
  }
}
