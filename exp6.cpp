#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static const int initial_permutation[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

static const uint64_t key = 0x133457799BBCDFF1;

uint64_t initial_permutation_function(uint64_t input) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((input >> (64 - initial_permutation[i])) & 1) << (63 - i);
    }
    return result;
}

void print_binary(uint64_t value) {
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (value >> i) & 1);
    }
    printf("\n");
}

int main() {
    uint64_t data = 0x0123456789ABCDEF;
    uint64_t permuted_data = initial_permutation_function(data);

    printf("Initial Permuted Data: ");
    print_binary(permuted_data);

    return 0;
}
#include<stdio.h>

