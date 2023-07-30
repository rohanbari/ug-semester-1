/**
 * @file 6.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a function to find whether a given no. is prime or not. Use the
 * same to generate the prime numbers less than 100.
 * @version 0.1
 * @date 30-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

// Generate prime numbers up to
#define MAX_RANGE 100

// Custom Boolean type
typedef enum { false, true } bool;

/**
 * @brief Evaluates whether a given number is a prime number or not.
 * 
 * @param p The number to be tested
 * @return true 
 * @return false 
 */
bool is_prime(const int p) {
    // 0 and 1 are non-prime numbers
    if (p == 0 || p == 1) {
        return false;
    }

    // Attempting to divide every lower number to the main number
    // NOTE: i <= (p/2) because main number / (p/2 + 1) < 2!
    for (int i = 2; i <= p / 2; i++) {
        if (p % i == 0) {
            // If the lower number cancels out the main number, then it is
            // divisible by the lower number; hence, not a prime.
            return false;
        }
    }

    return true;
}

void activity_1(void) {
    int input = 0;

    fprintf(stdout, "Enter an integer: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: The input is not a valid integer.\n");
        return;
    }

    bool prime = is_prime(input);
    fprintf(stdout, "The number is %s prime.\n", (prime ? "a" : "not a"));
}

void activity_2(void) {
    for (int i = 0; i < 100; i++) {
        if (is_prime(i)) {
            fprintf(stdout, "%d ", i);
        }
    }
    fputc('\n', stdout);
}

int main(void) {
    activity_1();
    activity_2();

    return 0;
}