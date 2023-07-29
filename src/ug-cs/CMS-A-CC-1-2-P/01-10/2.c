#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * @brief Displays the reverse of a given number.
 * 
 * @param param The given number
 */
void display_reverse(int param) {
    while (param > 0) {
        // To get the last digit of each multiple of 10
        int rem = param % 10;
        param /= 10;

        printf("%d", rem);
    }
    putc('\n', stdout);
}

int main(void) {
    int input = 0;

    fprintf(stdout, "Enter an integer: ");

    // Input validation
    if (fscanf(stdin, "%d", &input) != 1) {
        fprintf(stderr, "error: Invalid input.");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "Reversed: ");
    display_reverse(input);

    return EXIT_SUCCESS;
}