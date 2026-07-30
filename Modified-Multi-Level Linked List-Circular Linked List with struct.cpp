#include <cstdlib> // Required for malloc, free, exit
#include <iostream>

using namespace std;

// 1. Define the Multilevel Node
struct Node
{
    int data;
    struct Node *next;  // Points to the right (Same Level, wraps to start)
    struct Node *child; // Points down (Sub Level, acts as head of a new circular list)
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

// --- Helper: Search across all levels (Circularly safe) ---
Node *searchNode(Node *startLevelNode, int target)
{
    if (startLevelNode == nullptr)
        return nullptr;

    Node *current = startLevelNode;
    do
    {
        if (current->data == target)
            return current;

        // Check child level
        if (current->child != nullptr)
        {
            Node *foundInChild = searchNode(current->child, target);
            if (foundInChild != nullptr)
            {
                return foundInChild;
            }
        }

        current = current->next;
    } while (current != startLevelNode); // Stop when we wrap around

    return nullptr;
}

// --- 8. Destroy List (Circularly safe) ---
void destroyLevel(Node *startLevelNode)
{
    if (startLevelNode == nullptr)
        return;

    // Break the circle to make it a linear list temporarily to avoid undefined behavior during deletion
    Node *tail = startLevelNode;
    while (tail->next != startLevelNode)
    {
        tail = tail->next;
    }
    tail->next = nullptr;

    Node *current = startLevelNode;
    while (current != nullptr)
    {
        Node *nextNode = current->next;

        // Destroy Child Circular List first
        if (current->child != nullptr)
        {
            destroyLevel(current->child);
        }

        cout << "Freeing node: " << current->data << endl;
        free(current);
        current = nextNode;
    }
}

void destroyList()
{
    if (head == nullptr)
    {
        cout << "List is already empty." << endl;
        return;
    }
    destroyLevel(head);
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

    if (head == nullptr)
    {
        head = newNode;
        head->next = head; // Points to itself
    }
    else
    {
        Node *temp = head;
        // Find the last node to update its next pointer
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
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
        head->next = head; // Points to itself
    }
    else
    {
        Node *temp = head;
        // Find the last node
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
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

    if (pos == 1)
    {
        // Equivalent to insert at beginning, but we write it out to avoid cin conflicts
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at position 1." << endl;
        return;
    }

    if (head == nullptr)
    {
        cout << "List is empty, invalid position." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head) // We circled back around before finding the position
        {
            cout << "Position out of range." << endl;
            return;
        }
    }

    Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at position " << pos << endl;
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
        // Insert as Next (Same Circular Level)
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << data << " as NEXT of " << target << endl;
    }
    else if (type == 2)
    {
        // Insert as Child (Sub Level)
        if (temp->child == nullptr)
        {
            temp->child = newNode;
            newNode->next = newNode; // Starts a new circular list
        }
        else
        {
            // Insert at the beginning of the child circular list
            Node *childTail = temp->child;
            while (childTail->next != temp->child)
            {
                childTail = childTail->next;
            }
            newNode->next = temp->child;
            temp->child = newNode;
            childTail->next = newNode;
        }
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

    if (head->next == head) // Only one node in main list
    {
        destroyLevel(head->child);
        free(head);
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;

        // Clean up deleted node's children
        if (temp->child != nullptr)
            destroyLevel(temp->child);
        free(temp);
    }
    cout << "Deleted from beginning." << endl;
}

// --- 6. Delete at End (Main Level) ---
void deleteAtEnd()
{
    if (head == nullptr)
        return;

    if (head->next == head) // Only one node in main list
    {
        destroyLevel(head->child);
        free(head);
        head = nullptr;
        cout << "Deleted from end." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    Node *toDelete = temp->next;
    temp->next = head; // Bypass the last node

    if (toDelete->child != nullptr)
        destroyLevel(toDelete->child);
    free(toDelete);
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

    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp->next == head) // Out of bounds
        {
            cout << "Position out of range." << endl;
            return;
        }
    }

    Node *toDelete = temp->next;
    if (toDelete == head) // Safety check for wrap-around
    {
        cout << "Position out of range." << endl;
        return;
    }

    temp->next = toDelete->next;

    if (toDelete->child != nullptr)
        destroyLevel(toDelete->child);
    free(toDelete);
    cout << "Deleted at position " << pos << endl;
}

// --- Helper: Recursive Print to visualize levels ---
void printList(Node *startLevelNode, int level = 0)
{
    if (startLevelNode == nullptr)
        return;

    Node *current = startLevelNode;
    do
    {
        for (int i = 0; i < level; i++)
            cout << "    ";

        // Shows current data and what its 'next' pointer aims at to prove it's circular
        cout << "|-- " << current->data << " (next -> " << current->next->data << ")" << endl;

        if (current->child != nullptr)
        {
            printList(current->child, level + 1);
        }

        current = current->next;
    } while (current != startLevelNode);
}

// --- Main Menu ---
int main()
{
    int choice;
    while (true)
    {
        cout << "\n--- Multilevel Circular List Menu ---" << endl;
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
            cout << "Current Circular List Structure: " << endl;
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