#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int case_num = 1; case_num <= num_test_cases; case_num++) {
        int num_numbers;
        scanf("%d", &num_numbers);

        Node* root = NULL;
        for (int i = 0; i < num_numbers; i++) {
            int number;
            scanf("%d", &number);
            root = insert(root, number);
        }

        printf("Case %d:\n", case_num);
        printf("Pre.: ");
        preOrder(root);
        printf("\n");

        printf("In..: ");
        inOrder(root);
        printf("\n");

        printf("Post: ");
        postOrder(root);
        printf("\n");

        printf("\n");

        freeTree(root);
    }

    return 0;
}
