/*Implementation of static hash table with Linear Probing. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define EMPTY -1

// Hash table
int hashtable[SIZE];

// Initialize hash table
void initialize_table() {
    for (int i = 0; i < SIZE; i++) {
        hashtable[i] = EMPTY;
    }
}

// Hash function
int hash_function(int key) {
    return key % SIZE;
}

// Insert function using Linear Probing
void insert(int key) {
    int index = hash_function(key);
    int i = 0, new_index;

    // Find the next empty slot using Linear Probing
    while (hashtable[(new_index = (index + i) % SIZE)] != EMPTY) {
        i++;
        if (i == SIZE) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }

    // Insert the key into the hash table
    hashtable[new_index] = key;
    printf("Inserted %d at index %d\n", key, new_index);
}

// Display the hash table
void display() {
    printf("Hash table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashtable[i] == EMPTY) {
            printf("Index %d: EMPTY\n", i);
        } else {
            printf("Index %d: %d\n", i, hashtable[i]);
        }
    }
}

// Main function
int main() {
    int choice, key;
    initialize_table();

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}