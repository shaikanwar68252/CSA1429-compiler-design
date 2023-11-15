#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char input[100];
int pos = 0;

void error() {
    printf("Error: Invalid input.\n");
    exit(1);
}

void E();
void T();
void F();

char getNextChar() {
    return input[pos++];
}

void skipWhitespace() {
    while (isspace(input[pos])) {
        pos++;
    }
}

void E() {
    T();
    skipWhitespace();
    while (input[pos] == '+') {
        pos++;
        skipWhitespace();
        T();
        skipWhitespace();
    }
}

void T() {
    F();
    skipWhitespace();
    while (input[pos] == '*') {
        pos++;
        skipWhitespace();
        F();
        skipWhitespace();
    }
}

void F() {
    skipWhitespace();
    if (isdigit(input[pos])) {
        pos++;
    } else if (input[pos] == '(') {
        pos++;
        E();
        if (input[pos] == ')') {
            pos++;
        } else {
            error();
        }
    } else {
        error();
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    E();  // Start parsing from the top-level expression

    if (input[pos] == '\0') {
        printf("Parsing successful.\n");
    } else {
        error();
    }

    return 0;
}
