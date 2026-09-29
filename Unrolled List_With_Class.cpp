#include <iostream>

using namespace std;

const int MAX_ELEMENTS = 4;

class UnrolledLinkedList {
private:
    // Structure for the Unrolled Linked List Node, encapsulated within the class
    struct Node {
        int numElements;
        int elements[MAX_ELEMENTS];
        Node* next;

        // Constructor to streamline node initialization
        Node(int val) {
            numElements = 1;
            elements[0] = val;
            next = nullptr;
        }
    };

    // Private head pointer, replacing the global variable
    Node* head;

public:
    // Constructor
    UnrolledLinkedList() {
        head = nullptr;
    }

    // Destructor to ensure memory is freed when the object goes out of scope
    ~UnrolledLinkedList() {
        if (head != nullptr) {
            destroyList(false); // Suppress output during automatic destruction
        }
    }

    // Function to insert an element into the unrolled linked list
    void insertElement(int val) {
        if (head == nullptr) {
            head = new Node(val);
            cout << "Inserted " << val << " into a new head node.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        if (temp->numElements < MAX_ELEMENTS) {
            temp->elements[temp->numElements] = val;
            temp->numElements++;
            cout << "Inserted " << val << " into the existing last node.\n";
        } else {
            Node* newNode = new Node(val);
            temp->next = newNode;
            cout << "Node full. Inserted " << val << " into a newly created node.\n";
        }
    }

    // Function to delete the first occurrence of a specific element
    void deleteElement(int val) {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
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
                        if (prev == nullptr) {
                            head = temp->next;
                        } else {
                            prev->next = temp->next;
                        }
                        delete temp; // Use delete instead of free()
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
    void displayList() const {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        
        Node* temp = head;
        int nodeCount = 1;
        
        cout << "\n--- Unrolled Linked List Content ---\n";
        while (temp != nullptr) {
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
    void searchElement(int val) const {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        Node* temp = head;
        int nodeCount = 1;
        
        while (temp != nullptr) {
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
    void destroyList(bool printMessage = true) {
        if (head == nullptr) {
            if (printMessage) cout << "The list is already empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next; 
            delete temp; // Use delete instead of free()
            temp = nextNode;                    
        }
        
        head = nullptr; 
        if (printMessage) cout << "The entire list has been destroyed and memory freed.\n";
    }
};

int main() {
    UnrolledLinkedList list; // Instantiate the object
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
                list.insertElement(value);
                break;
            case 2:
                cout << "Enter integer value to delete: ";
                cin >> value;
                list.deleteElement(value);
                break;
            case 3:
                list.displayList();
                break;
            case 4:
                cout << "Enter integer value to search: ";
                cin >> value;
                list.searchElement(value);
                break;
            case 5:
                list.destroyList();
                break;
            case 6:
                // Destructor will automatically handle memory cleanup on exit
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}

