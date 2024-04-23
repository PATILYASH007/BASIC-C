#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    char data;
    struct Node* next;
};

// Function to add a node at the end of the linked list
void addNodeAtEnd(struct Node** head, char data) {
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

    printf("Node with data '%c' added at the end.\n", data);
}

// Function to remove a node from the end of the linked list
void removeNodeFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to remove node.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // Traverse to the end of the list
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Remove the last node
    if (prev == NULL) {
        // If there is only one node in the list
        free(*head);
        *head = NULL;
    } else {
        prev->next = NULL;
        free(current);
    }

    printf("Node with data '%c' removed from the end.\n", current->data);
}

// Function to count the number of vowels in the linked list
int countVowels(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        char currentChar = tolower(head->data);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            count++;
        }
        head = head->next;
    }
    return count;
}

// Function to print the linked list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add nodes at the end
    addNodeAtEnd(&head, 'a');
    addNodeAtEnd(&head, 'b');
    addNodeAtEnd(&head, 'e');
    addNodeAtEnd(&head, 'i');
    addNodeAtEnd(&head, 'o');

    // Print the initial linked list
    printList(head);

    // Remove node from the end
    removeNodeFromEnd(&head);

    // Print the updated linked list
    printList(head);

    // Count the number of vowels
    int vowelCount = countVowels(head);
    printf("Number of vowels in the list: %d\n", vowelCount);

    return 0;
}
