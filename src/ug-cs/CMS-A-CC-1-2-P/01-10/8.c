/**
 * @file 8.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a macro that swaps two numbers. WAP to use it.
 * @version 0.1
 * @date 30-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

// WARNING: Undefined-behavior invocation
#define SWAP(x, y) (x ^= y ^= x ^= y)

int main(void) {
    int x = 10;
    int y = 5;

    fprintf(stdout, "Before swap: %d %d\n", x, y);
    SWAP(x, y);
    fprintf(stdout, "After swap: %d %d\n", x, y);

    return 0;
}