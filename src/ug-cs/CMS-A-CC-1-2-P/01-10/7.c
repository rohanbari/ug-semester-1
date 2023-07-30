/**
 * @file 7.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP to compute the factors of a given number.
 * @version 0.1
 * @date 30-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

/**
 * @brief Generates the factors of a given number.
 * 
 * @param p The given number
 */
void list_factors(const int p) {
    for (int i = 1; i <= p; i++) {
        if (p % i == 0) {
            fprintf(stdout, "%d ", i);
        }
    }
    fputc('\n', stdout);
}

int main(void) {
    int input = 0;

    fprintf(stdout, "Enter an integer: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: The input is not a valid integer.\n");
        return 1;
    }

    fprintf(stdout, "Factors of %d: ", input);
    list_factors(input);

    return 0;
}