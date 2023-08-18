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

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/**
 * @brief Displays the loop on the screen.
 * 
 * @param p The array
 */
void display_loop(int *p) {
    for (int i = 0; i < MAX_SIZE; i++)
        fprintf(stdout, "%d ", p[i]);

    fputc('\n', stdout);
}

/**
 * @brief Displays the array in ascending order.
 * 
 * @param p The array
 */
void display_asc(int *p) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = i + 1; j < MAX_SIZE; j++) {
            if (p[i] > p[j]) {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    display_loop(p);
}

/**
 * @brief Displays the array in descending order.
 * 
 * @param p The array
 */
void display_dsc(int *p) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = i + 1; j < MAX_SIZE; j++) {
            if (p[i] < p[j]) {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    display_loop(p);
}

int main(void) {
    // Allocating 40-bytes of memory by default
    int *array = (void *)malloc((sizeof(int) * MAX_SIZE));

    // Memory allocation safety net
    if (array == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        return 1;
    }

    fprintf(stdout, "Input ten integers (sep. by space): ");

    // Assign values to the array
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