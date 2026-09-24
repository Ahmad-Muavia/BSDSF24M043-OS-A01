#include "../include/myfilefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars)
{
    if (file == NULL || lines == NULL || words == NULL || chars == NULL)
    {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    int inWord = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF)
    {
        (*chars)++;

        if (ch == '\n')
        {
            (*lines)++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            (*words)++;
            inWord = 1;
        }
    }

    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches)
{
    if (fp == NULL || search_str == NULL || matches == NULL)
    {
        return -1;
    }

    char line[1000];
    int count = 0;
    int capacity = 10;

    *matches = malloc(capacity * sizeof(char*));

    if (*matches == NULL)
    {
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, search_str) != NULL)
        {
            if (count == capacity)
            {
                capacity = capacity * 2;

                char** temp = realloc(*matches,
                                      capacity * sizeof(char*));

                if (temp == NULL)
                {
                    for (int i = 0; i < count; i++)
                    {
                        free((*matches)[i]);
                    }

                    free(*matches);
                    *matches = NULL;

                    return -1;
                }

                *matches = temp;
            }

            (*matches)[count] = malloc(strlen(line) + 1);

            if ((*matches)[count] == NULL)
            {
                for (int i = 0; i < count; i++)
                {
                    free((*matches)[i]);
                }

                free(*matches);
                *matches = NULL;

                return -1;
            }

            strcpy((*matches)[count], line);
            count++;
        }
    }

    return count;
}
