/* PLEASE EDIT THIS FILE */

#include "fileint.h"

#include <stdbool.h>
#include <stdio.h>

bool addFile(char *filename, int *sum) {
  /* BEGIN STUDENT ANSWER */

  // complete as described in the README
  FILE *file = fopen(filename, "r");
  if (file == NULL) // file could not opened
  {
    return false;
  }

  *sum = 0; // initialize sum to 0

  int num; 
  while (fscanf(file, "%d", &num) == 1) {
    *sum += num; // add the number to sum 
  }

  fclose(file); // close the file

  /* END STUDENT ANSWER */
  return true;
}

bool writeSum(char *filename, int sum) {
  /* BEGIN STUDENT ANSWER */

  // complete as described in the README
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return false; // file cannot be opened
  }

  // write sum to file
  fprintf(file, "%d\n", sum);

  // close the file
  fclose(file);

  /* END STUDENT ANSWER */
  return true;
}
