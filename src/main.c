#include <stdio.h>
#include <stdlib.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main()
{
    printf("--- Testing String Functions ---\n");

    char source[] = "Hello";
    char destination[100];

    int length = mystrlen(source);
    printf("Length of \"%s\" = %d\n", source, length);

    mystrcpy(destination, source);
    printf("After mystrcpy: %s\n", destination);

    mystrncpy(destination, "Programming", 5);
    printf("After mystrncpy: %s\n", destination);

    char first[100] = "Hello ";
    char second[] = "World";

    mystrcat(first, second);
    printf("After mystrcat: %s\n", first);


    printf("\n--- Testing File Functions ---\n");

    FILE* file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open test.txt\n");
        return 1;
    }

    int lines;
    int words;
    int chars;

    int result = wordCount(file, &lines, &words, &chars);

    if (result == 0)
    {
        printf("Lines: %d\n", lines);
        printf("Words: %d\n", words);
        printf("Characters: %d\n", chars);
    }
    else
    {
        printf("wordCount failed.\n");
    }

    fclose(file);


    file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not open test.txt\n");
        return 1;
    }

    char** matches;

    int matchCount = mygrep(file, "Hello", &matches);

    if (matchCount == -1)
    {
        printf("mygrep failed.\n");
    }
    else
    {
        printf("Lines containing \"Hello\": %d\n", matchCount);

        for (int i = 0; i < matchCount; i++)
        {
            printf("%s", matches[i]);
            free(matches[i]);
        }

        free(matches);
    }

    fclose(file);

    return 0;
}
