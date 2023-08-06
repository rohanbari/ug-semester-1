/**
 * @file 24.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a program that will read 10 integers from user and store them in
 * an array. Implement array using pointers. The program will print the array
 * elements in ascending and descending order.
 * @version 0.1
 * @date 06-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void display_asc(const int *p) {
}

void display_dsc(const int *p) {
}

int main(void) {
    int *array = (void *)malloc((sizeof(int) * MAX_SIZE));

    // Memory allocation safety net
    if (array == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        return 1;
    }

    fprintf(stdout, "Input ten integers (sep. by space): ");

    for (int i = 0; i < MAX_SIZE; i++) {
        int input = 0;
        if (fscanf(stdin, "%d", &input) != 1) {
            fprintf(stderr, "error: Invalid input type.\n");
            return 1;
        }

        array[i] = input;
    }

    display_asc(array);
    display_dsc(array);

    return 0;
}