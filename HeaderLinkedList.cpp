#include <cstdlib> // Required for malloc and free
#include <iostream>

using namespace std;

// Defines the structure for each node in the list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Global pointer to the Header Node
Node *head;

// Initializes the list with a Header Node
void createHeaderList()
{
    // Allocate memory for the Header Node
    head = (Node *)malloc(sizeof(Node));
    
    if (head == nullptr) {
        cout << "Error: Memory allocation for Header failed." << endl;
        exit(1); //or we can use macro : EXIT_FAILURE 
    }

    // internal counter for position validation (metadata)
    head->data = 0; 
    head->next = nullptr;
}

// --- Insertion Operations ---

// 1. Inserts a new node at the beginning (after the header)
void insertAtBeginning(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr)
    {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }

    newNode->data = data;
    
    // Link new node to the current first node
    newNode->next = head->next;
    
    // Link header to the new node
    head->next = newNode;

    // Increment internal count
    head->data++; 

    cout << data << " inserted at the beginning." << endl;
}

// 2. Inserts a new node at the end of the list
void insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }

    newNode->data = data;
    newNode->next = nullptr;

    // Start traversal from head
    Node *temp = head;
    
    // Move to the last node
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Link the new node
    temp->next = newNode;
    
    // Increment internal count
    head->data++;

    cout << data << " inserted at the end." << endl;
}

// 3. Inserts a new node at a specific position
void insertAtPosition(int data, int pos)
{
    // We use head->data (internal count) to validate the position
    if (pos < 1 || pos > head->data + 1)
    {
        cout << "Invalid position! Current list size: " << head->data << endl;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }
    newNode->data = data;

    // Start from head
    Node *temp = head;

    // Traverse to the node immediately BEFORE the target position
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    // Insert the node
    newNode->next = temp->next;
    temp->next = newNode;

    // Increment internal count
    head->data++;

    cout << data << " inserted at position " << pos << "." << endl;
}

// 4. Inserts a new node after a node with a specific value
void insertAfterElement(int data, int element)
{
    Node *temp = head->next; // Start checking actual data nodes
    
    while (temp != nullptr && temp->data != element)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Element " << element << " not found in the list." << endl;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }
    newNode->data = data;

    // Link new node
    newNode->next = temp->next;
    temp->next = newNode;

    // Increment internal count
    head->data++;

    cout << data << " inserted after " << element << "." << endl;
}

// --- Deletion Operations ---

// 5. Deletes the node from the beginning
void deleteFromBeginning()
{
    if (head->next == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = head->next; // The first actual node
    
    // Update header to point to the second node
    head->next = temp->next;
    
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    
    free(temp);
    temp = nullptr;

    // Decrement internal count
    head->data--;
}

// 6. Deletes the node from the end
void deleteFromEnd()
{
    if (head->next == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = head;
    
    // Traverse to the node BEFORE the last node
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // temp->next is the node to be deleted
    Node *nodeToDelete = temp->next;
    
    // Unlink
    temp->next = nullptr;

    cout << "Deleted " << nodeToDelete->data << " from the end." << endl;
    
    free(nodeToDelete);
    nodeToDelete = nullptr;

    // Decrement internal count
    head->data--;
}

// 7. Deletes a node from a specific position
void deleteFromPosition(int pos)
{
    if (head->next == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    
    if (pos < 1 || pos > head->data)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *prev = head;
    
    // Traverse to the node BEFORE the target position
    for (int i = 1; i < pos; i++)
    {
        prev = prev->next;
    }

    Node *nodeToDelete = prev->next;
    
    // Unlink the node
    prev->next = nodeToDelete->next;

    cout << "Deleted " << nodeToDelete->data << " from position " << pos << "." << endl;
    
    free(nodeToDelete);
    nodeToDelete = nullptr;

    // Decrement internal count
    head->data--;
}

// --- Utility Operations ---

// 8. Traverses and prints the list from beginning to end
void traverseInOrder()
{
    if (head->next == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head->next; // Skip header
    cout << "Header -> ";
    
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 9. Deletes all nodes and frees the memory
void destroyList()
{
    Node *current = head->next; // Start after header
    Node *nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    // Reset header
    head->next = nullptr;
    head->data = 0;
    
    cout << "List cleared (Header node preserved)." << endl;
}

// Clean up the actual header node before exiting program
void freeHeader() {
    if (head != nullptr) {
        free(head);
        head = nullptr;
    }
}

// --- Main Driver Program ---

int main()
{
    createHeaderList();
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Header Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position" << endl;
        cout << "4. Insert after an element" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete from a position" << endl;
        cout << "8. Traverse the list in order" << endl;
        cout << "9. Clear the list" << endl;
        cout << "10. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            insertAtEnd(data);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> pos;
            insertAtPosition(data, pos);
            break;
        case 4:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter the element to insert after: ";
            cin >> element;
            insertAfterElement(data, element);
            break;
        case 5:
            deleteFromBeginning();
            break;
        case 6:
            deleteFromEnd();
            break;
        case 7:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteFromPosition(pos);
            break;
        case 8:
            traverseInOrder();
            break;
        case 9:
            destroyList();
            break;
        case 10:
            cout << "Exiting program. Goodbye!" << endl;
            destroyList();
            freeHeader(); // Free the actual header node
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}