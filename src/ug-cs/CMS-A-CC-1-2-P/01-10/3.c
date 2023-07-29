/**
 * @file 3.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP to compute the sum of the first n terms of the following series,
 * S = 1+ 1/2 + 1/3 + 1/4 + ...
 * @version 0.1
 * @date 29-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @brief Displays the geometric progression sum of up to N terms.
 * 
 * @param n Number of terms
 */
double display_gp_sum(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++)
        sum += 1.0 / i;

    return sum;
}

int main(void) {
    int input = 0;

    fprintf(stdout, "Number of terms to add up to: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    if (input <= 0) {
        fprintf(stderr, "error: The number of terms must be a +ve integer.\n");
        return EXIT_FAILURE;
    }

    double result = display_gp_sum(input);
    fprintf(stdout, "G.P. Sum: %.2lf\n", result);

    return EXIT_SUCCESS;
}