#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact book[MAX];
int count = 0;


void addContact() {
    printf("\nEnter Name: ");
    scanf("%s", book[count].name);

    printf("Enter Phone: ");
    scanf("%s", book[count].phone);

    printf("Enter Email: ");
    scanf("%s", book[count].email);

    count++;
    printf("\nContact Added Successfully!\n");
}


void searchContact() {
    char searchName[50];
    printf("\nEnter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, searchName) == 0) {
            printf("\nContact Found:\n");
            printf("Name  : %s\n", book[i].name);
            printf("Phone : %s\n", book[i].phone);
            printf("Email : %s\n", book[i].email);
            return;
        }
    }
    printf("\nContact Not Found!\n");
}


void viewAllContacts() {
    if (count == 0) {
        printf("\nNo Contacts Available.\n");
        return;
    }

    printf("\n--- All Contacts ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("Name  : %s\n", book[i].name);
        printf("Phone : %s\n", book[i].phone);
        printf("Email : %s\n", book[i].email);
    }
}


int main() {
    int choice;

    while (1) {
        printf("\n===== ADDRESS BOOK MENU =====\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. View All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: viewAllContacts(); break;
            case 4:
                printf("\nExiting... Thank You!\n");
                return 0;
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
}
