#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int dataType;
} Symbol;

Symbol symbolTable[100];
int symbolCount = 0;

void insertSymbol(char name[], int dataType) {
    if (symbolCount < 100) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].dataType = dataType;
        symbolCount++;
        printf("Symbol inserted: %s\n", name);
    } else {
        printf("Symbol table full. Cannot insert more symbols.\n");
    }
}

int searchSymbol(char name[]) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tDataType\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%d\n", symbolTable[i].name, symbolTable[i].dataType);
    }
}

int main() {
    insertSymbol("variable1", 0);
    insertSymbol("variable2", 1);

    displaySymbolTable();

    char searchName[50];
    printf("Enter symbol name to search: ");
    scanf("%s", searchName);

    int index = searchSymbol(searchName);
    if (index != -1) {
        printf("Symbol found at index %d\n", index);
    } else {
        printf("Symbol not found.\n");
    }

    return 0;
}
