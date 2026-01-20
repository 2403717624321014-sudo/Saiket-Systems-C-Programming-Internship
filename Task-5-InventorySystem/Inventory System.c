#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[100];
int count = 0;


void addItem() {
    printf("\nEnter Item Name: ");
    scanf("%s", inventory[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[count].price);

    count++;
    printf("\nItem Added Successfully!\n");
}

void updateItem() {
    char name[50];
    printf("\nEnter Item Name to Update: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter New Quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter New Price: ");
            scanf("%f", &inventory[i].price);

            printf("\nItem Updated Successfully!\n");
            return;
        }
    }

    printf("\nItem Not Found!\n");
}


void removeItem() {
    char name[50];
    printf("\nEnter Item Name to Remove: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("\nItem Removed Successfully!\n");
            return;
        }
    }

    printf("\nItem Not Found!\n");
}


void displayItems() {
    if (count == 0) {
        printf("\nInventory is Empty!\n");
        return;
    }

    printf("\n---- Current Inventory ----\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Quantity: %d | Price: %.2f\n",
               i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Remove Item\n");
        printf("4. Display Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: removeItem(); break;
            case 4: displayItems(); break;
            case 5: printf("\nExiting Program...\n"); return 0;
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    }
}
