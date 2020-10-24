/******************************************************************************
 *
 * File Name: class1a.c
 *	      (c) 2010 AED
 * Author:    ACR
 * Revision:  2012
 *
 * NAME
 *     class1
 *
 * DESCRIPTION
 *	Debuging, menory allocation and free, string manipulation
 *	Function call passing by reference and by argument
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* function show_values: illustrates the argument passing by value and by reference */
void show_values(int a, int* b, char* str1, char* str2)
{
  printf("\nFunction show_values:\nFirst argument of program, \"%s\", has %i characters.\n", str2, *b);
  printf("The hidden phrase \"%s\" has %i characters\n", str1, a);
  /* change string length to 10000 */
  a=10000;
  /* change first argument length to square root of 10000.0 */
  *b=(int) sqrt(10000.0);
}

void inocente(char *s, int end)
{
  s[end] = 'Q';
  s[end+1] = 'u';
  s[end+2] = 'e';
  s[end+3] = 'm';
  s[end+4] = ' ';
  s[end+5] = 'f';
  s[end+6] = 'e';
  s[end+7] = 'z';
  s[end+8] = ' ';
  s[end+9] = 'i';
  s[end+10] = 's';
  s[end+11] = 't';
  s[end+12] = 'o';
  s[end+13] = '?';
  s[end+14] = '.';
  s[end+15] = '\0';
}

int main(int argc, char ** argv)
{
  int arg1_len, i;

  /* phrase in stringA has 11 characters */
  char* stringA = "My secret: ";
  /* Phrase in stringB has 21 characters */
  char* stringB = "I like AED very much!";
  char* string = '\0';
  /* allocation of string */
  string = (char*) malloc ((strlen(stringA)+strlen(stringB)+100)*sizeof(char));
  /* function strcpy: copy strings */
  strcpy(string, stringA);
  /* function strccat: concatenate strings */
  strcat(string, stringB);
  /* what is the purpose of the next instruction ? Anything missing ? */
  inocente(string, strlen(string));

  if (argc < 2){
    printf("Number of arguments incorrect\n");
    exit(EXIT_FAILURE);
  }
  /* what is *argv[1]? */
  if (*argv[1] == '1') {
    /* part 1*/
    /* Function strlen: */
    /* returns the length (in characters) of a string */
    printf("\nFirst argument starts with 1:\n");
    for (i=0; i < strlen(string); i++) {
      printf("Character %d ---- %c\n", i, string[i]);
    }
    printf("\n");
  } else {
    /* part 2 */
    i=strlen(string);
    arg1_len = strlen(argv[1]);
    printf("\nInitial Values:\n");
    printf("Length of hidden phrase (i) = %d \n", i);
    printf("Length of first argument of the program (arg1_len) : %d \n", arg1_len);
    show_values(i, &arg1_len, string, argv[1]);
    printf("\nAfter show_values:\n");
    printf("Length of hidden phrase (i) (32) = %d \n", i);
    printf("Length of first argument of the program (arg1_len) (100): %d \n\n", arg1_len);
  }
  free(string);
}
