/**
 * @file 14.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Write a program which takes the radius of a circle as input from the
 * user, passes it to another function that computes the area and the
 * circumference of the circle and displays the value of area and circumference
 * from the main() function.
 * @version 0.1
 * @date 03-08-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <stdio.h>

#define PI 3.14159

/**
 * @brief The required data structure
 * 
 */
typedef struct {
    double circumference;
    double area;
} data;

/**
 * @brief Computes the data and returns 'data'.
 * 
 * @param  p The radius
 * @return   data 
 */
data compute(const double p) {
    data pack;

    pack.circumference = 2 * PI * p;
    pack.area = PI * p * p;

    return pack;
}

int main(void) {
    double input = 0;

    fprintf(stdout, "Enter the radius of the circle: ");

    if (fscanf(stdin, "%lf", &input) != 1) {
        fprintf(stderr, "error: Invalid radius.\n");
        return 1;
    }

    data result = compute(input);

    fprintf(stdout, "The circumference is %.2lf and the area is %.2lf.\n",
            result.circumference, result.area);

    return 0;
}