#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack *s, char c) { s->items[++(s->top)] = c; }
char pop(struct Stack *s) { return s->items[(s->top)--]; }

void reverseString(char *str) {
    struct Stack s = { .top = -1 };
    for (int i = 0; str[i] != '\0'; i++) push(&s, str[i]);
    for (int i = 0; s.top != -1; i++) str[i] = pop(&s);
}

int main() {
    char str[MAX_SIZE];
    printf("Input a string: ");
    fgets(str, MAX_SIZE, stdin);
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    reverseString(str);
    printf("Reversed string using a stack is: %s\n", str);
    return 0;
}