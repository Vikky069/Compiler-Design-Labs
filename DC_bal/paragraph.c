#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    char paragraph[MAX_SIZE];
    int characterCount, wordCount, lineCount;

    // Initialize counters
    characterCount = wordCount = lineCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX_SIZE, stdin);

    // Count characters, words, and lines
    for (int i = 0; paragraph[i] != '\0'; i++) {
        // Count characters
        if (paragraph[i] != ' ' && paragraph[i] != '\n') {
            characterCount++;
        }

        // Count words
        if (paragraph[i] == ' ' || paragraph[i] == '\n') {
            wordCount++;
        }

        // Count lines
        if (paragraph[i] == '\n') {
            lineCount++;
        }
    }

    // Increment word count by 1 to account for the last word
    wordCount++;

    printf("Total characters: %d\n", characterCount);
    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);

    return 0;
}
