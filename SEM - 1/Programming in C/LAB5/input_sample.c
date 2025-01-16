#include <stdio.h>

// This file generated with the help of GPT

int main()
{
    int id[10];
    char name[10][100];
    int age[10];
    char gender[10];
    float year[10];
    char city[10][100];

    for (int i = 0; i < 5; ++i)
    {
        // Read ID
        if (scanf("%d", &id[i]) != 1)
        {
            fprintf(stderr, "Error reading ID for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        // Read name, age, gender, year, and city
        if (fgets(name[i], sizeof(name[i]), stdin) == NULL)
        {
            fprintf(stderr, "Error reading name for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        if (scanf("%d", &age[i]) != 1)
        {
            fprintf(stderr, "Error reading age for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        if (scanf(" %c", &gender[i]) != 1)
        {
            fprintf(stderr, "Error reading gender for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        if (scanf("%f", &year[i]) != 1)
        {
            fprintf(stderr, "Error reading year for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        if (fgets(city[i], sizeof(city[i]), stdin) == NULL)
        {
            fprintf(stderr, "Error reading city for person %d\n", i + 1);
            break; // Exit loop if input fails
        }

        // Check for and ignore empty lines after reading the city
        while (city[i][0] == '\n' || city[i][0] == '\r')
        {
            if (fgets(city[i], sizeof(city[i]), stdin) == NULL)
            {
                fprintf(stderr, "Error reading city for person %d\n", i + 1);
                break; // Exit loop if input fails
            }
        }
    }

    // Process the data as needed
    for (int i = 0; i < 5; ++i)
    {
        // Process the ID, name, age, gender, year, and city as needed
        // For example, you can print them as follows:
        printf("ID %d\n", id[i]);
        printf("Name: %s", name[i]);
        printf("Age: %d\n", age[i]);
        printf("Gender: %c\n", gender[i]);
        printf("Year: %f\n", year[i]);
        printf("City: %s", city[i]);
    }

    return 0;
}
