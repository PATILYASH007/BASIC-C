#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at a specific position in the linked list
void addNodeAtPosition(struct Node** head, int position, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to add node.\n");
        return;
    }

    newNode->data = data;

    if (position == 0) {
        // Add at the beginning
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to the node at the specified position
        struct Node* current = *head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Invalid position. Unable to add node.\n");
            free(newNode);
            return;
        }

        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Node added successfully at position %d.\n", position);
}

// Function to remove a node from the beginning of the linked list
void removeNodeFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to remove node.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    printf("Node with data %d removed from the beginning.\n", temp->data);
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add nodes at specific positions
    addNodeAtPosition(&head, 0, 5);
    addNodeAtPosition(&head, 1, 10);
    addNodeAtPosition(&head, 1, 7);

    // Print the initial linked list
    printList(head);

    // Remove node from the beginning
    removeNodeFromBeginning(&head);

    // Print the updated linked list
    printList(head);

    return 0;
}
