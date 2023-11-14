#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValidIdentifier(const char *input) {
    if (strlen(input) == 0 || isdigit(input[0]))
        return false;
        int i;
    for (i = 0; i < strlen(input); i++) {
        char currentChar = input[i];

        if (!(isalpha(currentChar) || isdigit(currentChar) || currentChar == '_'))
            return false;
    }

    return true;
}

int main() {
    char input[100];

    printf("Enter an identifier: ");
    scanf("%s", input);

    if (isValidIdentifier(input))
        printf("%s is a valid identifier.\n", input);
    else
        printf("%s is not a valid identifier.\n", input);

    return 0;
}
