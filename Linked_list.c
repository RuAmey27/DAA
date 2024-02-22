/**
 * @file Linked_list.c
 * @author Amey Pande (Ameypande2709@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*Aim : Write a program to implement the Linked List and it's operations*/
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node** headRef, int data) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found in the list!\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with the given data in the linked list
struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node** headRef) {
    struct Node* temp;
    while (*headRef != NULL) {
        temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, searchData;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Search node\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &searchData);
                if (search(head, searchData) != NULL) {
                    printf("Node with data %d found in the list.\n", searchData);
                } else {
                    printf("Node with data %d not found in the list.\n", searchData);
                }
                break;
            case 5:
                printf("Linked List: ");
                printList(head);
                break;
            case 6:
                freeList(&head);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
