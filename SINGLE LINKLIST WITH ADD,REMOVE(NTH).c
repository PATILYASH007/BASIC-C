#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
void addNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to add node.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Traverse to the end of the list
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Add the new node at the end
        current->next = newNode;
    }

    printf("Node with data %d added at the end.\n", data);
}

// Function to remove the nth node from the linked list
void removeNthNode(struct Node** head, int n) {
    if (*head == NULL) {
        printf("List is empty. Unable to remove node.\n");
        return;
    }

    if (n <= 0) {
        printf("Invalid position. Unable to remove node.\n");
        return;
    }

    // Special case: Remove the head node
    if (n == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Node with data %d removed from position %d.\n", temp->data, n);
        free(temp);
        return;
    }

    // Traverse to the (n-1)th node
    struct Node* current = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < n && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Unable to remove node.\n");
        return;
    }

    // Remove the nth node
    prev->next = current->next;
    printf("Node with data %d removed from position %d.\n", current->data, n);
    free(current);
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

    // Add nodes at the end
    addNodeAtEnd(&head, 5);
    addNodeAtEnd(&head, 10);
    addNodeAtEnd(&head, 15);

    // Print the initial linked list
    printList(head);

    // Remove the nth node
    removeNthNode(&head, 2);

    // Print the updated linked list
    printList(head);

    return 0;
}
