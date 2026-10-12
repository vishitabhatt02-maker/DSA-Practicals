#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is FULL\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;

    printf("Value inserted\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted value :%d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue :");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("\n2. Dequeue\n");
        printf("\n3. Display\n");
        printf("\n4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue();

        else if (choice == 2)
            dequeue();

        else if (choice == 3)
            display();

        else if (choice == 4)
            break;

        else
            printf("Invalid choice\n");
    }

    return 0;
}
