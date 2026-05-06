#include <cstdint> // Required for uintptr_t (essential for pointer XOR)
#include <cstdlib> // Required for malloc and free
#include <iostream>

using namespace std;

// Defines the structure for the XOR Linked List Node
typedef struct XNode
{
    int data;
    struct XNode *npx; // XOR of next and prev pointer
} Node;

// Global pointer to the first node of the list
Node *head;

// --- Helper Function for XOR Operation ---
// Returns (Node*) ( (uintptr_t)a ^ (uintptr_t)b )
Node *XOR(Node *a, Node *b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

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

    // Logic:
    // New Node's npx = NULL ^ current_head
    newNode->npx = XOR(nullptr, head);

    // If the list was not empty, we must update the old head's npx
    if (head != nullptr)
    {
        // Old head's npx was: NULL ^ Next
        // We need it to be: NewNode ^ Next

        // 1. Decode the 'next' node of the current head
        Node *next = XOR(nullptr, head->npx);

        // 2. Update head's npx
        head->npx = XOR(newNode, next);
    }

    head = newNode;
    cout << data << " inserted at the beginning." << endl;
}

// 2. Inserts a new node at the end of the list
void insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (head == nullptr)
    {
        newNode->npx = XOR(nullptr, nullptr); // NULL ^ NULL
        head = newNode;
        cout << data << " inserted at the end." << endl;
        return;
    }

    // Traverse to the last node
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    while (curr != nullptr)
    {
        next = XOR(prev, curr->npx);
        if (next == nullptr)
            break; // We found the last node
        prev = curr;
        curr = next;
    }

    // 'curr' is now the last node.
    // curr->npx is currently: XOR(prev, NULL).
    // It needs to become: XOR(prev, newNode).
    curr->npx = XOR(prev, newNode);

    // newNode->npx = XOR(curr, NULL)
    newNode->npx = XOR(curr, nullptr);

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

    // Traverse to find the node BEFORE the insertion point (pos-1)
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;
    int i = 1;

    while (curr != nullptr && i < pos - 1)
    {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
        i++;
    }

    if (curr == nullptr)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // We are inserting AFTER 'curr'.
    // Let 'next' be the node currently after 'curr'.
    next = XOR(prev, curr->npx);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Linkage Logic:
    // 1. Setup newNode: npx = curr ^ next
    newNode->npx = XOR(curr, next);

    // 2. Update curr: npx was (prev ^ next), now becomes (prev ^ newNode)
    curr->npx = XOR(prev, newNode);

    // 3. Update next (if it exists): npx was (curr ^ nextNext), now becomes (newNode ^ nextNext)
    if (next != nullptr)
    {
        Node *nextNext = XOR(curr, next->npx);
        next->npx = XOR(newNode, nextNext);
    }

    cout << data << " inserted at position " << pos << "." << endl;
}

// 4. Inserts a new node after a node with a specific value
void insertAfterElement(int data, int element)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    // Search for element
    while (curr != nullptr && curr->data != element)
    {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    if (curr == nullptr)
    {
        cout << "Element " << element << " not found in the list." << endl;
        return;
    }

    // Element found at 'curr'. Insert 'newNode' between 'curr' and 'next'.
    next = XOR(prev, curr->npx); // Decode the node after curr

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Update pointers using XOR logic
    newNode->npx = XOR(curr, next);
    curr->npx = XOR(prev, newNode);

    if (next != nullptr)
    {
        Node *nextNext = XOR(curr, next->npx);
        next->npx = XOR(newNode, nextNext);
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
    // Decode the second node (which will become head)
    // Next = NULL ^ head->npx
    Node *next = XOR(nullptr, head->npx);

    if (next != nullptr)
    {
        // Update the new head's npx.
        // Currently next->npx is: XOR(head, nextNext)
        // We need it to be: XOR(NULL, nextNext)
        Node *nextNext = XOR(temp, next->npx);
        next->npx = XOR(nullptr, nextNext);
    }

    head = next;
    cout << "Deleted " << temp->data << " from the beginning." << endl;
    free(temp);
}

// 6. Deletes the node from the end
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    // Traverse to end
    while (true)
    {
        next = XOR(prev, curr->npx);
        if (next == nullptr)
            break; // curr is the last node
        prev = curr;
        curr = next;
    }

    // curr is the last node. prev is the second to last.
    if (prev != nullptr)
    {
        // prev->npx was: XOR(prevPrev, curr)
        // Needs to be: XOR(prevPrev, NULL)

        // Decode prevPrev
        Node *prevPrev = XOR(prev->npx, curr);
        prev->npx = XOR(prevPrev, nullptr);
    }
    else
    {
        // List had only one node
        head = nullptr;
    }

    cout << "Deleted " << curr->data << " from the end." << endl;
    free(curr);
}

// 7. Deletes a node from a specific position
void deleteFromPosition(int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (pos == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;
    Node *next;
    int i = 1;

    // Traverse to the node at 'pos'
    while (curr != nullptr && i < pos)
    {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
        i++;
    }

    if (curr == nullptr)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // We are deleting 'curr'.
    // Logic: Connect 'prev' directly to 'next'.

    next = XOR(prev, curr->npx); // Decode node after curr

    // 1. Update prev
    // prev->npx was (prevPrev ^ curr). Needs to be (prevPrev ^ next).
    Node *prevPrev = XOR(prev->npx, curr);
    prev->npx = XOR(prevPrev, next);

    // 2. Update next (if exists)
    // next->npx was (curr ^ nextNext). Needs to be (prev ^ nextNext).
    if (next != nullptr)
    {
        Node *nextNext = XOR(curr, next->npx);
        next->npx = XOR(prev, nextNext);
    }

    cout << "Deleted " << curr->data << " from position " << pos << "." << endl;
    free(curr);
}

// ---  Utility Operations ---



// 8. Traverses and prints the list from beginning to end
void traverseInOrder()
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    cout << "List (Forward): ";
    while (curr != nullptr)
    {
        cout << curr->data << " <-> ";

        // Calculate next address using XOR formula
        next = XOR(prev, curr->npx);

        // Shift pointers forward
        prev = curr;
        curr = next;
    }
    cout << "NULL" << endl;
}

// 9. Deletes all nodes and frees the memory
void destroyList()
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    while (curr != nullptr)
    {
        next = XOR(prev, curr->npx);

        // NOTE: We must calculate 'next' BEFORE freeing 'curr'
        // because we need curr->npx to do the calculation.

        free(curr);

        // Standard advancement
        prev = curr; // Note: prev now holds a pointer to freed memory.
                     // This is okay ONLY because we won't dereference 'prev'.
                     // We only use the *value* of the address 'prev' for the XOR calculation in the next iteration.
        curr = next;
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
        cout << "\n--- Memory Efficient XOR Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position" << endl;
        cout << "4. Insert after an element" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete from a position" << endl;
        cout << "8. Traverse the list in order" << endl;
        cout << "9. Destroy the list" << endl;
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
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}