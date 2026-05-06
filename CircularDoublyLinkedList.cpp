#include <cstdlib> // Required for malloc and free
#include <iostream>

using namespace std;

// Defines the structure for each node in the list
typedef struct DLL
{
    int data;
    DLL *next;
    DLL *prev;
} Node;

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
        // --- CDLL Change ---
        // List is empty, so the new node points to itself.
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        // --- CDLL Change ---
        // Find the last node (which is head->prev) and link it.
        Node *last = head->prev;

        newNode->next = head;     // New node points forward to old head
        newNode->prev = last;     // New node points back to last node
        head->prev = newNode;     // Old head's prev points to new node
        last->next = newNode;     // Last node's next points to new node
        head = newNode;           // Update the head pointer
    }
    cout << data << " inserted at the beginning." << endl;
}

// 2. Inserts a new node at the end of the list
void insertAtEnd(int data)
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
        // --- CDLL Change ---
        // If list is empty, same as insertAtBeginning
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        // --- CDLL Change ---
        // This is now O(1) instead of O(n). No traversal needed.
        Node *last = head->prev; // Get the last node directly

        newNode->next = head;     // New node points forward to head
        newNode->prev = last;     // New node points back to old last
        last->next = newNode;     // Old last's next points to new node
        head->prev = newNode;     // Head's prev points to the new last node
    }
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
    // --- CDLL Change ---
    // Handle empty list case if pos > 1
    if (head == nullptr)
    {
        cout << "Position out of bounds! List is empty." << endl;
        return;
    }

    Node *temp = head;
    // --- CDLL Change ---
    // Traverse, but check for wrapping around
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            // We've wrapped around the entire list
            cout << "Position out of bounds!" << endl;
            return;
        }
    }

    // 'temp' is now the node *before* the insertion point

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == nullptr)
    {
        cout << "Error: Memory allocation failed." << endl;
        return;
    }
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    // --- CDLL Change ---
    // The next node's prev must be updated. It's never null.
    temp->next->prev = newNode;
    temp->next = newNode;

    cout << data << " inserted at position " << pos << "." << endl;
}

// 4. Inserts a new node after a node with a specific value
void insertAfterElement(int data, int element)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;

    // --- CDLL Change ---
    // Use a do-while loop to traverse and check for wrapping
    do
    {
        if (temp->data == element)
        {
            // Found the element
            Node *newNode = (Node *)malloc(sizeof(Node));
            if (newNode == nullptr)
            {
                cout << "Error: Memory allocation failed." << endl;
                return;
            }
            newNode->data = data;

            newNode->next = temp->next;
            newNode->prev = temp;
            // --- CDLL Change ---
            // Update the next node's prev pointer
            temp->next->prev = newNode;
            temp->next = newNode;

            cout << data << " inserted after " << element << "." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    // If we complete the loop, the element was not found
    cout << "Element " << element << " not found in the list." << endl;
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
    cout << "Deleted " << temp->data << " from the beginning." << endl;

    // --- CDLL Change ---
    if (head->next == head)
    {
        // Case 1: Only one node in the list
        head = nullptr;
    }
    else
    {
        // Case 2: Multiple nodes
        Node *last = head->prev;
        head = head->next;      // Move head to the second node
        head->prev = last;      // New head's prev points to last
        last->next = head;      // Last's next points to new head
    }

    free(temp);
    temp = nullptr; // Good practice
}

// 6. Deletes the node from the end
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    // --- CDLL Change ---
    // This is now O(1) instead of O(n)
    Node *last = head->prev; // Get the last node
    cout << "Deleted " << last->data << " from the end." << endl;

    if (head->next == head)
    {
        // Case 1: Only one node
        head = nullptr;
    }
    else
    {
        // Case 2: Multiple nodes
        Node *newLast = last->prev; // Get the second-to-last node
        newLast->next = head;       // New last node points to head
        head->prev = newLast;       // Head's prev points to new last node
    }

    free(last);
    last = nullptr;
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
    // --- CDLL Change ---
    // Traverse to the node *at* the position, checking for wrap-around
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }
    }

    // 'temp' is now the node to be deleted

    // --- CDLL Change ---
    // Simpler link update, no null checks needed
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    cout << "Deleted " << temp->data << " from position " << pos << "." << endl;
    free(temp);
    temp = nullptr;
}




// 8. Traverses and prints the list from beginning to end
void traverseInOrder()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    
    // --- CDLL Change ---
    // Print format shows the circular link
    cout << "List (Forward): head <-> ";
    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "head" << endl;
}



// 9. Deletes all nodes and frees the memory
void destroyList()
{
    if (head == nullptr)
    {
        
        cout << "List is empty." << endl;
        return;
    }

    Node *current = head;
    Node *nextNode;

    // --- CDLL Change ---
    // Traverse and free nodes, stopping when we return to the start
    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);

    head = nullptr;
    cout << "List destroyed." << endl;
}

// --- Main Driver Program ---
// (No changes are needed to the main function,
// it works perfectly with the updated functions.)

int main()
{
    createEmptyList();
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Circular Doubly Linked List Menu ---" << endl; // Updated title
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
        cout << "--------------------------------------" << endl;
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
            destroyList(); // Clean up memory before exiting
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}