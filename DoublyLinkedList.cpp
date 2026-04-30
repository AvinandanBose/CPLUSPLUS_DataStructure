#include <cstdlib> // Required for malloc and free
#include <iostream>

using namespace std;

// Defines the structure for each node in the list
typedef struct DLL
{
    int data;
    DLL *next;
    DLL *prev;
}Node;

// Global pointer to the first node of the list
Node *head;

// Initializes the list as empty
void createEmptyList()
{
    head = nullptr;
}


// --- Insertion Operations ---

// 1. Inserts a new node at the beginning of the list
void insertAtBeginning(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr)
    {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }

    newNode->data = data;

    if (head == nullptr)
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        cout << data << " inserted at the beginning." << endl;
    }

    else
    {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << data << " inserted at the beginning." << endl;
    }
    
}

//We can write the same logic as:

// void insertAtBeginning(int data)
// {
//     Node *newNode = (Node *)malloc(sizeof(Node));
// if (newNode == nullptr)
// {
//     cout << "Error: Memory allocation failed." << endl;
//     return;
// }
//     newNode->data = data;
//     newNode->prev = nullptr;
//     newNode->next = head;
//     if (head != nullptr)
//     {
//         head->prev = newNode;
//     }
//     head = newNode;
//     cout << data << " inserted at the beginning." << endl;
// }

// 2. Inserts a new node at the end of the list
void insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    { // If list is empty, new node becomes the head
        newNode->prev = nullptr;
        head = newNode;
        cout << data << " inserted at the end." << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode;
    newNode->prev = temp;
    cout << data << " inserted at the end." << endl;
}

// 3. Inserts a new node at a specific position
void insertAtPosition(int data, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1)
    {
        insertAtBeginning(data);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
    cout << data << " inserted at position " << pos << "." << endl;
}

// 4. Inserts a new node after a node with a specific value
void insertAfterElement(int data, int element)
{
    Node *temp = head;
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
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != nullptr)
    {
        newNode->next->prev = newNode;
    }
    cout << data << " inserted after " << element << "." << endl;
}

// --- Deletion Operations ---

// 5. Deletes the node from the beginning
void deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    temp->next = nullptr;
    free(temp);
    temp = nullptr;
}

// 6. Deletes the node from the end
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node *temp = head;
    if (temp->next == nullptr)
    { // Only one node in the list
        head = nullptr;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node
        }
        temp->prev->next = nullptr;
        temp->prev = nullptr;
    }
    cout << "Deleted " << temp->data << " from the end." << endl;
    free(temp);
    temp = nullptr;
}

// 7. Deletes a node from a specific position
void deleteFromPosition(int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (pos < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
        temp->next = nullptr;
    }

    temp->prev = nullptr;

    cout << "Deleted " << temp->data << " from position " << pos << "." << endl;
    free(temp);
    temp = nullptr;
}

// --- Search and Utility Operations ---

// 8 & 9. Search for an element (works for both sorted and unsorted)
void searchForElement(int data)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    int pos = 1;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            cout << "Element " << data << " found at position " << pos << "." << endl;
            return;
        }
        // For a sorted list, we could optimize by stopping if temp->data > data
        temp = temp->next;
        pos++;
    }
    cout << "Element " << data << " not found in the list." << endl;
}

// 10. Returns the number of nodes in the list
int length()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return 0;
    }
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 11. Traverses and prints the list from beginning to end
void traverseInOrder()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    cout << "List (Forward): NULL <- ";
    while (temp !=nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Bonus: Traverses and prints the list from end to beginning
void traverseInReverse()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    { // Go to the last node
        temp = temp->next;
    }

    cout << "List (Reverse): NULL <- ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

// 12. Deletes all nodes and frees the memory
void destroyList()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *current = head;
    Node *nextNode;
    while (current != nullptr)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = nullptr;
    cout << "List destroyed." << endl;
}

// --- Main Driver Program ---

int main()
{
    createEmptyList();
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position" << endl;
        cout << "4. Insert after an element" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete from a position" << endl;
        cout << "8. Search for an element" << endl; // Simplified to one search
        cout << "9. Length of the list" << endl;
        cout << "10. Traverse the list in order" << endl;
        cout << "11. Traverse the list in reverse" << endl;
        cout << "12. Destroy the list" << endl;
        cout << "13. Exit" << endl;
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
            cout << "Enter element to search: ";
            cin >> data;
            searchForElement(data);
            break;
        case 9:
            cout << "Length of the list is: " << length() << endl;
            break;
        case 10:
            traverseInOrder();
            break;
        case 11:
            traverseInReverse();
            break;
        case 12:
            destroyList();
            break;
        case 13:
            cout << "Exiting program. Goodbye!" << endl;
            destroyList(); // Clean up memory before exiting
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}