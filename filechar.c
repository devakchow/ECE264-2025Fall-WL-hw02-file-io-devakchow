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

  int first_char_ind = -1; // index of first character in current pair
  bool need_first = true; // flag to track if we need first or second character

  // read characters one by one
  int ch;
  while ((ch = fgetc(file)) != EOF) {
  
    int curr_ind = char_to_index(ch);

    if (curr_ind == -1) {
      continue; // skip invalid characters
    }

    if (need_first) {
      // we need the first character of the pair
      first_char_ind = curr_ind;
      need_first = false; // next we will need the second character
    } 
    else {
      // we have second character, form the pair
      counts[first_char_ind][curr_ind]++; // increment the count for the pair
      need_first = true; // next we will need the first character again
    }
  }

  // handle leftover single character at the end of file
  if (!need_first && first_char_ind != -1) {
    counts[first_char_ind][ALPHABET_SIZE]++; // increment count for space
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
