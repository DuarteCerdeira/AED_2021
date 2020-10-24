/******************************************************************************
* (c) 2010-2019 AED Team
* Last modified: abl 2019-02-22
*
* NAME
*   connectivity.c
*
* DESCRIPTION
*   Algorithms for solving the connectivity problem -  QF QU WQU CWQU
*   For each method count number of entry pairs and the number of links
*
* COMMENTS
*   Code for public distribution
******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#include "connectivity.h"

unsigned long int count[2];

/******************************************************************************
 *
 * count[0]: find operations counter
 * count[1]: union operations counter
 *
 *****************************************************************************/

/******************************************************************************
* quick_find()
*
* Arguments: id - array with connectivity information
*            N - size of array
*            fp - file pointer to read data from
*            quietOut - to reduce output to just final count
* Returns: (void)
* Side-Effects: pairs of elements are read and the connectivity array is
*               modified
*
* Description: Quick Find algorithm
*****************************************************************************/
void quick_find(int *id, int N, FILE * fp, int quietOut)
{
    int i, j, p, q, t, sets = 0, singles = 0;
    int pairs_cnt = 0;            /* connection pairs counter */
    int links_cnt = 0;            /* number of links counter */

    /* initialize; all disconnected */
    for (i = 0; i < N; i++) {
        id[i] = i;
    }

    /* read while there is data */
    while (fscanf(fp, "%d %d", &p, &q) == 2) {
	pairs_cnt++;
	count[0]+=2;
	/* do search first */
	if (id[p] == id[q]) {
	    /* already in the same set; discard */
	    if (!quietOut)
		printf("\t%d %d\n", p, q);
	    continue;
	}

	/* pair has new info; must perform union */
	count[1]++;
	for (t = id[p], i = 0; i < N; i++, count[1]++) {
	    if (id[i] == t) {
		id[i] = id[q];
		count[1]+=2;
	    }
	}
	links_cnt++;
	if (!quietOut)
	    printf(" %d %d\n", p, q);
    }
    printf("QF: The number of links performed is %d for %d input pairs.\n",
	   links_cnt, pairs_cnt);
    printf("Find operations: %ld\nUnion operations: %ld\n", count[0], count[1]);
    count[0] = 0; count[1] = 0;

    /* print out sets */
    
    t = 0;
    while (t < N) {
	i = 0; j = 0;
	while (i < N) {
	    if (id[i] == t) {
		if (j == 0)
		    printf("%d", i);
		else
		    printf("-%d", i);
		j++;
	    }
	    i++;
	}
	if (j == 1)
	  singles++;
	if (j != 0) {
	    printf("\n");
	    sets++;
	}
	t++;
    }
    printf("Number of sets: %d\n", sets);
    printf("Number of sets with only one member: %d\n", singles);
    return;
}


/******************************************************************************
* quick_union()
*
* Arguments: id - array with connectivity information
*            N - size of array
*            fp - file pointer to read data from
*            quietOut - to reduce output to just final count
* Returns: (void)
* Side-Effects: pairs of elements are read and the connectivity array is
*               modified
*
* Description: Quick Union algorithm
*****************************************************************************/
void quick_union(int *id, int N, FILE * fp, int quietOut)
{

    int i, j, p, q;
    int pairs_cnt = 0;            /* connection pairs counter */
    int links_cnt = 0;            /* number of links counter */

    /* initialize; all disconnected */
    for (i = 0; i < N; i++) {
        id[i] = i;
    }

    /* read while there is data */
    while (fscanf(fp, "%d %d", &p, &q) == 2) {
        pairs_cnt++;
        i = p;
        j = q;
        /* do search first */
	count[0] += 2;
        while (i != id[i]) {
            i = id[i];
	    count[0]+=2;
        }
        while (j != id[j]) {
            j = id[j];
	    count[0]+=2;
        }
        if (i == j) {
            /* already in the same set; discard */
            if (!quietOut)
                printf("\t%d %d\n", p, q);
            continue;
        }

        /* pair has new info; must perform union */
        id[i] = j;
        links_cnt++;
	count[1]++;
        if (!quietOut)
            printf(" %d %d\n", p, q);
    }
    printf("QU: The number of links performed is %d for %d input pairs.\n",
            links_cnt, pairs_cnt);
    printf("Find operations: %ld\nUnion operations: %ld\n", count[0], count[1]);
    count[0] = 0; count[1] = 0;
}


/******************************************************************************
* weighted_quick_union()
*
* Arguments: id - array with connectivity information
*            N - size of array
*            fp - file pointer to read data from
*            quietOut - to reduce output to just final count
* Returns: (void)
* Side-Effects: pairs of elements are read and the connectivity array is
*               modified
*
* Description: Weighted Quick Union algorithm
*****************************************************************************/
void weighted_quick_union(int *id, int N, FILE * fp, int quietOut)
{

    int i, j, p, q;
    int *sz = (int *) malloc(N * sizeof(int));
    int pairs_cnt = 0;            /* connection pairs counter */
    int links_cnt = 0;            /* number of links counter */

    /* initialize; all disconnected */
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    /* read while there is data */
    while (fscanf(fp, "%d %d", &p, &q) == 2) {
        pairs_cnt++;
        /* do search first */
	count[0] += 2;
        for (i = p; i != id[i]; i = id[i], count[0] += 2);
        for (j = q; j != id[j]; j = id[j], count[0] += 2);
        if (i == j) {
            /* already in the same set; discard */
            if (!quietOut)
                printf("\t%d %d\n", p, q);
            continue;
        }

        /* pair has new info; must perform union; pick right direction */
	count[1] += 2;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
	    count[1] += 4;
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
	    count[1] += 4;
        }
        links_cnt++;

        if (!quietOut)
            printf(" %d %d\n", p, q);
    }
    printf("WQU: The number of links performed is %d for %d input pairs.\n",
            links_cnt, pairs_cnt);
    printf("Find operations: %ld\nUnion operations: %ld\n", count[0], count[1]);
    count[0] = 0; count[1] = 0;
}


/******************************************************************************
* compressed_weighted_quick_union()
*
* Arguments: id - array with connectivity information
*            N - size of array
*            fp - file pointer to read data from
*            quietOut - to reduce output to just final count
* Returns: (void)
* Side-Effects: pairs of elements are read and the connectivity array is
*               modified
*
* Description: Compressed Weighted Quick Union algorithm
*****************************************************************************/
void compressed_weighted_quick_union(int *id, int N, FILE * fp, int quietOut)
{
    int i, j, p, q, t, x;
    int *sz = (int *) malloc(N * sizeof(int));
    int pairs_cnt = 0;            /* connection pairs counter */
    int links_cnt = 0;            /* number of links counter */

    /* initialize; all disconnected */
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    /* read while there is data */
    while (fscanf(fp, "%d %d", &p, &q) == 2) {
        pairs_cnt++;

        /* do search first */
	count[0] += 2;
        for (i = p; i != id[i]; i = id[i], count[0] += 2);
        for (j = q; j != id[j]; j = id[j], count[0] += 2);

        if (i == j) {
            /* already in the same set; discard */
            if (!quietOut)
                printf("\t%d %d\n", p, q);
            continue;
        }

        /* pair has new info; must perform union; pick right direction */
	count[1] += 2;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
            t = j;
	    count[1] += 4;
        }
        else {
            id[j] = i;
            sz[i] += sz[j];
            t = i;
	    count[1] += 4;
        }
        links_cnt++;

        /* retrace the path and compress to the top */
        for (i = p; i != id[i]; i = x, count[1]++) {
            x = id[i];
            id[i] = t;
	    count[1] += 2;
        }
        for (j = q; j != id[j]; j = x, count[1]++) {
            x = id[j];
            id[j] = t;
	    count[1] += 2;
        }
        if (!quietOut)
            printf(" %d %d\n", p, q);
    }
    printf("CWQU: The number of links performed is %d for %d input pairs.\n",
            links_cnt, pairs_cnt);
    printf("Find operations: %ld\nUnion operations: %ld\n", count[0], count[1]);
    count[0] = 0; count[1] = 0;
    return;
}
