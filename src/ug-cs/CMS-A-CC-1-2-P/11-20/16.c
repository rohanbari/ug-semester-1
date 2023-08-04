/**
 * @file 16.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief 
 * @version 0.1
 * @date 04-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

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
                break;
            case DISP_MEM_ADDR:
                break;
            case CONCAT_STR_NO_STRCAT:
                break;
            case CONCAT_STR_STRCAT:
                break;
            case COMPARE_STRS:
                break;
            case CALC_STRLEN:
                break;
            case CONV_LOWER_TO_UPPER:
                break;
            case CALC_VOWELS:
                break;
            case REV_STR:
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

    return 0;
}