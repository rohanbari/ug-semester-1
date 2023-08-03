/**
 * @file 13.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a program in which a function is passed address of two variables
 * and then alter its contents.
 * @version 0.1
 * @date 03-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

/**
 * @brief Alters the value of the passed variable.
 * 
 * @param a 
 * @param b 
 */
void pass_by_ref(int *a, int *b) {
    *a = 40;
    *b = 50;
}

int main(void) {
    int a = 10;
    int b = 20;

    fprintf(stdout, "Before: a = %d : b = %d\n", a, b);

    // NOTE: There is nothing like pass-by-reference in C.
    // Yet, it can be achieved using pointers this way.
    pass_by_ref(&a, &b);

    fprintf(stdout, "After:  a = %d : b = %d\n", a, b);

    return 0;
}