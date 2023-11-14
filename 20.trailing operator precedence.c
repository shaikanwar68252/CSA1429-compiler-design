#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool isTerminal(char symbol) {
    return isalnum(symbol) || symbol == '+' || symbol == '*' || symbol == '(' || symbol == ')';
}


void computeTrailingSet(char nonTerminal, bool trailingSet[], const char grammar[][256], int numRules) {
    for (int i = 0; i < numRules; i++) {
        int len = strlen(grammar[i]);
        if (grammar[i][len - 1] == nonTerminal) {
            for (int j = len - 2; j >= 0; j--) {
                if (isTerminal(grammar[i][j]) && grammar[i][j] != 'e') {
                    trailingSet[grammar[i][j]] = true;
                }
                if (isTerminal(grammar[i][j]) || grammar[i][j] == nonTerminal) {
                    break;
                }
            }
        }
    }
}

int main() {
    const int MAX_RULES = 10;
    const int MAX_RULE_LENGTH = 256;
    const int MAX_NON_TERMINALS = 256;

    char grammar[MAX_RULES][MAX_RULE_LENGTH];
    int numRules;

    char nonTerminals[MAX_NON_TERMINALS];
    int numNonTerminals = 0;

    
    printf("Enter the number of grammar rules: ");
    scanf("%d", &numRules);

    printf("Enter the grammar rules (e.g., E->E+T): \n");
    for (int i = 0; i < numRules; i++) {
        scanf("%s", grammar[i]);

        char nonTerminal = grammar[i][0];
        if (isupper(nonTerminal) && strchr(nonTerminals, nonTerminal) == NULL) {
            nonTerminals[numNonTerminals] = nonTerminal;
            numNonTerminals++;
        }
    }

    bool trailingSets[MAX_NON_TERMINALS][256];

    
    for (int i = 0; i < numNonTerminals; i++) {
        for (int j = 0; j < 256; j++) {
            trailingSets[i][j] = false;
        }
    }

    
    for (int i = 0; i < numNonTerminals; i++) {
        computeTrailingSet(nonTerminals[i], trailingSets[i], grammar, numRules);
    }

   
    for (int i = 0; i < numNonTerminals; i++) {
        printf("TRAILING(%c): {", nonTerminals[i]);
        bool first = true;
        for (int j = 0; j < 256; j++) {
            if (trailingSets[i][j]) {
                if (!first) {
                    printf(", ");
                }
                printf("%c", j);
                first = false;
            }
        }
        printf("}\n");
    }

    return 0;
}
