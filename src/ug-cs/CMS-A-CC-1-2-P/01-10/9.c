/**
 * @file 9.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP to print a triangle of stars.
 * @version 0.1
 * @date 30-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

/**
 * @brief Displays a complete equilateral triangle with asterisks.
 * 
 * @param p Number of lines
 */
void display_triangle(const int p) {
    for (int line = 1; line <= p; line++) {
        for (int space = 1; space <= p - line; space++)
            fputc(' ', stdout);

        // Left side
        for (int mark = 1; mark <= line; mark++)
            fputc('*', stdout);

        // Right side
        for (int mark = 2; mark <= line; mark++)
            fputc('*', stdout);

        fputc('\n', stdout);
    }
}

int main(void) {
    int input = 0;

    fprintf(stdout, "Number of lines: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: Input is not a valid integer.\n");
        return 1;
    }

    // Non-negativity validation
    if (input <= 0) {
        fprintf(stderr, "error: The integer must be non-negative.\n");
        return 1;
    }

    display_triangle(input);

    return 0;
}