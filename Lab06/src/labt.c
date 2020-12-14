/******************************************************************************
* (c) 2010-2020 AED Team
* Revisions: v2.1 ACR / v3.0 AED Team Out 2013 / v4.0 AED Team, Nov 2019
* Last mod: abl 2020-05-19
*
* DESCRIPTION
*   Main program for Tree lab
*
* COMMENTS
*   Code for distribution
******************************************************************************/
#include "tree.h"
#include "queue.h"


/******************************************************************************
 * main()
 *
 * Arguments: argc - number of comand line arguments
 *            argv - array of pointers to command line arguments
 * Returns: success or error
 * Side-Effects: none
 *
 * Description:
 *  Read in tree from file, create data. Perform dumps and sweeps with output.
 *****************************************************************************/

int main(int argc, char *argv[])
{
    Node *root;
    FILE *fp;
    char *yno = " ? ", *ynb = " ? ";

    /* must have at least one argument besides the exec name */
    if (argc < 2) {
        fprintf(stderr,
            "This program must have at least one argument besides the exec name.\n");
        exit(1);
    }

    /* open tree data file */
    fp = (FILE *) fopen(argv[1], "r");
    if (fp == (FILE *) NULL) {
        fprintf(stderr, "File %s cannot be read.  Please correct.\n", argv[1]);
        exit(2);
    }

    root = Construct(fp, argv[1]);
    fclose(fp);

    printf("\nPreFix dump:\n");
    PreFixed(root, 0);
    putchar('\n');

    printf("\nIn-Fix:\n");
    InFixed(root, 0);
    putchar('\n');

    printf("\nPos-Fix:\n");
    PosFixed(root, 0);
    putchar('\n');

    printf("Depth First:\n");
    sweepDepth(root, 0);
    putchar('\n');

    printf("Breadth First:\n");
    sweepBreadth(root);
    putchar('\n');

    if (isTreeOrdered(root))
        yno = " ";
    else
        yno = " not ";

    if (isTreeBalanced(root))
        ynb = " ";
    else
        ynb = " not ";

    printf("The tree is%sordered.\n", yno);
    printf("The tree is%sbalanced.\n", ynb);

    FreeTree(root);

    return (0);
}
