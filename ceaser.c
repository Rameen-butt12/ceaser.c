#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Function definition
bool only_digits(string s) {
    for (int j = 0; j < strlen(s); j++) {
        if (!isdigit(s[j]))
            return false;
    }
    return true;
}

int main(int argc, string argv[]) {
    // Argument check
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: ./program key (positive integer only)\n");
        return 1;
    }

    int key = atoi(argv[1]); // Convert string to integer
    string p = get_string("Enter text: \n");

    printf("Ciphertext: ");
    for (int i = 0; i < strlen(p); i++) {
        if (isupper(p[i])) {
            printf("%c", (p[i] - 'A' + key) % 26 + 'A');
        }
        else if (islower(p[i])) {
            printf("%c", (p[i] - 'a' + key) % 26 + 'a');
        }
        else {
            printf("%c", p[i]); // Non-alphabetic characters unchanged
        }
    }
    printf("\n");
    return 0;
}
