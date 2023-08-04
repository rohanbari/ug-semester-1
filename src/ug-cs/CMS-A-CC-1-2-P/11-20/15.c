/**
 * @file 15.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a program to find sum of n elements entered by the user. To
 * write this program, allocate memory dynamically using malloc() / calloc()
 * functions or new operator.
 * @version 0.1
 * @date 04-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number = 0;

    fprintf(stdout, "Number of integers to fill up: ");

    // Input validation
    if (fscanf(stdin, "%d", &number) != 1) {
        fprintf(stderr, "error: Invalid input.\n");
        return 1;
    }

    // Negative size safety
    if (number <= 0) {
        fprintf(stderr, "error: The number must be +ve nonzero.\n");
        return 1;
    }

    // Allocating required bytes of integer
    int *array = (void *)malloc(sizeof(int) * number);

    // Memory allocation safety
    if (array == NULL) {
        fprintf(stdout, "error: malloc() failed.\n");
        return 1;
    }

    fprintf(stdout, "Input the integers: ");

    for (int i = 0; i < number; i++) {
        int input = 0;

        // Input validation
        if (fscanf(stdin, "%d", &input) != 1) {
            fprintf(stderr, "error: Invalid integer.\n");
            return 1;
        }

        array[i] = input;
    }

    for (int i = 0; i < number; i++)
        fprintf(stdout, "%d ", array[i]);

    fputc('\n', stdout);

    return 0;
}