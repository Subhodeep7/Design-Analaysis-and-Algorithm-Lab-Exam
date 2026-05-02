#include <stdio.h>
#include <string.h>
#include <time.h>

#define d 256   // number of characters
#define q 101   // prime number (mod value)

void rabinKarp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int pHash = 0; // hash value for pattern
    int tHash = 0; // hash value for text
    int h = 1;
    int i, j;
    int found = 0;

    // Calculate h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values
    for (i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= n - m; i++) {

        // If hash values match, check characters
        if (pHash == tHash) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m) {
                printf("Pattern found at index %d\n", i);
                found = 1;
            }
        }

        // Calculate next window hash
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;

            // Convert negative hash to positive
            if (tHash < 0)
                tHash = tHash + q;
        }
    }

    if (!found) {
        printf("Pattern not found in text.\n");
    }
}

int main() {
    char text[100], pattern[50];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    // Measure CPU time
    clock_t start, end;
    double cpu_time;

    start = clock();

    rabinKarp(text, pattern);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Execution Time: %f seconds\n", cpu_time);

    return 0;
}