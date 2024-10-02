#include <stdio.h>

#define MAX_CHAR 256 // Maximum number of characters (ASCII)

void ideal_substring(char[], int, int);

int main(){

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

void ideal_substring(char array[], int size, int substring_size){

    char window[substring_size];

    for(int i = 0; i < size - substring_size + 1; i++){

        int flag = 1;
        
        for(int j = 0; j < substring_size; j++) // Initialize the window
            window[j] = array[i + j];

        int count[MAX_CHAR] = {0}; // Initialize count array with all 0's

        for(int k = 0; window[k] != 0; k++) // Check for duplicates
            count[(unsigned char)window[k]]++;

        for(int k = 0; k < MAX_CHAR; k++){

            if(count[k] > 1){

                flag = 0;
                break;
            }
        }

        if(flag){

            for(int j = 0; j < substring_size; j++)
                printf("%c", window[j]);
            
            printf(" ");
        }
    }
}


// Slightly Optimized Version of the above code
/*

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


*/