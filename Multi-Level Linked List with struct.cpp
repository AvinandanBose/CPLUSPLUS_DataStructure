#include <cstdlib> // Required for malloc, free, exit
#include <iostream>

using namespace std;

// 1. Define the Multilevel Node
struct Node
{
    int data;
    struct Node *next;  // Points to the right (Same Level)
    struct Node *child; // Points down (Sub Level)
};

Node *head = nullptr; // Global Head Pointer

// Helper: Create a new node with malloc
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr)
    {
        cout << "Memory allocation failed." << endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    newNode->child = nullptr;
    return newNode;
}

// --- 1. Insert at Beginning (Main Level) ---
void insertAtBeginning()
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << data << " at beginning." << endl;
}

// --- 2. Insert at End (Main Level) ---
void insertAtEnd()
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    Node *newNode = createNode(data);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << data << " at end." << endl;
}

// --- 3. Insert at Position (Main Level) ---
void insertAtPosition()
{
    int data, pos;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter position (1-based): ";
    cin >> pos;

    Node *newNode = createNode(data);

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        free(newNode);
        return;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted at position " << pos << endl;
    }
}

// --- 4. Insert After Element (The Multilevel Magic) ---
void insertAfterElement()
{
    int target, data, type;
    cout << "Enter the element to search for: ";
    cin >> target;

    // Simple search (Only searches main level for simplicity in this demo)
    Node *temp = head;
    while (temp != nullptr && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Element not found in main list." << endl;
        return;
    }

    cout << "Enter data to insert: ";
    cin >> data;
    Node *newNode = createNode(data);

    cout << "Insert as (1) Next Node or (2) Child Node? ";
    cin >> type;

    if (type == 1)
    {
        // Standard Linked List Insertion
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << data << " as NEXT of " << target << endl;
    }
    else if (type == 2)
    {
        // Multilevel Insertion
        // If a child already exists, we link the new node to the front of the child list
        newNode->next = temp->child;
        temp->child = newNode;
        cout << "Inserted " << data << " as CHILD of " << target << endl;
    }
    else
    {
        cout << "Invalid option." << endl;
        free(newNode);
    }
}

// --- 5. Delete at Beginning (Main Level) ---
void deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;

    // Note: In a full implementation, we should also free temp->child recursively
    free(temp);
    cout << "Deleted from beginning." << endl;
}

// --- 6. Delete at End (Main Level) ---
void deleteAtEnd()
{
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    cout << "Deleted from end." << endl;
}

// --- 7. Delete at Position (Main Level) ---
void deleteAtPosition()
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == nullptr)
        return;

    Node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    cout << "Deleted at position " << pos << endl;
}

// --- 8. Destroy List (Recursive for Multilevel) ---
void destroyNodeRecursively(Node *node)
{
    if (node == nullptr)
        return;

    // 1. Destroy Child List first
    destroyNodeRecursively(node->child);

    // 2. Destroy Next List
    destroyNodeRecursively(node->next);

    // 3. Free current
    cout << "Freeing node: " << node->data << endl;
    free(node);
}

void destroyList()
{
    destroyNodeRecursively(head);
    head = nullptr;
    cout << "Entire list destroyed." << endl;
}

// --- Helper: Recursive Print to visualize levels ---
void printList(Node *node, int level = 0)
{
    while (node != nullptr)
    {
        for (int i = 0; i < level; i++)
            cout << "    ";
        cout << "|-- " << node->data << endl;

        if (node->child != nullptr)
        {
            printList(node->child, level + 1);
        }
        node = node->next;
    }
}

// --- Main Menu ---
int main()
{
    int choice;
    while (true)
    {
        cout << "\n--- Multilevel List Menu ---" << endl;
        cout << "1. Insert at Beginning (Main)" << endl;
        cout << "2. Insert at End (Main)" << endl;
        cout << "3. Insert at Position (Main)" << endl;
        cout << "4. Insert After Element (Link or Child)" << endl;
        cout << "5. Delete at Beginning (Main)" << endl;
        cout << "6. Delete at End (Main)" << endl;
        cout << "7. Delete at Position (Main)" << endl;
        cout << "8. Destroy List" << endl;
        cout << "9. Display List" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            insertAfterElement();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtPosition();
            break;
        case 8:
            destroyList();
            break;
        case 9:
            cout << "Current List Structure: " << endl;
            printList(head);
            break;
        case 10:
            // list is not empty, delete it before exiting
            if (head != nullptr)
            {
                destroyList();
            }
            cout << "Exiting program." << endl;
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}



