#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int l = strlen(s);
    char* stack = (char*)malloc((l + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i <l; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--;
        } else {
            stack[++top] = s[i];
        }
    }

    stack[top + 1] = '\0';
    return stack;
}

int main() {
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);

    char* result = removeDuplicates(s);
    printf("Final string after duplicate removals: %s\n", result);

     // Freeing the dynamically allocated memory
    return 0;
}
