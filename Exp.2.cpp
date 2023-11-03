#include <stdio.h>
#include <string.h>

int isSingleLineComment(char *line) {
    return (strncmp(line, "//", 2) == 0);
}

int isMultiLineCommentStart(char *line) {
    return (strncmp(line, "/*", 2) == 0);
}

int isMultiLineCommentEnd(char *line) {
    int len = strlen(line);
    return (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/');
}

int isComment(char *line) {
    return isSingleLineComment(line) || isMultiLineCommentStart(line) || isMultiLineCommentEnd(line);
}

int main() {
    char line[1000];
    printf("Enter a line of C code:\n");
    fgets(line, sizeof(line), stdin);

    if (isComment(line)) {
        printf("The given line is a comment.\n");
    } else {
        printf("The given line is not a comment.\n");
    }

    return 0;
}