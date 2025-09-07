/* PLEASE EDIT THIS FILE */

#include "filechar.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

/* BEGIN STUDENT ANSWER HELPER FUNCTIONS */

static inline int char_to_index(char character) {
  // turn both [a-z] and [A-Z] into the index used to increment their spots in
  // the array.
  if (character >= 'a' && character <= 'z') {
    return character - 'a';
  }
  if (character >= 'A' && character <= 'Z') {
    return character - 'A'; // normalize uppercase to lowercase
  }
  return -1; // this is for invalid character 
}

static inline char index_to_char(int index) {
  // turn the index into [a-z] or ' '
  if (index >= 0 && index < ALPHABET_SIZE) {
    return 'a' + index;
  }
  if (index == ALPHABET_SIZE) {
    return ' '; // space character
  }
  return '\0'; // this for invalid index
}

/* END STUDENT ANSWER HELPER FUNCTIONS */

bool countChar(char *filename, int counts[][ALPHABET_SIZE_W_SPACE]) {
  /* BEGIN STUDENT ANSWER */

  // complete as described in the README
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return false; // file could not opened
  }

  int prev_ind = -1; // to track previous valid character index
  int curr_ind; // current index

  // read variables one by one
  int ch;
  while ((ch = fgetc(file)) != EOF) {
    curr_ind = char_to_index(ch);
    // skip invalid characters
    if (curr_ind == -1) {
      continue; // invalid character, so skip 
    }

    // if there is a previous valid character, increment the count
    if (prev_ind != -1) {
      counts[prev_ind][curr_ind]++;
    }

    // update prev_ind to current character's index 
    prev_ind = curr_ind;
  }

  // handle leftover single character at the end of file
  if (prev_ind != -1) {
    counts[prev_ind][ALPHABET_SIZE]++; // increment count for space
  }

  fclose(file);
  return true; // successfully counted characters

  /* END STUDENT ANSWER */
}

void printCounts(int counts[][ALPHABET_SIZE_W_SPACE]) {
  /* BEGIN STUDENT ANSWER */

  // complete as described in the README
  for (int ind1 = 0; ind1 < ALPHABET_SIZE; ind1++) {
    for (int ind2 = 0; ind2 < ALPHABET_SIZE_W_SPACE; ind2++) {
      if (counts[ind1][ind2] == 0) {
        continue; // skip zero counts
      }

      // convert indices to characters
      char char1 = index_to_char(ind1);
      char char2 = index_to_char(ind2);

      // print the count in the specified format
      printf("%d, %d, %c%c, %d\n", ind1, ind2, char1, char2, counts[ind1][ind2]);
    }
  }

  /* END STUDENT ANSWER */
}
