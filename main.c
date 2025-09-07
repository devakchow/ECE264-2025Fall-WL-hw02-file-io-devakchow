// ***
// *** DO NOT modify this file
// ***

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "filechar.h"
#include "fileint.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <char filename> <int filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int counts[ALPHABET_SIZE][ALPHABET_SIZE_W_SPACE] = {0};  // Counts initialized to zero
  bool ret;

  ret = countChar(argv[1], counts);
  if (ret == false) {
    printf("Failed to open file for character counting.\n");
    return EXIT_FAILURE;
  }

  printCounts(counts);

  int sum = 0;
  ret = addFile(argv[2], &sum);
  if (ret == false) {
    printf("Failed to open file for integer addition.\n");
    return EXIT_FAILURE;
  }

  ret = writeSum("sum_output.txt", sum);
  if (!ret) {
    printf("Failed to write sum to output file.\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
