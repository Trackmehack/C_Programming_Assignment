#include <stdio.h>
#include <ctype.h>

// Function to determine character type
const char* get_char_type(char c) {
    if (isupper(c)) return "Upper Case Letter";
    if (islower(c)) return "Lower Case Letter";
    if (isdigit(c)) return "Digit";
    if (isspace(c)) {
        if (c == ' ') return "Space";
        if (c == '\n') return "Newline";
    }
    return "Symbol";
}

int main() {
    char filename[200];  // To store the file name
    printf("Enter File Name:\n");
    scanf("%199s", filename);  // Limit input to avoid overflow

    printf("Opening File: %s\n", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char c;
    int line = 1, col = 1;

    while ((c = fgetc(file)) != EOF) {
        printf("Line %d Col %d has ASCII Code %d which is a %s.\n",
               line, col, (int)c, get_char_type(c));

        if (c == '\n') {  // Move to the next line on newline
            line++;
            col = 0;
        }
        col++;
    }

    fclose(file);
    return 0;
}
