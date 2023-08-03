/**
 * @file 12.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a program that swaps two numbers using pointers.
 * @version 0.1
 * @date 03-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *x = (void *)malloc(sizeof(int));
    int *y = (void *)malloc(sizeof(int));

    // Memory allocation safety
    if (x == NULL || y == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        return 1;
    }

    fprintf(stdout, "Input two integers: ");

    // Input validation
    if (fscanf(stdin, "%d%d", x, y) != 2) {
        fprintf(stderr, "error: Improper input.\n");
        return 1;
    }

    *x = *x + *y; // a = a + b
    *y = *x - *y; // b = a - b
    *x = *x - *y; // a = a - b

    fprintf(stdout, "Swapped values: %d %d\n", *x, *y);

    return 0;
}