#include <iostream>
#include <cstdlib> // Required for malloc() and free()

using namespace std;

#define MAX_ELEMENTS 4

// Structure for the Unrolled Linked List Node
struct Node {
    int numElements;                
    int elements[MAX_ELEMENTS];     
    struct Node* next;              
};

// Global head pointer
struct Node* head = NULL;

// Function to insert an element into the unrolled linked list
void insertElement(int val) {
    if (head == NULL) {
        head = (struct Node*)malloc(sizeof(struct Node));
        head->numElements = 1;
        head->elements[0] = val;
        head->next = NULL;
        cout << "Inserted " << val << " into a new head node.\n";
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->numElements < MAX_ELEMENTS) {
        temp->elements[temp->numElements] = val;
        temp->numElements++;
        cout << "Inserted " << val << " into the existing last node.\n";
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->numElements = 1;
        newNode->elements[0] = val;
        newNode->next = NULL;
        
        temp->next = newNode;
        cout << "Node full. Inserted " << val << " into a newly created node.\n";
    }
}

// Function to delete the first occurrence of a specific element
void deleteElement(int val) {
    if (head == NULL) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL) {
        for (int i = 0; i < temp->numElements; i++) {
            if (temp->elements[i] == val) {
                
                // Element found: Shift remaining elements left
                for (int j = i; j < temp->numElements - 1; j++) {
                    temp->elements[j] = temp->elements[j + 1];
                }
                temp->numElements--; 
                
                cout << "Element " << val << " deleted successfully.\n";

                // Check if the node is now completely empty
                if (temp->numElements == 0) {
                    if (prev == NULL) {
                        head = temp->next;
                        free(temp);
                    } else {
                        prev->next = temp->next;
                        free(temp);
                    }
                    cout << "An empty node was removed from the list.\n";
                }
                return; 
            }
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Element " << val << " not found in the list.\n";
}

// Function to display the elements in the list
void displayList() {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }
    
    struct Node* temp = head;
    int nodeCount = 1;
    
    cout << "\n--- Unrolled Linked List Content ---\n";
    while (temp != NULL) {
        cout << "Node " << nodeCount << " (" << temp->numElements << "/" << MAX_ELEMENTS << " elements): [";
        for (int i = 0; i < temp->numElements; i++) {
            cout << temp->elements[i];
            if (i < temp->numElements - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
        
        temp = temp->next;
        nodeCount++;
    }
    cout << "------------------------------------\n";
}

// Function to search for an element
void searchElement(int val) {
    if (head == NULL) {
        cout << "The list is empty.\n";
        return;
    }

    struct Node* temp = head;
    int nodeCount = 1;
    
    while (temp != NULL) {
        for (int i = 0; i < temp->numElements; i++) {
            if (temp->elements[i] == val) {
                cout << "Element " << val << " found in Node " << nodeCount << " at index " << i << ".\n";
                return; 
            }
        }
        temp = temp->next;
        nodeCount++;
    }
    
    cout << "Element " << val << " not found in the list.\n";
}

// Function to destroy the entire list and free all memory
void destroyList() {
    if (head == NULL) {
        cout << "The list is already empty.\n";
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next; 
        free(temp);                         
        temp = nextNode;                    
    }
    
    head = NULL; 
    cout << "The entire list has been destroyed and memory freed.\n";
}

int main() {
    int choice, value;
    
    do {
        cout << "\n=== Unrolled Linked List Menu ===\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display List\n";
        cout << "4. Search Element\n";
        cout << "5. Destroy List (Clear All)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter integer value to insert: ";
                cin >> value;
                insertElement(value);
                break;
            case 2:
                cout << "Enter integer value to delete: ";
                cin >> value;
                deleteElement(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                cout << "Enter integer value to search: ";
                cin >> value;
                searchElement(value);
                break;
            case 5:
                destroyList();
                break;
            case 6:
                destroyList(); // Clean up before closing the program
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}