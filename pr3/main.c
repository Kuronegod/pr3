#include <stdio.h>

long long count_valid_numbers(int p, int last_digit, int last_count) {
    if (p == 0) {
        return 1;
    }

    long long count = 0;


    if (last_digit == 5) {

        count += count_valid_numbers(p - 1, 9, 1);

        if (last_count < 2) {
            count += count_valid_numbers(p - 1, 5, last_count + 1);
        }
    }


    if (last_digit == 9) {
        // We can add a 5 next
        count += count_valid_numbers(p - 1, 5, 1);

        if (last_count < 2) {
            count += count_valid_numbers(p - 1, 9, last_count + 1);
        }
    }

    return count;
}

long long total_valid_numbers(int p) {
    long long count = 0;


    count += count_valid_numbers(p - 1, 5, 1);


    count += count_valid_numbers(p - 1, 9, 1);

    return count;
}

int main() {
    int p;
    printf("Enter the number of digits (p): ");
    scanf("%d", &p);

    long long result = total_valid_numbers(p);

    printf("Number of valid %d-digit numbers: %lld\n", p, result);

    return 0;
}
