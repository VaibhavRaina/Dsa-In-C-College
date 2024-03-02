#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;
};

struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->is_end_of_word = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createNode(); 
        }
        node = node->children[index];
    }
    node->is_end_of_word = true;
}

bool search(struct TrieNode* root, const char* word) {
    struct TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!node || !node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return (node != NULL && node->is_end_of_word);
}

bool isEmpty(struct TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return false;
        }
    }
    return true;
}

struct TrieNode* deleteNode(struct TrieNode* root, const char* word, int depth) {
    if (!root) {
        return NULL;
    }

    if (word[depth] == '\0') {
        if (root->is_end_of_word) {
            root->is_end_of_word = false;
        }

        if (isEmpty(root)) {
            free(root);
            root = NULL;
        }

        return root;
    }

    int index = word[depth] - 'a';
    root->children[index] = deleteNode(root->children[index], word, depth + 1);

    if (isEmpty(root) && !root->is_end_of_word) {
        free(root);
        root = NULL;
    }

    return root;
}


int main() {
    struct TrieNode* root = createNode();

    char word[100];
    int choice;

    do {
        printf("\nTrie Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the word to insert: ");
                scanf("%s", word);
                insert(root, word);
                break;
            case 2:
                printf("Enter the word to search: ");
                scanf("%s", word);
                printf("%s\n", search(root, word) ? "Found" : "Not Found");
                break;
            case 3:
                printf("Enter the word to delete: ");
                scanf("%s", word);
                root = deleteNode(root, word, 0);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

