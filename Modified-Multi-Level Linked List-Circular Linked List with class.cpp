#include <iostream>

using namespace std;

// 1. Define the Circular Node Class
class Node
{
public:
    int data;
    Node *next;  // Points to the right (Same Level, wraps to start)
    Node *child; // Points down (Sub Level, acts as head of a new circular list)

    // Constructor with Initializer List
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

// 2. Define the Multilevel Circular Linked List Class
class MultilevelCircularLinkedList
{
private:
    Node *head; // Encapsulated Head Pointer

    // --- Helper Declarations ---
    Node *searchNode(Node *startLevelNode, int target);
    void destroyLevel(Node *startLevelNode);
    void printList(Node *startLevelNode, int level = 0);

public:
    // Constructor & Destructor
    MultilevelCircularLinkedList();
    ~MultilevelCircularLinkedList();

    // --- Public Methods ---
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int pos);
    void insertAfterElement(int target, int data, int type);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int pos);
    void destroyList();
    void displayList();
};

// ==========================================
// PRIVATE HELPER METHOD DEFINITIONS
// ==========================================

// --- Helper: Search across all levels (Circularly safe) ---
Node *MultilevelCircularLinkedList::searchNode(Node *startLevelNode, int target)
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

// --- Helper: Destroy List (Circularly safe) ---
void MultilevelCircularLinkedList::destroyLevel(Node *startLevelNode)
{
    if (startLevelNode == nullptr)
        return;

    // Break the circle to make it a linear list temporarily
    // This avoids undefined behavior/infinite loops during deletion
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
        delete current;
        current = nextNode;
    }
}

// --- Helper: Recursive Print to visualize levels ---
void MultilevelCircularLinkedList::printList(Node *startLevelNode, int level)
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

// ==========================================
// PUBLIC METHOD DEFINITIONS
// ==========================================

// Constructor
MultilevelCircularLinkedList::MultilevelCircularLinkedList()
{
    head = nullptr;
}

// Destructor
MultilevelCircularLinkedList::~MultilevelCircularLinkedList()
{
    if (head != nullptr)
    {
        destroyList();
    }
}

// --- 1. Insert at Beginning (Main Level) ---
void MultilevelCircularLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);

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
void MultilevelCircularLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);

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
void MultilevelCircularLinkedList::insertAtPosition(int data, int pos)
{
    if (pos == 1)
    {
        insertAtBeginning(data);
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

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at position " << pos << endl;
}

// --- 4. Insert After Element (The Multilevel Magic) ---
void MultilevelCircularLinkedList::insertAfterElement(int target, int data, int type)
{
    if (head == nullptr)
    {
        cout << "List is empty. Please insert an element first." << endl;
        return;
    }

    Node *temp = searchNode(head, target);

    if (temp == nullptr)
    {
        cout << "Element " << target << " not found anywhere in the list." << endl;
        return;
    }

    Node *newNode = new Node(data);

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
        delete newNode;
    }
}

// --- 5. Delete at Beginning (Main Level) ---
void MultilevelCircularLinkedList::deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == head) // Only one node in main list
    {
        destroyLevel(head->child);
        delete head;
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

        delete temp;
    }
    cout << "Deleted from beginning." << endl;
}

// --- 6. Delete at End (Main Level) ---
void MultilevelCircularLinkedList::deleteAtEnd()
{
    if (head == nullptr)
        return;

    if (head->next == head) // Only one node in main list
    {
        destroyLevel(head->child);
        delete head;
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

    delete toDelete;
    cout << "Deleted from end." << endl;
}

// --- 7. Delete at Position (Main Level) ---
void MultilevelCircularLinkedList::deleteAtPosition(int pos)
{
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

    delete toDelete;
    cout << "Deleted at position " << pos << endl;
}

// --- 8. Destroy Entire List ---
void MultilevelCircularLinkedList::destroyList()
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

// --- 9. Display List Wrapper ---
void MultilevelCircularLinkedList::displayList()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Current Circular List Structure: " << endl;
    printList(head);
}

// ==========================================
// MAIN MENU
// ==========================================
int main()
{
    MultilevelCircularLinkedList list; // Instantiate the object
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

        // Input validation to prevent infinite loops on bad input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        }
        case 3:
        {
            int data, pos;
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position (1-based): ";
            cin >> pos;
            list.insertAtPosition(data, pos);
            break;
        }
        case 4:
        {
            int target, data, type;
            cout << "Enter the element to search for: ";
            cin >> target;
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Insert as (1) Next Node or (2) Child Node? ";
            cin >> type;
            list.insertAfterElement(target, data, type);
            break;
        }
        case 5:
            list.deleteAtBeginning();
            break;
        case 6:
            list.deleteAtEnd();
            break;
        case 7:
        {
            int pos;
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        }
        case 8:
            list.destroyList();
            break;
        case 9:
            list.displayList();
            break;
        case 10:
            cout << "Exiting program." << endl;
            // The list destructor ~MultilevelCircularLinkedList() cleans up memory.
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}