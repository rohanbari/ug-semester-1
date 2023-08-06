/**
 * @file 16.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief String manipulation program.
 * @version 0.1
 * @date 04-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

typedef enum { false, true } bool;

// User choices as anonymous enum
enum {
    QUIT,
    DISP_MEM_ADDR,
    CONCAT_STR_NO_STRCAT,
    CONCAT_STR_STRCAT,
    COMPARE_STRS,
    CALC_STRLEN,
    CONV_LOWER_TO_UPPER,
    CALC_VOWELS,
    REV_STR,
};

void clear_screen(void) {
    if (system("@cls||clear") != EXIT_SUCCESS) {
        fprintf(stderr, "error: Failed to clear screen.\n");
        exit(EXIT_FAILURE);
    }
}

void discard_newlines(void) {
    int n;
    while ((n = getchar()) != '\n' && n != EOF)
        ;
}

bool disp_mem_addr(void) {
    char input[MAX_LEN];

    fprintf(stdout, "Enter a sentence: ");

    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "error: Invalid data is given.\n");
        return false;
    }

    discard_newlines();
    for (size_t i = 0, len = strlen(input); i < len; i++)
        fprintf(stdout, "Index %ld has memory address %p.\n", i, &input[i]);

    return true;
}

bool concat_str_no_strcat(void) {
    return true;
}

bool concat_str_strcat(void) {
    char str1[MAX_LEN / 2];
    char str2[MAX_LEN / 2];
    char full_str[MAX_LEN];

    // Getting the first string
    fprintf(stdout, "Enter the 1st string: ");

    if (fgets(str1, sizeof str1, stdin) == NULL) {
        fprintf(stderr, "error: Invalid data.\n");
        return false;
    }
    discard_newlines();

    // Getting the second string
    fprintf(stdout, "Enter the 2nd string: ");

    if (fgets(str2, sizeof str2, stdin) == NULL) {
        fprintf(stderr, "error: Invalid data.\n");
        return false;
    }
    discard_newlines();

    strcat(full_str, str1);
    strcat(full_str, str2);

    fprintf(stdout, "Joined strings: %s\n", full_str);
    return true;
}

bool compare_strs(void) {
    return true;
}

bool calc_strlen(void) {
    char input[MAX_LEN];

    fprintf(stdout, "Input a string: ");

    if (fgets(input, sizeof input, stdin) == NULL) {
        fprintf(stderr, "error: Invalid data.\n");
        return false;
    }
    discard_newlines();

    size_t len = 0;
    while (input[len++] != 0)
        ;

    fprintf(stdout, "The string has %ld characters.\n", len);

    return true;
}

bool conv_lower_to_upper(void) {
    return true;
}

bool calc_vowels(void) {
    return true;
}

bool rev_str(void) {
    return true;
}

int main(void) {
    while (true) {
        clear_screen();

        const char output[MAX_LEN] =
                "[1] Display memory address of each character\n"
                "[2] Concatenate two strings without using strcat\n"
                "[3] Concatenate two strings with using strcat\n"
                "[4] Compare two strings\n"
                "[5] Calculate length of a string using pointers\n"
                "[6] Convert all lowercase characters to uppercase\n"
                "[7] Calculate number of vowels in a string\n"
                "[8] Reverse a string\n"
                "[0] Quit from the app\n\n"
                "[=] Input => ";
        fprintf(stdout, output);

        int input = 0;
        if (fscanf(stdin, "%d", &input) != 1) {
            fprintf(stderr, "\nerror: Invalid input.\n");
            discard_newlines();
            getchar();

            continue;
        }
        fputc('\n', stdout);

        bool status = true;
        switch (input) {
            case QUIT:
                goto quit;
                break;
            case DISP_MEM_ADDR:
                status = disp_mem_addr();
                break;
            case CONCAT_STR_NO_STRCAT:
                status = concat_str_no_strcat();
                break;
            case CONCAT_STR_STRCAT:
                status = concat_str_strcat();
                break;
            case COMPARE_STRS:
                status = compare_strs();
                break;
            case CALC_STRLEN:
                status = calc_strlen();
                break;
            case CONV_LOWER_TO_UPPER:
                status = conv_lower_to_upper();
                break;
            case CALC_VOWELS:
                status = calc_vowels();
                break;
            case REV_STR:
                status = rev_str();
                break;
            default:
                fprintf(stderr, "error: No such option.\n");
                break;
        }

        discard_newlines();

        if (!status)
            fprintf(stderr, "warn: The code execution did not finish well.\n");

        fprintf(stdout, "\nPress any key to continue. ");
        getchar();
    }

quit:
    fprintf(stdout, "==[ Thank You For Using This Application ]==\n\n");

    return 0;
}