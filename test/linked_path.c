#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list node
struct PathNode {
    char *directory;
    struct PathNode *next;
};

// Function to build the linked list of PATH directories
struct PathNode *buildPathList() {
    char *path = getenv("PATH");

    if (path == NULL) {
        printf("PATH environment variable is not set.\n");
        return NULL;
    }

    struct PathNode *head = NULL;
    struct PathNode *tail = NULL;

    char *token = strtok(path, ":");
    while (token != NULL) {
        struct PathNode *newNode = (struct PathNode *)malloc(sizeof(struct PathNode));
        if (newNode == NULL) {
            perror("malloc");
            exit(1);
        }

        newNode->directory = strdup(token);
        newNode->next = NULL;

        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        token = strtok(NULL, ":");
    }

    return head;
}

// Function to free the linked list
void freePathList(struct PathNode *head) {
    while (head != NULL) {
        struct PathNode *temp = head;
        head = head->next;
        free(temp->directory);
        free(temp);
    }
}

int main() {
    printf("Linked list of PATH directories:\n");
    struct PathNode *pathList = buildPathList();

    struct PathNode *current = pathList;
    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }

    // Free the linked list
    freePathList(pathList);

    return 0;
}

