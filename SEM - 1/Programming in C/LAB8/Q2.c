#include <stdio.h>
#include <string.h>

void main(){

    char arr[] = "hello";
    char vowels[6] = {'a', 'e', 'i', 'o', 'u'};
    int vowelsInStr = 0;
    float percentage;

    for(int i = 0; i < strlen(arr); i++) for(int j = 0; j < strlen(vowels); j++) if(arr[i] == vowels[j]) vowelsInStr++;
    
    percentage = (vowelsInStr * 100.00) / (float) strlen(arr);  
    printf("%.2f\n", percentage);
}