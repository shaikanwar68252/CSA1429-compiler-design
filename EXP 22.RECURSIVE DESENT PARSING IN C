#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int expr();
int term();
int factor();

char input[100];
int pos = 0;

char getNextChar() {
    return input[pos++];
}

int factor() {
    char ch = getNextChar();
    if (isdigit(ch)) {
        return ch - '0';
    } else if (ch == '(') {
        int result = expr();
        if (getNextChar() == ')') {
            return result;
        } else {
            printf("Error: Mismatched parentheses.\n");
            exit(1);
        }
    } else {
        printf("Error: Invalid character in the input.\n");
        exit(1);
    }
}

int term() {
    int result = factor();
    char ch = getNextChar();
    while (ch == '*' || ch == '/') {
        if (ch == '*') {
            result *= factor();
        } else {
            int divisor = factor();
            if (divisor != 0) {
                result /= divisor;
            } else {
                printf("Error: Division by zero.\n");
                exit(1);
            }
        }
        ch = getNextChar();
    }
    pos--;
    return result;
}

int expr() {
    int result = term();
    char ch = getNextChar();
    while (ch == '+' || ch == '-') {
        if (ch == '+') {
            result += term();
        } else {
            result -= term();
        }
        ch = getNextChar();
    }
    pos--;
    return result;
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

    int result = expr();
    printf("Result: %d\n", result);

    return 0;
}
