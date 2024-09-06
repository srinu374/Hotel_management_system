#include <stdio.h>
#include <string.h>

// Define a structure to represent a hotel guest
struct Guest {
    int id;
    char name[100];
    int age;
    char roomType[50];
};

// Function prototypes
void addGuest(struct Guest guests[], int *count);
void displayGuests(const struct Guest guests[], int count);

int main() {
    struct Guest guests[100]; // Array to store guest records
    int guestCount = 0; // Number of guests
    int choice;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest(guests, &guestCount);
                break;
            case 2:
                displayGuests(guests, guestCount);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a guest record
void addGuest(struct Guest guests[], int *count) {
    if (*count >= 100) {
        printf("Guest list is full. Cannot add more guests.\n");
        return;
    }

    struct Guest newGuest;

    printf("Enter guest ID: ");
    scanf("%d", &newGuest.id);
    printf("Enter guest name: ");
    scanf(" %[^\n]", newGuest.name); // Read string with spaces
    printf("Enter guest age: ");
    scanf("%d", &newGuest.age);
    printf("Enter room type: ");
    scanf(" %[^\n]", newGuest.roomType); // Read string with spaces

    guests[*count] = newGuest;
    (*count)++;

    printf("Guest added successfully.\n");
}

// Function to display all guest records
void displayGuests(const struct Guest guests[], int count) {
    if (count == 0) {
        printf("No guests to display.\n");
        return;
    }

    printf("\nGuest Records:\n");
    printf("ID\tName\t\t\tAge\tRoom Type\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%d\t%s\n", guests[i].id, guests[i].name, guests[i].age, guests[i].roomType);
    }
}

