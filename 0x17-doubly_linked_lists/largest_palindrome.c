#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int n) {
    int reverse = 0;
    int original = n;

    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return original == reverse;
}

int main() {
    int largest_palindrome = 0;

    /* Iterate through all combinations of two 3-digit numbers */
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int product = i * j;
            if (is_palindrome(product) && product > largest_palindrome) {
                largest_palindrome = product;
            }
        }
    }

    /* Save the result to a file */
    FILE *file = fopen("102-result", "w");
    if (file != NULL) {
        fprintf(file, "%d", largest_palindrome);
        fclose(file);
    }

    return 0;
}

