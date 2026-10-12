#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning()
{
    int value;
    struct Node *newNode;

    newNode = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAfter()
{
    int value, after;
    struct Node *newNode, *temp;

    printf("Enter node value after which to insert: ");
    scanf("%d", &after);

    temp = head;

    while (temp != NULL && temp->data != after)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newNode = (struct Node *) malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted :%d\n", temp->data);

    free(temp);
}

void deleteLast()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("Deleted :%d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted :%d\n", temp->data);

    free(temp);
}

void deleteAfter()
{
    int value;
    struct Node *temp, *deleteNode;

    printf("Enter node value after which to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("Node not found or no node after it\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("Deleted :%d\n", deleteNode->data);

    free(deleteNode);
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked list: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert after given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete node after given node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                deleteAfter();
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
