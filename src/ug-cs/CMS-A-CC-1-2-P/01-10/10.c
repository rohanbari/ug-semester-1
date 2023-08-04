/**
 * @file 10.c
 * @author Rohan Bari <rohanbari4@gmail.com>
 * @brief Array-manipulation program.
 * @version 0.1
 * @date 30-07-2023
 * 
 * Copyright (c) 2023 Rohan Bari
 * 
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Custom Boolean type
typedef enum { false, true } bool;

// User choices
enum {
    INIT_ARRAY = 0,
    EVEN_ELEMS,
    ODD_ELEMS,
    SUM_AVG,
    MAX_MIN,
    REV_ORDER,
    REM_DUPES,
    QUIT = 9
};

// These are global variables.
// I have used them with safety precautions as per KISS rule.
// It is not recommended as a general practice, though.
int array_size = 0;
int *array = NULL;

/**
 * @brief Undefined-behavior on empty array safety.
 * 
 * @return true 
 * @return false 
 */
bool len_check() {
    if (array_size == 0 || array == NULL) {
        fprintf(stderr, "error: The array must be initialized first.\n");
        return 1;
    }

    return 0;
}

/**
 * @brief Clears the output screen.
 * 
 */
void clear_screen(void) {
    if (system("@cls||clear") != EXIT_SUCCESS) {
        fprintf(stderr, "error: Failed to clear screen.\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Discards extra input buffer.
 * 
 */
void discard_newlines(void) {
    int n;
    while ((n = getchar()) != '\n' && n != EOF)
        ;
}

bool init_arrays() {
    fprintf(stdout, "Enter the array size: ");

    // Input validation
    if (fscanf(stdin, "%d", &array_size) != 1) {
        fprintf(stderr, "error: Invalid input.\n");
        return 1;
    }

    free(array);
    // Required memory allocation
    array = (void *)malloc(sizeof(int) * array_size);

    // Memory allocation safety
    if (array == NULL) {
        fprintf(stderr, "error: malloc() failed.\n");
        return 1;
    }

    fprintf(stdout, "Array elements (sep. by space): ");
    for (int i = 0; i < array_size; i++) {
        int input = 0;

        // Input validation
        if (fscanf(stdin, "%d", &input) != 1) {
            fprintf(stderr, "error: Invalid integer.\n");

            // Resetting values
            array_size = 0;
            array = NULL;

            return 1;
        }

        array[i] = input;
    }

    return 0;
}

bool print_even_elems() {
    if (len_check())
        return 1;

    for (int i = 0; i < array_size; i++)
        if (array[i] % 2 == 0)
            fprintf(stdout, "%d ", array[i]);

    fputc('\n', stdout);

    return 0;
}

bool print_odd_elems() {
    if (len_check())
        return 1;

    for (int i = 0; i < array_size; i++)
        if (array[i] % 2 == 1)
            fprintf(stdout, "%d ", array[i]);

    fputc('\n', stdout);

    return 0;
}

bool print_sum_average() {
    if (len_check())
        return 1;

    int sum = 0;
    double avg = 0.0;

    for (int i = 0; i < array_size; i++)
        sum += array[i];

    avg = (double)sum / array_size;

    fprintf(stdout, "The sum is %d and the average is %.2lf.\n", sum, avg);

    return 0;
}

bool print_max_min() {
    if (len_check())
        return 1;

    int min = INT_MIN;
    int max = INT_MAX;

    for (int i = 0; i < array_size; i++) {
        if (array[i] > min)
            min = array[i];
        if (array[i] < max)
            max = array[i];
    }

    fprintf(stdout, "The min element is %d and max is %d.\n", min, max);

    return 0;
}

bool print_reverse_order() {
    if (len_check())
        return 1;

    for (int i = array_size - 1; i >= 0; i--)
        fprintf(stdout, "%d ", array[i]);

    fputc('\n', stdout);

    return 0;
}

bool remove_dupes() {
    if (len_check())
        return 1;

    if (array_size == 1)
        fprintf(stdout, "%d\n", array[0]);

    // Careful! array_size is a global variable.
    // For the sake of not altering the value globally, I used a temp variable.
    int temp_size = array_size;
    int *temp_array = (void *)malloc(sizeof(int) * temp_size);

    for (int i = 0; i < temp_size; i++)
        temp_array[i] = array[i];

    // Duplicate removal algorithm
    for (int idx = 0; idx < temp_size; idx++)
        for (int sub_idx = idx + 1; sub_idx < temp_size; sub_idx++)
            if (temp_array[idx] == temp_array[sub_idx]) {
                for (int k = sub_idx; k < temp_size; k++)
                    temp_array[k] = temp_array[k + 1];

                sub_idx--;
                temp_size--;
            }

    for (int i = 0; i < temp_size; i++)
        fprintf(stdout, "%d ", temp_array[i]);

    fputc('\n', stdout);

    return 0;
}

int main(void) {
    while (true) {
        clear_screen();

        fprintf(stdout, "[0] Initialize the array\n"
                        "=============================================\n"
                        "[1] Print the even-valued elements\n"
                        "[2] Print the odd-valued elements\n"
                        "[3] Print the sum and average of the elements\n"
                        "[4] Print the maximum and minimum elements\n"
                        "[5] Print the array in reverse order\n"
                        "[6] Remove duplicate elements\n"
                        "=============================================\n"
                        "[9] Quit app\n\n"
                        "[=] Choice: ");

        int input = 0;
        if (fscanf(stdin, "%d", &input) != 1) {
            fprintf(stderr, "\nerror: Invalid input.\n");
            discard_newlines();
            getchar();

            continue;
        }
        fputc('\n', stdout);

        bool status = false;
        switch (input) {
            case INIT_ARRAY:
                status = init_arrays();
                break;
            case EVEN_ELEMS:
                status = print_even_elems();
                break;
            case ODD_ELEMS:
                status = print_odd_elems();
                break;
            case SUM_AVG:
                status = print_sum_average();
                break;
            case MAX_MIN:
                status = print_max_min();
                break;
            case REV_ORDER:
                status = print_reverse_order();
                break;
            case REM_DUPES:
                status = remove_dupes();
                break;
            case QUIT:
                // Dangerous! It is used here to avoid complications
                goto exit;
                break;
            default:
                fprintf(stderr, "error: No such option.\n");
                break;
        }

        discard_newlines();

        if (status)
            fprintf(stderr, "warn: Execution abnormally failed.\n");

        fprintf(stdout, "\nPress any key to continue. ");
        getchar();
    }

exit:
    free(array);
    fprintf(stdout, "==[ THANK YOU FOR USING THIS PROGRAM ]==\n\n");

    return 0;
}