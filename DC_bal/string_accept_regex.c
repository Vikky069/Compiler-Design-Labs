#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matchRegex(const char *regex, const char *str) {
    if (*regex == '\0') {
        // Reached the end of the regular expression.
        // If the input string is also empty, it's a match.
        // Otherwise, the input string doesn't match the regular expression.
        return (*str == '\0');
    }

    if (*(regex + 1) == '*') {
        // Handle the case where the next character is '*'.

        // Recursively check zero occurrences of the current character
        // in the regular expression and advance the regex pointer.
        if (matchRegex(regex + 2, str))
            return 1;

        // If the current character in the regular expression matches
        // the current character in the input string (or it's a '.' wildcard),
        // advance the input string pointer and continue matching.
        while (*str != '\0' && (*str == *regex || *regex == '.')) {
            if (matchRegex(regex + 2, str + 1))
                return 1;
            str++;
        }

        // If zero or more occurrences of the current character didn't match,
        // skip the '*' and the character it modifies in the regular expression
        // and continue matching the remaining string.
        return matchRegex(regex + 2, str);
    }

    // If the current character in the regular expression matches
    // the current character in the input string (or it's a '.' wildcard),
    // advance both pointers and continue matching.
    if (*str != '\0' && (*str == *regex || *regex == '.'))
        return matchRegex(regex + 1, str + 1);

    // If the current character in the regular expression doesn't match
    // the current character in the input string, or we reached the end
    // of the input string, the match fails.
    return 0;
}

int main() {
    char regex_pattern[100];
    char input_string[100];

    printf("Enter the regular expression pattern: ");
    fgets(regex_pattern, sizeof(regex_pattern), stdin);

    printf("Enter the input string: ");
    fgets(input_string, sizeof(input_string), stdin);

    // Remove newline characters from the input strings
    regex_pattern[strcspn(regex_pattern, "\n")] = '\0';
    input_string[strcspn(input_string, "\n")] = '\0';

    // Check if the input string matches the regular expression
    int isMatch = matchRegex(regex_pattern, input_string);

    if (isMatch) {
        printf("The input string matches the regular expression.\n");
    } else {
        printf("The input string does not match the regular expression.\n");
    }

    return 0;
}
