#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Change {
    int position;
    struct Change* next;
} Change;

Change* top = NULL;
char text[MAX_SIZE];
int textLength = 0;

void insertChange(const char* str) {
    int len = strlen(str);
    if (textLength + len >= MAX_SIZE) {
        printf("Limite de tamanho excedido\n");
        return;
    }

    strncpy(text + textLength, str, len);
    textLength += len;

    Change* newChange = (Change*)malloc(sizeof(Change));
    if (newChange == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    newChange->position = textLength;
    newChange->next = top;
    top = newChange;
}

char* undoChange() {
    if (top == NULL) {
        return "NULL";
    }

    Change* temp = top;
    top = top->next;

    int len = temp->position - (top ? top->position : 0);
    char* result = (char*)malloc(len + 1);
    if (result == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    strncpy(result, text + (top ? top->position : 0), len);
    result[len] = '\0';

    free(temp);
    textLength = top ? top->position : 0;

    return result;
}

int main() {
    char command[MAX_SIZE];

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "inserir") == 0) {
            char str[MAX_SIZE];
            scanf("%s", str);
            insertChange(str);
        } else if (strcmp(command, "desfazer") == 0) {
            char* result = undoChange();
            printf("%s\n", result);
            free(result);
        }
    }

    while (top != NULL) {
        Change* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}








