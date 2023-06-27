#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int hashFunction(int key, int baseSize) {
    return key % baseSize;
}

void insert(Node** table, int key, int baseSize) {
    int index = hashFunction(key, baseSize);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* curr = table[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printTable(Node** table, int baseSize) {
    int i;
    for (i = 0; i < baseSize; i++) {
        printf("%d -> ", i);
        Node* curr = table[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("\n");
    }
}

void freeTable(Node** table, int baseSize) {
    int i;
    for (i = 0; i < baseSize; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(table);
}

int main() {
    int num_testes;
    scanf("%d", &num_testes);

    int i;
    for (i = 0; i < num_testes; i++) {
        int baseSize, num_keys;
        scanf("%d %d", &baseSize, &num_keys);

        Node** table = (Node**)malloc(baseSize * sizeof(Node*));
        int j;
        for (j = 0; j < baseSize; j++) {
            table[j] = NULL;
        }

        int key;
        for (j = 0; j < num_keys; j++) {
            scanf("%d", &key);
            insert(table, key, baseSize);
        }

        printTable(table, baseSize);
        if (i != num_testes - 1) {
            printf("\n");
        }

        freeTable(table, baseSize);
    }

    return 0;
}
