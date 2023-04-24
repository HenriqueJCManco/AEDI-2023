#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* name;
    struct node* next;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

Node* insertBefore(Node* head, char* suggestion, Node* newFriendsHead) {
    if (head == NULL) {
        return newFriendsHead;
    }
    if (strcmp(head->name, suggestion) == 0) {
        Node* newFriendsTail = newFriendsHead;
        while (newFriendsTail->next != NULL) {
            newFriendsTail = newFriendsTail->next;
        }
        newFriendsTail->next = head;
        return newFriendsHead;
    }
    head->next = insertBefore(head->next, suggestion, newFriendsHead);
    return head;
}

int main() {
    char* current = NULL;
    size_t n = 0;
    getline(&current, &n, stdin);

    // remove newline character
    current[strcspn(current, "\n")] = '\0';

    Node* head = NULL;
    char* name = strtok(current, " ");
    while (name != NULL) {
        head = insertBefore(head, "", createNode(name));
        name = strtok(NULL, " ");
    }

    char* newFriends = NULL;
    n = 0;
    getline(&newFriends, &n, stdin);

    // remove newline character
    newFriends[strcspn(newFriends, "\n")] = '\0';

    Node* newFriendsList = NULL;
    char* newFriend = strtok(newFriends, " ");
    while (newFriend != NULL) {
        newFriendsList = insertBefore(newFriendsList, "", createNode(newFriend));
        newFriend = strtok(NULL, " ");
    }

    char* suggestion = NULL;
    n = 0;
    getline(&suggestion, &n, stdin);

    // remove newline character
    suggestion[strcspn(suggestion, "\n")] = '\0';

    if (strcmp(suggestion, "nao") == 0) {
        head = insertBefore(head, "", newFriendsList);
    } else {
        head = insertBefore(head, suggestion, newFriendsList);
    }

    Node* currentFriend = head;
    int isFirst = 1;
    while (currentFriend != NULL) {
        if (isFirst) {
            printf("%s", currentFriend->name);
            isFirst = 0;
        } else {
            printf(" %s", currentFriend->name);
        }
    currentFriend = currentFriend->next;
}
    printf("\n");

    return 0;
}