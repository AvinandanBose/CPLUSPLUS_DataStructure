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

// --- Helper: Recursive Search across all levels ---
Node *searchNode(Node *current, int target)
{
    if (current == nullptr)
        return nullptr;

    if (current->data == target)
        return current;

    Node *foundInChild = searchNode(current->child, target);
    if (foundInChild != nullptr)
    {
        return foundInChild;
    }      
    return searchNode(current->next, target);
}

// --- 8. Destroy List (Moved up so delete functions can use it) ---
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
    if (head == nullptr)
    {
        cout << "List is already empty." << endl;
        return;
    }
    destroyNodeRecursively(head);
    head = nullptr;
    cout << "Entire list destroyed." << endl;
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
    if (head == nullptr)
    {
        cout << "List is empty. Please insert an element first." << endl;
        return;
    }

    int target, data, type;
    cout << "Enter the element to search for: ";
    cin >> target;

    Node *temp = searchNode(head, target);

    if (temp == nullptr)
    {
        cout << "Element " << target << " not found anywhere in the list." << endl;
        return;
    }

    cout << "Enter data to insert: ";
    cin >> data;
    Node *newNode = createNode(data);

    cout << "Insert as (1) Next Node or (2) Child Node? ";
    cin >> type;

    if (type == 1)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << data << " as NEXT of " << target << endl;
    }
    else if (type == 2)
    {
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

    // Recursively free the entire child branch attached to this node
    destroyNodeRecursively(temp->child);

    free(temp);
    cout << "Deleted from beginning." << endl;
}

// --- 6. Delete at End (Main Level) ---
void deleteAtEnd()
{
    if (head == nullptr)
        return;

    // If there is only one element in the main list
    if (head->next == nullptr)
    {
        destroyNodeRecursively(head->child); // Free children first
        free(head);
        head = nullptr;
        cout << "Deleted from end." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // temp->next is the last node. Free its children first.
    destroyNodeRecursively(temp->next->child);

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
        destroyNodeRecursively(temp->child); // Free children first
        free(temp);
        cout << "Deleted at position " << pos << endl;
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

    // Free children attached to the node being deleted
    destroyNodeRecursively(toDelete->child);

    free(toDelete);
    cout << "Deleted at position " << pos << endl;
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