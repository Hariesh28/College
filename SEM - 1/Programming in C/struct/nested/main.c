# include <stdio.h>

struct emp {

    char name[25];
    int id;
};

struct empad {

    char city[25];
    char ph[11];
    struct emp e;  
} a;

int main() {

    printf("Name: ");
    scanf("%s", a.e.name);
    printf("%s", a.e.name);

    printf("\nId: ");
    scanf("%d", &a.e.id);
    printf("%d", a.e.id);

    printf("\nCity: ");
    scanf("%s", &a.e.id);
    printf("%s", a.city);
    
    fflush(stdin);

    printf("\nphone: ");
    scanf("%s", &a.e.id);
    printf("%s", a.ph);

}