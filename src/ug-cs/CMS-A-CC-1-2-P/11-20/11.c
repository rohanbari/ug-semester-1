/**
 * @file 11.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP that prints a table indicating the number of occurrences of each
 * alphabet in the text entered as command line arguments.
 * @version 0.1
 * @date 02-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool validate_args(const int argc, const char *p) {
    if (argc == 1) {
        fprintf(stdout, "Usage: %s <text>\n", p);
        return false;
    }

    return true;
}

bool display_frequency(int argc, char **argv) {
    int *count = (void *)malloc(sizeof(int) * argc);

    // Memory allocation safety
    if (count == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        // TODO: Code from here
    }
}

int main(int argc, char **argv) {
    if (!validate_args(argc, argv[0]))
        return 1;

    if (!display_frequency(argc, argv))
        return 1;

    return 0;
}