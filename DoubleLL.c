#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
void createList(struct Node** head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void deleteAtBeginning(struct Node** head);
void deleteAtEnd(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
struct Node* search(struct Node* head, int key);
void traverseForward(struct Node* head);
void menu();

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Enter data to insert at position: ");
                scanf("%d", &data);
                printf("Enter position (1-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 5:
                printf("Enter data to delete from beginning: ");
                deleteAtBeginning(&head);
                break;
            case 6:
                printf("Enter data to delete from end: ");
                deleteAtEnd(&head);
                break;
            case 7:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &key);
                {
                    struct Node* res = search(head, key);
                    if (res != NULL)
                        printf("%d found in the list.\n", key);
                    else
                        printf("%d not found in the list.\n", key);
                }
                break;
            case 9:
                printf("Traversing forward:\n");
                traverseForward(head);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void menu() {
    printf("\n*****Doubly Linked List Operations*****\n");
    printf("-----------------------------------------\n\n");

    printf("1. Create List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Specific Position\n");
    printf("5. Delete from Beginning\n");
    printf("6. Delete from End\n");
    printf("7. Delete at Specific Position\n");
    printf("8. Searching\n");
    printf("9. Traverse Forward\n");
    printf("10.Thank You Exiting......\n");
}

void createList(struct Node** head) {
    printf("Enter data for new node: ");
    int data;
    scanf("%d", &data);
    *head = NULL;
    insertAtEnd(head, data);
    printf("List created with data %d.\n", data);
    return;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("%d inserted at beginning.\n", data);
    return ;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("%d inserted as the first node.\n", data);
        return ;
    
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end.\n", data);
    return;
}
void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* temp = *head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position exceeds list length. Inserting at end.\n");
        insertAtEnd(head, data);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", data, position);
}

// Delete from beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        printf("%d deleted from end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("%d deleted from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Delete at specific position (1-based)
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    int i = 1;
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position exceeds list length.\n");
        return;
    }
    printf("%d deleted from position %d.\n", temp->data, position);
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
struct Node* search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}