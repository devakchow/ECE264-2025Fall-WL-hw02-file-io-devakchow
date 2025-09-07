# File IO

## Learning Goals

In this assignment, you will:

- Read characters and integers from files.
- Handle file permissions and potential errors.
- Convert between characters and their ASCII values.
- Pass data by address between functions.
- Write results to output files.
- Practice separate compilation by using multiple source files.

---

## **Part 1: Reading Characters from a File**

### **Function 1: Counting Character Frequencies**

You need to implement the function:

```c
bool countChar(const char *filename, int counts[][]);
```

In this function, you will read each successive pair of letters and increment the appropriate
   `counts[first_letter_index][second_letter_index]` entry.
   - The first index (0–25) corresponds to the first letter in the pair (`a`=0, `b`=1, …, `z`=25).
   - The second index (0–25) corresponds to the second letter in the pair, and index 26 is reserved for when the last letter has **no partner** (odd number of letters).
   - Skip any characters that are not `[a-z]` or `[A-Z]` when forming pairs.

   **Example:**  
   A file containing `"I love ECE264!"` (case-insensitive, ignoring spaces and punctuation) would be read as:

   - `"il"` → `counts[8][11]++`
   - `"ov"` → `counts[14][21]++`
   - `"ee"` → `counts[4][4]++`
   - `"ce"` → `counts[2][4]++`

### **Instructions:**

1. Open the file specified by `filename` for reading.
   - If the file cannot be opened, return `false` and **do not call** `fclose()`.

2. Read each successive pair of letters and increment the appropriate entry in  `counts[][]`.
   1. Create a loop where one character is read each iteration.
   2. If the current character is not alphanumeric (`[a-z]` or `[A-Z]`), skip it.
   3. If the current alphanumeric character is first in the current pair, store it's value.
   4. If the current alphanumeric character is second in the current pair, increment the pair in `counts[][]`.

3. Stop reading at the end of the file.

4. If there is a leftover single letter at the end, increment its count at index 26 for the second position.

5. Close the file using `fclose()` after processing if the file opened successfully and return `true`.

**Hint 1:** fill out the helper function `char_to_index()`, and use it! This is an operation you will have to do multiple times so it nice to have the logic separated.

**Hint 2:** use `fgetc()`. Please read the documentation carefully around reaching the end of the file. Documentation can be found by typing `man fgetc` in your terminal. This method works for all standard library functions!

**Hint 3:** use `isalpha()`. Try looking it up in the manual in the same way as the previous hint.

### **Function 2: Printing Character Counts**

You need to implement the function:

```c
void printCounts(const int counts[][]);
```

### **Instructions:**

1. Iterate through every possible pair of indices `(ind1, ind2)` in the `counts` array.

2. For each `(ind1, ind2)` pair:    
   - If `counts[ind1][ind2]` is zero, skip printing for that pair.
   - Otherwise, print one line in the format:

     ```
     ind1, ind2, onechar1onechar2, counts[ind1][ind2]
     ```
     where:
     - `ind1` and `ind2` are printed as integers.
     - `onechar1` and `onechar2` are the lowercase letters corresponding to `ind1` and `ind2`.
       If `ind2 == 26`, print a space `' '` for `onechar2`.
     - `counts[ind1][ind2]` is the integer count value for that pair.

   **Example:**  
   A file containing `"I love ECE264!"` would print:
   ```
   2, 4, ce, 1
   4, 4, ee, 1
   8, 11, il, 1
   14, 21, ov, 1
   ```

3. Stop after processing all `(ind1, ind2)` combinations.

**Hint 1:** fill out the helper function `index_to_char()`, and use it! This is an operation you will have to do multiple times so it nice to have the logic separated.

**Hint 2:** You must always know the size an array before iterating through it to avoid an out-of-bounds array access. Luckily, these are defined for you with the object-like macros `ALPHABET_SIZE` and `ALPHABET_SIZE_W_SPACE` in `filechar.h`.More info on [out-of-bound array access](https://www.geeksforgeeks.org/cpp/accessing-array-bounds-ccpp/) and [macros](https://www.geeksforgeeks.org/c/macros-and-its-types-in-c-cpp/).

## **Part 2: Reading and Summing Integers from a File**

### **Function 3: Adding Numbers from a File**

Implement the function:

```c
bool addFile(const char *filename, int *sum);
```

### **Instructions:**

1. Open the file specified by `filename` for reading.
   - If the file cannot be opened, return `false` and **do not call** `fclose()`.
2. Initialize `*sum` to zero.
3. Read integers from the file using `fscanf()` and accumulate the sum.
4. Stop reading at the end of the file.
5. Close the file using `fclose()` if it opened successfully.
6. Return `true`.

### **Function 4: Writing the Sum to a File**

Implement the function:

```c
bool writeSum(const char *filename, int sum);
```

### **Instructions:**

1. Open the file specified by `filename` for writing.
   - If the file cannot be opened, return `false`.
2. Write the sum as an integer to the file using `fprintf()`.
3. Close the file using `fclose()`.
4. Return `true`.

---

## **Files and Separate Compilation**

- Write your code for character-related operations (Part 1) in `filechar.c`.
- Write your code for integer-related operations (Part 2) in `fileint.c`.

---

## **Testing Your Program**

The Makefile provided includes several test cases. Example:

  ```plaintext
  make test1
  ```
Feel free to create more custom test cases as well.

---

## **Submission Requirements**

Submit the following files to gradescope:
`filechar.c`, `fileint.c`

Do this through the use of the zip command: `zip hw02.zip filechar.c fileint.c`
