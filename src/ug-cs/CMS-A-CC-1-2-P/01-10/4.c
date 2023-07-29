/**
 * @file 4.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP to compute the sum of the first n terms of the following series,
 * S = 1 - 2 + 3 - 4 + 5 - ...
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
 * @brief Evaluates the sign of a given number.
 * 
 * @param num The number
 * @return +1 or -1
 */
short int sign(const int num) {
    // Returns +1 if +ve, -1 if -ve
    return ((num % 2 == 0) ? -1 : 1);
}

/**
 * @brief Calculates the sum.
 * 
 * @param n Number of terms
 * @return  Summation
 */
int calc_sum(const int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++)
        sum += sign(i) * i;

    return sum;
}

int main() {
    int input = 0;

    fprintf(stdout, "Enter the number of terms: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    int result = calc_sum(input);
    fprintf(stdout, "Sum: %d\n", result);

    return EXIT_SUCCESS;
}