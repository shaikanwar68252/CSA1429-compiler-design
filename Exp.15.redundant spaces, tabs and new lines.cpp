#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 50

// Token types
typedef enum {
    TOKEN_UNKNOWN,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD
} TokenType;

// Token structure to store token type and value
typedef struct {
    TokenType type;
    char value[MAX_IDENTIFIER_LENGTH];
} Token;

// Function to skip whitespace and comments
void skipWhitespaceAndComments(FILE* input) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            continue; // Skip whitespace and newlines
        } else if (c == '/') {
            if ((c = fgetc(input)) == '/') {
                // Ignore single-line comments
                while ((c = fgetc(input)) != '\n' && c != EOF);
            } else if (c == '*') {
                // Ignore multi-line comments
                while (1) {
                    c = fgetc(input);
                    if (c == '*') {
                        if ((c = fgetc(input)) == '/') {
                            break;
                        }
                    } else if (c == EOF) {
                        // Handle unterminated multi-line comment error
                        printf("Error: Unterminated comment\n");
                        exit(1);
                    }
                }
            } else {
                ungetc(c, input); // Not a comment, put character back
                break;
            }
        } else {
            ungetc(c, input);
            break;
        }
    }
}

// Function to recognize and return the next token
Token getNextToken(FILE* input) {
    Token token;
    int c;

    // Initialize the token as an unknown token
    token.type = TOKEN_UNKNOWN;
    token.value[0] = '\0';

    // Skip whitespace and comments
    skipWhitespaceAndComments(input);

    // Read the next character
    c = fgetc(input);

    if (c == EOF) {
        token.type = TOKEN_UNKNOWN;
    } else if (isalpha(c) || c == '_') {
        // Recognize keywords and identifiers
        int i = 0;
        token.value[i++] = (char)c;
        while ((c = fgetc(input)) != EOF && (isalnum(c) || c == '_')) {
            if (i < MAX_IDENTIFIER_LENGTH - 1) {
                token.value[i++] = (char)c;
            }
        }
        token.value[i] = '\0';

        // Check if it's a keyword
        if (strcmp(token.value, "if") == 0 || strcmp(token.value, "else") == 0) {
            token.type = TOKEN_KEYWORD;
        } else {
            token.type = TOKEN_IDENTIFIER;
        }

        ungetc(c, input);
    } else if (isdigit(c)) {
        // Recognize numbers
        int i = 0;
        token.value[i++] = (char)c;
        while ((c = fgetc(input)) != EOF && isdigit(c)) {
            if (i < MAX_IDENTIFIER_LENGTH - 1) {
                token.value[i++] = (char)c;
            }
        }
        token.value[i] = '\0';
        token.type = TOKEN_NUMBER;
        ungetc(c, input);
    } else {
        // Recognize operators
        token.value[0] = (char)c;
        token.value[1] = '\0';
        token.type = TOKEN_OPERATOR;
    }

    return token;
}

int main() {
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    Token token;
    do {
        token = getNextToken(input);
        if (token.type != TOKEN_UNKNOWN) {
            printf("Token Type: %d, Value: %s\n", token.type, token.value);
        }
    } while (token.type != TOKEN_UNKNOWN);

    fclose(input);
    return 0;
}
