#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

void removeRedundancy(char *line)
{
    int i = 0;
    int j = 0;
    int commentState = 0; // 0 - No comment, 1 - Single-line comment, 2 - Multi-line comment

    while (line[i] != '\0')
    {
        char currentChar = line[i];
        char nextChar = line[i + 1];

        // Check for comment
        if (currentChar == '/' && nextChar == '/')
        {
            commentState = 1;
            line[j++] = ' ';
            break;
        }
        else if (currentChar == '/' && nextChar == '*')
        {
            commentState = 2;
            line[j++] = ' ';
            i++;
        }
        else if (currentChar == '*' && nextChar == '/')
        {
            commentState = 0;
            line[j++] = ' ';
            i++;
        }

        // Ignore characters inside comments
        if (commentState > 0)
        {
            i++;
            continue;
        }

        // Ignore redundant spaces, tabs, and newlines
        if (isspace(currentChar))
        {
            if (j > 0 && !isspace(line[j - 1]))
            {
                line[j++] = ' ';
            }
        }
        // Copy non-space characters
        else
        {
            line[j++] = currentChar;
        }

        i++;
    }

    line[j] = '\0';
}

int main()
{
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        removeRedundancy(line);
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
