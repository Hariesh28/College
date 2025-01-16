# include <stdio.h>
# include <string.h>

int main() {

    int random, index = 0, value;
    char day[15];
    char days[][50] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("Enter day: ");
    scanf("%s", day);

    printf("\nEnter random number: ");
    scanf("%d", &random);

    for(int i = 0; i < 7; i++) if(strcmp(day, days[i]) == 0) index = (i);
    
    value = (index + random) % 7;

    printf("\nReq day is: %s", days[value]);

    return 0;
}