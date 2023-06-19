#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 201

struct node {
    char palavra[MAX_WORD_LENGTH];
    struct node* left;
    struct node* right;
};

struct node* createNode(const char* palavra) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->palavra, palavra);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* inserir(struct node* root, const char* palavra) {
    if (root == NULL) {
        return createNode(palavra);
    }

    int cmp = strcasecmp(palavra, root->palavra);
    if (cmp < 0) {
        root->left = inserir(root->left, palavra);
    } else if (cmp > 0) {
        root->right = inserir(root->right, palavra);
    }

    return root;
}

int isAlphaWord(const char* palavra) {
    int length = strlen(palavra);

    for (int i = 0; i < length; i++) {
        if (!isalpha(palavra[i])) {
            return 0;
        }
    }
    return (length > 0);  // Ignora palavras vazias
}



void printArvore(struct node* root) {
    if (root == NULL) {
        return;
    }

    printArvore(root->left);
    printf("%s\n", root->palavra);
    printArvore(root->right);
}

void freeTree(struct node* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    char palavra[MAX_WORD_LENGTH];
    struct node* root = NULL;

    while (scanf("%s", palavra) != EOF) {
        for (int i = 0; palavra[i] != '\0'; i++) {
            palavra[i] = tolower(palavra[i]);
        }
        if (isAlphaWord(palavra)) {
            root = inserir(root, palavra);
        }
    }

    printArvore(root);
    freeTree(root);

    return 0;
}
