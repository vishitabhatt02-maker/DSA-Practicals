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
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAfter()
{
    int value, after;
    struct Node *newNode, *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter node value after which to insert: ");
    scanf("%d", &after);

    temp = head;

    do
    {
        if (temp->data == after)
            break;

        temp = temp->next;
    }
    while (temp != head);

    if (temp->data != after)
    {
        printf("Node not found\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst()
{
    struct Node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted: %d\n", temp->data);
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

    if (head->next == head)
    {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteAfter()
{
    int value;
    struct Node *temp, *del;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter node value after which to delete: ");
    scanf("%d", &value);

    temp = head;

    do
    {
        if (temp->data == value)
            break;

        temp = temp->next;
    }
    while (temp != head);

    if (temp->data != value || temp->next == head)
    {
        printf("Node not found or no node after it\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;

    printf("Deleted: %d\n", del->data);
    free(del);
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

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("Back to head\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
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
}7
