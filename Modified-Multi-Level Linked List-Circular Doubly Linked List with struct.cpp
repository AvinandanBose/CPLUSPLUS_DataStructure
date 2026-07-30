#include <cstdlib> // Required for malloc, free, exit
#include <iostream>

using namespace std;

// 1. Define the Multilevel Doubly Circular Node
struct Node
{
    int data;
    struct Node *next;  // Points to the right (Same Level, Circularly)
    struct Node *prev;  // Points to the left (Same Level, Circularly)
    struct Node *child; // Points down (Sub Level, Acts as Head of new circular list)
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
    newNode->prev = nullptr;
    newNode->child = nullptr;
    return newNode;
}

// --- Helper: Recursive Search across all levels (Circularly Safe) ---
Node *searchNode(Node *startLevelNode, int target)
{
    if (startLevelNode == nullptr)
        return nullptr;

    Node *current = startLevelNode;
    do
    {
        if (current->data == target)
            return current;

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

// --- 8. Destroy List (Circularly Safe) ---
void destroyLevel(Node *startLevelNode)
{
    if (startLevelNode == nullptr)
        return;

    // Break the circle to avoid infinite loops during deletion
    Node *tail = startLevelNode->prev;
    tail->next = nullptr;

    Node *current = startLevelNode;
    while (current != nullptr)
    {
        Node *nextNode = current->next;

        // 1. Destroy Child List first
        if (current->child != nullptr)
        {
            destroyLevel(current->child);
        }

        // 2. Free current
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
        head->next = head;
        head->prev = head; // Points to itself in both directions
    }
    else
    {
        Node *tail = head->prev; // In circular doubly list, head->prev is the tail

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode; // Shift head to the newly inserted node
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
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;
        // Do not shift head, so it remains at the end
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
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted at position 1." << endl;
        return;
    }

    if (head == nullptr)
    {
        cout << "List is empty, position out of range." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head) // Circled back before finding position
        {
            cout << "Position out of range." << endl;
            return;
        }
    }

    Node *newNode = createNode(data);
    Node *nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;

    temp->next = newNode;
    nextNode->prev = newNode;

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
        // Insert as Next (Same Level, Circularly)
        Node *nextNode = temp->next;

        newNode->next = nextNode;
        newNode->prev = temp;

        temp->next = newNode;
        nextNode->prev = newNode;

        cout << "Inserted " << data << " as NEXT of " << target << endl;
    }
    else if (type == 2)
    {
        // Insert as Child (Sub Level) - becomes the end of that child list
        if (temp->child == nullptr)
        {
            temp->child = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *childHead = temp->child;
            Node *childTail = childHead->prev;

            newNode->next = childHead;
            newNode->prev = childTail;

            childTail->next = newNode;
            childHead->prev = newNode;
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

    if (head->next == head) // Only one element in the main list
    {
        if (head->child != nullptr)
            destroyLevel(head->child);
        free(head);
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        Node *tail = head->prev;

        head = head->next; // Shift head

        tail->next = head; // Update tail's next
        head->prev = tail; // Update new head's prev

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

    if (head->next == head) // Only one element in the main list
    {
        if (head->child != nullptr)
            destroyLevel(head->child);
        free(head);
        head = nullptr;
        cout << "Deleted from end." << endl;
        return;
    }

    Node *tail = head->prev;
    Node *newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    if (tail->child != nullptr)
        destroyLevel(tail->child);
    free(tail);

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
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            cout << "Position out of range." << endl;
            return;
        }
    }

    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    if (temp->child != nullptr)
        destroyLevel(temp->child);
    free(temp);

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

        cout << "|-- " << current->data << " [prev: " << current->prev->data << ", next: " << current->next->data << "]" << endl;

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
        cout << "\n--- Multilevel Circular Doubly List Menu ---" << endl;
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