#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILENAME 100
#define MAX_LINE_LENGTH 100

int main() {
    char filename[MAX_FILENAME];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        lineCount++;

        int i = 0;
        bool inWord = false;

        while (line[i] != '\0') {
            char currentChar = line[i];
            char nextChar = line[i + 1];

            if (isalnum(currentChar)) {
                charCount++;

                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else if (isspace(currentChar)) {
                if (inWord)
                    inWord = false;
            }

            i++;
        }
    }

    fclose(file);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}
