#include <iostream>

using namespace std;

// 1. Define the Doubly Linked Node Class
class Node
{
public:
    int data;
    Node *next;  // Points to the right (Same Level)
    Node *prev;  // Points to the left (Same Level)
    Node *child; // Points down (Sub Level)

    // Constructor to automatically initialize the node
    Node(int val) : data(val), next(nullptr), prev(nullptr), child(nullptr) {}

    /**
    We can also use an alternative constructor like this:
   Node(int val)
   {
       data = val;
       next = nullptr;
       prev = nullptr;
       child = nullptr;
   }
    *
    */
};

// 2. Define the Multilevel Doubly Linked List Class
class MultilevelDoublyLinkedList
{
private:
    Node *head; // Encapsulated Head Pointer

    // --- Helper Declarations ---
    Node *searchNode(Node *, int );
    void destroyNodeRecursively(Node *);
    void printList(Node *, int ); // Default argument goes here!
    
public:
    // Constructor
    MultilevelDoublyLinkedList();

    // Destructor ensures no memory leaks when object is destroyed
    ~MultilevelDoublyLinkedList();

    // --- 1. Insert at Beginning (Main Level) ---
    void insertAtBeginning(int);

    // --- 2. Insert at End (Main Level) ---
    void insertAtEnd(int);

    // --- 3. Insert at Position (Main Level) ---
    void insertAtPosition(int, int);

    // --- 4. Insert After Element (The Multilevel Magic) ---
    void insertAfterElement(int, int, int);

    // --- 5. Delete at Beginning (Main Level) ---
    void deleteAtBeginning();

    // --- 6. Delete at End (Main Level) ---
    void deleteAtEnd();

    // --- 7. Delete at Position (Main Level) ---
    void deleteAtPosition(int);

    // --- 8. Destroy Entire List ---
    void destroyList();

    // --- 9. Display List Wrapper ---
    void displayList();
};
// ==========================================
// PRIVATE HELPER METHOD DEFINITIONS
// ==========================================


// --- Helper: Recursive Search across all levels ---
Node *MultilevelDoublyLinkedList::searchNode(Node *current, int target)
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

// --- Helper: Destroy List Recursively ---
void MultilevelDoublyLinkedList::destroyNodeRecursively(Node *node)
{
    if (node == nullptr)
        return;

    // 1. Destroy Child List first
    destroyNodeRecursively(node->child);

    // 2. Destroy Next List
    destroyNodeRecursively(node->next);

    // 3. Free current using C++ 'delete'
    cout << "Freeing node: " << node->data << endl;
    delete node;
}


// --- Helper: Recursive Print to visualize levels ---
void MultilevelDoublyLinkedList::printList(Node *node, int level = 0)
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
// ==========================================
// PRIVATE HELPER METHOD DEFINITIONS---END
// ==========================================

// ==========================================
// Public METHOD DEFINITIONS---Start
// ==========================================
// Constructor
MultilevelDoublyLinkedList::MultilevelDoublyLinkedList()
{
    head = nullptr;
}

// Destructor
MultilevelDoublyLinkedList::~MultilevelDoublyLinkedList()
{
    if (head != nullptr)
    {
        destroyList();
    }
}


// --- 1. Insert at Beginning (Main Level) ---
void MultilevelDoublyLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
    cout << "Inserted " << data << " at beginning." << endl;
}

// --- 2. Insert at End (Main Level) ---
void MultilevelDoublyLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);

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
        newNode->prev = temp; // Connect doubly link
    }
    cout << "Inserted " << data << " at end." << endl;
}

// --- 3. Insert at Position (Main Level) ---
void MultilevelDoublyLinkedList::insertAtPosition(int data, int pos)
{
    if (pos == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << "Inserted at position 1." << endl;
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
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted at position " << pos << endl;
    }
}

// --- 4. Insert After Element (The Multilevel Magic) ---
void MultilevelDoublyLinkedList::insertAfterElement(int target, int data, int type)
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
        // Insert as Next (Same Level)
        newNode->next = temp->next;
        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        cout << "Inserted " << data << " as NEXT of " << target << endl;
    }
    else if (type == 2)
    {
        // Insert as Child (Sub Level) - becomes the new head of that child list
        newNode->next = temp->child;
        if (temp->child != nullptr)
        {
            temp->child->prev = newNode;
        }
        temp->child = newNode;
        newNode->prev = nullptr; // It is the first element of this child level

        cout << "Inserted " << data << " as CHILD of " << target << endl;
    }
    else
    {
        cout << "Invalid option." << endl;
        delete newNode;
    }
}

// --- 5. Delete at Beginning (Main Level) ---
void MultilevelDoublyLinkedList::deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }

    // Recursively free the entire child branch attached to this node
    destroyNodeRecursively(temp->child);

    delete temp;
    cout << "Deleted from beginning." << endl;
}

// --- 6. Delete at End (Main Level) ---
void MultilevelDoublyLinkedList::deleteAtEnd()
{
    if (head == nullptr)
        return;

    // If there is only one element in the main list
    if (head->next == nullptr)
    {
        destroyNodeRecursively(head->child); // Free children first
        delete head;
        head = nullptr;
        cout << "Deleted from end." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // temp is now the last node.
    temp->prev->next = nullptr;

    // Free children first.
    destroyNodeRecursively(temp->child);

    delete temp;
    cout << "Deleted from end." << endl;
}

// --- 7. Delete at Position (Main Level) ---
void MultilevelDoublyLinkedList::deleteAtPosition(int pos)
{
    if (head == nullptr)
        return;

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        destroyNodeRecursively(temp->child); // Free children first
        delete temp;
        cout << "Deleted at position " << pos << endl;
        return;
    }

    Node *temp = head;
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

    if (toDelete->next != nullptr)
    {
        toDelete->next->prev = temp;
    }

    // Free children attached to the node being deleted
    destroyNodeRecursively(toDelete->child);

    delete toDelete;
    cout << "Deleted at position " << pos << endl;
}

// --- 8. Destroy Entire List ---
void MultilevelDoublyLinkedList::destroyList()
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

// --- 9. Display List Wrapper ---
void MultilevelDoublyLinkedList::displayList()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }
    cout << "Current List Structure: " << endl;
    printList(head);
}

// ==========================================
// Public METHOD DEFINITIONS---END
// ==========================================

// --- Main Menu ---
int main()
{
    MultilevelDoublyLinkedList list; // Instantiate the list object
    int choice;

    while (true)
    {
        cout << "\n--- Multilevel Doubly List Menu ---" << endl;
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
            // The object destructor ~MultilevelDoublyLinkedList()
            // automatically triggers here to clean up memory.
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
