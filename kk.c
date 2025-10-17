#include <stdio.h>
#include <stdlib.h>
// Structure of a node
struct Node {
    int data;
    struct Node* next;
};
// Function to create linked list
struct Node* createLinkedList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;
    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}
int search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
// Function to display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int n;
    struct Node* head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    displayList(head);
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);  
    int position = search(head, key);
    if (position != -1) {
        printf("Key %d found at position %d\n", key, position);
    } else {
        printf("Key %d not found in the list\n", key);
    }

    return 0;
}


