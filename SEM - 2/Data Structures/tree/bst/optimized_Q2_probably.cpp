#include <stdio.h>
#include <stdbool.h>

#define MAX_CHAR 256

void ideal_substring(char[], int, int);

int main() {
    int len, substring;
    
    printf("Enter the length of the string: ");
    scanf("%d", &len);

    char string[len + 1];

    printf("Enter the string: ");
    scanf("%s", string);

    printf("Enter the length of the substring: ");
    scanf("%d", &substring);

    printf("Ideal Substrings are: ");
    ideal_substring(string, len, substring);

    return 0;
}

void ideal_substring(char array[], int size, int substring_size) {
    bool exists[MAX_CHAR] = {false};
    int start = 0, end = 0, count = 0;

    while (end < size) {
        // Expand the window
        while (end - start < substring_size && end < size) {
            if (exists[array[end]]) {
                while (array[start] != array[end]) {
                    exists[array[start]] = false;
                    start++;
                }
                start++;
            } else {
                exists[array[end]] = true;
            }
            end++;
        }
        
        // Check if ideal substring found
        if (end - start == substring_size) {
            for (int i = start; i < end; i++) {
                printf("%c", array[i]);
            }
            printf(" ");
            count++;
        }

        // Shrink the window
        exists[array[start]] = false;
        start++;
    }

    printf("\nTotal Ideal Substrings: %d\n", count);
}
