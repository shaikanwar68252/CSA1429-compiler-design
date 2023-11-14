#include <stdio.h>
#include <cstdlib>  // Add this line to include the necessary header file

// Function prototypes
int getPrecedence(char op);
void shift(char *stack, char *input, int *stackPointer, int *inputPointer);
void reduce(char *stack, int *stackPointer);

int main() {
    char input[100];
    char stack[100];
    int stackPointer = 0;
    int inputPointer = 0;

    printf("Enter the input expression: ");
    scanf("%s", input);

    stack[stackPointer++] = '$'; // Bottom of stack marker
    stack[stackPointer] = '\0';

    printf("Parsing steps:\n");

    while (stackPointer > 0 && input[inputPointer] != '\0') {
        printf("Stack: %s, Input: %s\n", stack, input + inputPointer);

        int stackTopPrecedence = getPrecedence(stack[stackPointer - 1]);
        int inputTopPrecedence = getPrecedence(input[inputPointer]);

        if (stackTopPrecedence < inputTopPrecedence) {
            shift(stack, input, &stackPointer, &inputPointer);
        } else {
            reduce(stack, &stackPointer);
        }
    }

    printf("Stack: %s, Input: %s\n", stack, input + inputPointer);

    if (stackPointer == 2 && stack[stackPointer - 1] == '$' && input[inputPointer] == '\0') {
        printf("Parsing successful.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // For non-operators or unknown operators
    }
}

void shift(char *stack, char *input, int *stackPointer, int *inputPointer) {
    stack[(*stackPointer)++] = input[(*inputPointer)++];
    stack[*stackPointer] = '\0';
    printf("Shift: %s\n", stack);
}

void reduce(char *stack, int *stackPointer) {
    // Perform reduction based on the grammar rules
    if (stack[(*stackPointer) - 1] == 'E' && stack[(*stackPointer) - 2] == '+' && stack[(*stackPointer) - 3] == 'E') {
        // Reduce '+' rule
        (*stackPointer) -= 2;
        printf("Reduce: %s\n", stack);
    } else if (stack[(*stackPointer) - 1] == 'E' && stack[(*stackPointer) - 2] == '*' && stack[(*stackPointer) - 3] == 'E') {
        // Reduce '*' rule
        (*stackPointer) -= 2;
        printf("Reduce: %s\n", stack);
    } else {
        printf("Error: Invalid reduction\n");
        // You may handle errors differently based on your needs
        std::exit(1);  // Use std::exit instead of exit
    }
}
