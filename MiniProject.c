#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left, *right;
};

struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode = malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, char name[], char phone[]) {
    if (root == NULL)
        return createNode(name, phone);

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = insert(root->left, name, phone);
    else if (cmp > 0)
        root->right = insert(root->right, name, phone);
    else
        printf("Contact already exists!\n");

    return root;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("Name: %s | Phone: %s\n",
               root->name, root->phone);
        display(root->right);
    }
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteContact(struct Node* root, char name[]) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = deleteContact(root->left, name);
    else if (cmp > 0)
        root->right = deleteContact(root->right, name);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteContact(root->right, temp->name);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    struct Node* result;
    char name[50], phone[15];
    int choice;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %49[^\n]", name);

                printf("Enter phone: ");
                scanf("%14s", phone);

                root = insert(root, name, phone);
                break;

            case 2:
                printf("Enter name to search: ");
                scanf(" %49[^\n]", name);

                result = search(root, name);

                if (result != NULL)
                    printf("Contact found!\nName: %s\nPhone: %s\n",
                           result->name, result->phone);
                else
                    printf("Contact not found!\n");
                break;

            case 3:
                if (root == NULL)
                    printf("No contacts available.\n");
                else {
                    printf("\nContact List (Alphabetical Order):\n");
                    display(root);
                }
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf(" %49[^\n]", name);

                if (search(root, name) != NULL) {
                    root = deleteContact(root, name);
                    printf("Contact deleted successfully!\n");
                } else {
                    printf("Contact not found!\n");
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
