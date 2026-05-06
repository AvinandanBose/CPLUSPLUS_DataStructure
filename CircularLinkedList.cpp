
#include <cstdlib> // Required for malloc and free
#include <iostream>

using namespace std;
// Defines the structure for each node in the list
typedef struct CLL
{
    int data;
    CLL *next;
} Node;

// Global pointer to the last node of the list
Node *tail;

// Initializes the list as empty
void createEmptyList()
{
    tail = nullptr;
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

    if (tail == nullptr) // If the list is empty
    {
        tail = newNode;
        tail->next = tail; // Point to itself
    }
    else
    {
        newNode->next = tail->next; // New node points to the old first node
        tail->next = newNode;       // Last node points to the new first node
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

    if (tail == nullptr) // If the list is empty
    {
        tail = newNode;
        tail->next = tail; // Point to itself
    }
    else
    {
        newNode->next = tail->next; // New node points to the first node
        tail->next = newNode;       // Old last node points to the new node
        tail = newNode;             // Update tail to be the new last node
    }
    cout << data << " inserted at the end." << endl;
}

// 3. Inserts a new node at a specific position
void insertAtPosition(int data, int pos)
{
    /* -------- sanity checks -------- */
    if (pos < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    /* -------- position 1 → reuse existing routine -------- */
    if (pos == 1)
    {
        insertAtBeginning(data);
        return;
    }
    /* -------- traverse until node (pos-1) -------- */
    Node *temp = tail->next; // Start from the first node
    int count = 1;
    // Traverse to the node just before the desired position
    while (count < pos - 1 && temp != tail)
    {
        temp = temp->next;
        count++;
    }

    /* -------- validate position -------- */

    if (temp == tail && count < pos - 1)
    {
        // This condition is true ONLY IF we hit the end of the list
        // before finding the desired position.
        cout << "Position " << pos << " is out of bounds!" << endl;
        return;
    }
    /* -------- insert -------- */
    // If we need to insert at the end
    if (temp == tail) // insert just after tail
    {
        insertAtEnd(data); // updates tail internally
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == nullptr)
        {
            cout << "Error: Memory allocation failed." << endl;
            return;
        }
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << data << " inserted at position " << pos << "." << endl;
    }
}

// 4. Inserts a new node after a node with a specific value
void insertAfterElement(int data, int element)
{
    if (tail == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = tail->next; // Start from the first node
    do
    {
        if (temp->data == element)
        {
            if (temp == tail)
            { // If the element is the last node
                insertAtEnd(data);
            }
            else
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                if (newNode == nullptr)
                {
                    cout << "Error: Memory allocation failed." << endl;
                    return;
                }
                newNode->data = data;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << data << " inserted after " << element << "." << endl;
            }
            return;
        }
        temp = temp->next;
    } while (temp != tail->next);

    cout << "Element " << element << " not found in the list." << endl;
}

// --- Deletion Operations ---

// 5. Deletes the node from the beginning
void deleteFromBeginning()
{
    if (tail == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *temp = tail->next; // Node to be deleted (the first node)
    cout << "Deleted " << temp->data << " from the beginning." << endl;

    if (tail == tail->next) // If only one node exists
    {
        tail = nullptr;
    }
    else
    {
        tail->next = temp->next; // Tail now points to the second node
        temp->next=nullptr; // Isolate the node to be deleted
    }
    free(temp);
    temp = nullptr;
}

// 6. Deletes the node from the end
void deleteFromEnd()
{
    if (tail == nullptr)
    {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node *toDelete = tail;
    cout << "Deleted " << toDelete->data << " from the end." << endl;

    if (tail == tail->next) // If only one node exists
    {
        tail = nullptr;
    }
    else
    {
        Node *temp = tail->next;
        // Traverse to the second to last node
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next; // Second last node now points to the first node
        tail = temp;             // Update tail
        toDelete->next= nullptr; // Isolate the node to be deleted
    }
    free(toDelete);
    toDelete = nullptr;
}

// 7. Deletes a node from a specific position
void deleteFromPosition(int pos)
{
    if (tail == nullptr)
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

    Node *current = tail->next;
    Node *prev = nullptr;
    int count = 1;

    while (count < pos && current != tail)
    {
        prev = current;
        current = current->next;
        count++;
    }

    // If position is out of bounds (greater than list length)
    if (count < pos && current == tail)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // If deleting the last node
    if (current == tail)
    {
        deleteFromEnd();
        return;
    }

    // Deleting a middle node
    prev->next = current->next;
    current->next = nullptr; // Isolate the node to be deleted
    cout << "Deleted " << current->data << " from position " << pos << "." << endl;
    free(current);
    current = nullptr;
}

// --- Traversal and Utility Operations ---

// 8. Traverses and prints the list
void traverseInOrder()
{
    if (tail == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = tail->next; // Start from the first node
    cout << "List: HEAD -> ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next); // Loop until we are back at the start
    cout << "HEAD (Circular)" << endl;
}

// 9. Deletes all nodes and frees the memory
void destroyList()
{
    if (tail == nullptr)
    {
        cout << "List is already empty." << endl;
        return;
    }

    Node *current = tail->next;
    tail->next = nullptr; // Break the circle to stop the loop
    Node *nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    tail = nullptr;
    cout << "List destroyed." << endl;
}

// --- Main Driver Program ---

int main()
{
    createEmptyList();
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position" << endl;
        cout << "4. Insert after an element" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete from a position" << endl;
        cout << "8. Traverse the list" << endl;
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
            destroyList(); // Clean up memory before exiting
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
