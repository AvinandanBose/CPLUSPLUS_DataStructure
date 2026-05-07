#include <cstdlib>
#include <iostream>

using namespace std;

class HeaderLinkedList
{
private:
    // Node Structure
    struct Node
    {
        int data;
        Node *next;
    };

    // Header Pointer
    Node *head;

public:
    // Constructor
    HeaderLinkedList()
    {
        head = (Node *)malloc(sizeof(Node));

        if (head == nullptr)
        {
            cout << "Memory Allocation Failed." << endl;
            exit(EXIT_FAILURE);
        }

        head->data = 0; // Internal Counter
        head->next = nullptr;

        cout << "Header Linked List Created Successfully." << endl;
    }

    // Destructor
    ~HeaderLinkedList()
    {
        destroyList();

        free(head);
        head = nullptr;

        cout << "Header Node Deleted Successfully." << endl;
    }

    // Function Declarations
    void insertAtBeginning(int);
    void insertAtEnd(int);
    void insertAtPosition(int , int);
    void insertAfterElement(int , int);

    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int);

    void traverse();
    void displayCount();
    void destroyList();
};

// --------------------------------------------------
// INSERTION OPERATIONS
// --------------------------------------------------

// Insert at Beginning
void HeaderLinkedList::insertAtBeginning(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        cout << "Memory Allocation Failed." << endl;
        return;
    }

    newNode->data = data;

    newNode->next = head->next;
    head->next = newNode;

    head->data++;

    cout << data << " inserted at beginning." << endl;
}

// Insert at End
void HeaderLinkedList::insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        cout << "Memory Allocation Failed." << endl;
        return;
    }

    newNode->data = data;
    newNode->next = nullptr;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    head->data++;

    cout << data << " inserted at end." << endl;
}

// Insert at Position
void HeaderLinkedList::insertAtPosition(int data, int pos)
{
    if (pos < 1 || pos > head->data + 1)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        cout << "Memory Allocation Failed." << endl;
        return;
    }

    newNode->data = data;

    Node *temp = head;

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    head->data++;

    cout << data << " inserted at position " << pos << "." << endl;
}

// Insert After Element
void HeaderLinkedList::insertAfterElement(int data, int element)
{
    Node *temp = head->next;

    while (temp != nullptr && temp->data != element)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Element Not Found." << endl;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == nullptr)
    {
        cout << "Memory Allocation Failed." << endl;
        return;
    }

    newNode->data = data;

    newNode->next = temp->next;
    temp->next = newNode;

    head->data++;

    cout << data << " inserted after " << element << "." << endl;
}

// --------------------------------------------------
// DELETION OPERATIONS
// --------------------------------------------------

// Delete from Beginning
void HeaderLinkedList::deleteFromBeginning()
{
    if (head->next == nullptr)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *temp = head->next;

    head->next = temp->next;

    cout << "Deleted " << temp->data << " from beginning." << endl;

    free(temp);
    temp = nullptr;

    head->data--;
}

// Delete from End
void HeaderLinkedList::deleteFromEnd()
{
    if (head->next == nullptr)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *nodeToDelete = temp->next;

    temp->next = nullptr;

    cout << "Deleted " << nodeToDelete->data << " from end." << endl;

    free(nodeToDelete);
    nodeToDelete = nullptr;

    head->data--;
}

// Delete from Position
void HeaderLinkedList::deleteFromPosition(int pos)
{
    if (head->next == nullptr)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (pos < 1 || pos > head->data)
    {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node *prev = head;

    for (int i = 1; i < pos; i++)
    {
        prev = prev->next;
    }

    Node *nodeToDelete = prev->next;

    prev->next = nodeToDelete->next;

    cout << "Deleted " << nodeToDelete->data
         << " from position " << pos << "." << endl;

    free(nodeToDelete);
    nodeToDelete = nullptr;

    head->data--;
}

// --------------------------------------------------
// UTILITY OPERATIONS
// --------------------------------------------------

// Traverse List
void HeaderLinkedList::traverse()
{
    if (head->next == nullptr)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *temp = head->next;

    cout << "Header -> ";

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Display Total Nodes
void HeaderLinkedList::displayCount()
{
    cout << "Total Nodes = " << head->data << endl;
}

// Destroy List
void HeaderLinkedList::destroyList()
{
    Node *current = head->next;
    Node *nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;

        free(current);

        current = nextNode;
    }

    head->next = nullptr;
    head->data = 0;

    cout << "List Cleared." << endl;
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------

int main()
{
    HeaderLinkedList list;

    int choice;
    int data;
    int pos;
    int element;

    while (true)
    {
        cout << "\n--- Header Linked List Menu ---" << endl;

        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Insert After Element" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete from Position" << endl;
        cout << "8. Traverse List" << endl;
        cout << "9. Display Count" << endl;
        cout << "10. Clear List" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter Data: ";
            cin >> data;

            list.insertAtBeginning(data);

            break;

        case 2:

            cout << "Enter Data: ";
            cin >> data;

            list.insertAtEnd(data);

            break;

        case 3:

            cout << "Enter Data: ";
            cin >> data;

            cout << "Enter Position: ";
            cin >> pos;

            list.insertAtPosition(data, pos);

            break;

        case 4:

            cout << "Enter Data: ";
            cin >> data;

            cout << "Enter Element: ";
            cin >> element;

            list.insertAfterElement(data, element);

            break;

        case 5:

            list.deleteFromBeginning();

            break;

        case 6:

            list.deleteFromEnd();

            break;

        case 7:

            cout << "Enter Position: ";
            cin >> pos;

            list.deleteFromPosition(pos);

            break;

        case 8:

            list.traverse();

            break;

        case 9:

            list.displayCount();

            break;

        case 10:

            list.destroyList();
            cout << "List Destroyed." << endl;

            break;

        case 11:
            list.~HeaderLinkedList();
            cout << "Exiting Program..." << endl;

            return 0;

        default:

            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}