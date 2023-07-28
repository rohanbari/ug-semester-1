/**
 * @file 1.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief WAP to print the sum and product of digits of an integer.
 * @version 0.1
 * @date 28-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @brief Summation of the digits of the passed integer.
 * 
 * @param param The integer to be worked on
 */
void do_sum(int param) {
    int sum = 0;

    while (param > 0) {
        int remainder = param % 10;
        param /= 10;

        sum += remainder;
    }

    fprintf(stdout, "Summation: %d\n", sum);
}

/**
 * @brief Product of the digits of the passed integer.
 * 
 * @param param The integer to be worked on
 */
void do_product(int param) {
    int product = 1;

    while (param > 0) {
        int remainder = param % 10;
        param /= 10;

        product *= remainder;
    }

    fprintf(stdout, "Product: %d\n", product);
}

int main(void) {
    int input = 0;

    fprintf(stdout, "Enter an integer: ");

    // Validating the user input
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    do_sum(input);
    do_product(input);

    return EXIT_SUCCESS;
}