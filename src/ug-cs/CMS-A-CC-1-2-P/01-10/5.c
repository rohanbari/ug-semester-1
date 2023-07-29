/**
 * @file 5.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a function that checks whether a given string is Palindrome or
 * not. Use this function to find whether the string entered by user is
 * Palindrome or not.
 * @version 0.1
 * @date 29-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAX_LEN 256

// Custom boolean type
typedef enum { false, true } bool;

/**
 * @brief Reverses a given string.
 * 
 * @param str The string
 */
void reverse_str(char *str) {
    char dummy[MAX_LEN];
    strcpy(dummy, str);

    int len = strlen(dummy) - 1;
    int idx = 0;

    while (len >= 0)
        str[idx++] = dummy[len--];
}

/**
 * @brief Evaluates whether a given word is a palindrome or not.
 * 
 * @param str The word string to be tested
 * @return    true, false
 */
bool is_pal(const char *str) {
    char copy_str[MAX_LEN];

    strcpy(copy_str, str);
    reverse_str(copy_str);

    bool status = strcmp(str, copy_str) == 0;

    return status;
}

int main(void) {
    char str[MAX_LEN];

    fprintf(stdout, "Input a word: ");

    // Input validation
    if (fscanf(stdin, "%s", str) != 1) {
        fprintf(stderr, "error: The string was improperly entered.\n");
        return EXIT_FAILURE;
    }

    bool result = is_pal(str);
    fprintf(stdout, "The string is %s palindrome.\n", (result ? "a" : "not a"));

    return EXIT_SUCCESS;
}