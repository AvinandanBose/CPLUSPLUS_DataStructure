// Circular Linked List implementation in C++ using classes
#include <iostream>

// Use the standard namespace
using namespace std;

// Defines the structure for each node in the list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a new node
    Node(int dataValue)
    {
        this->data = dataValue;
        this->next = nullptr;
    }
};

// Defines the Circular Linked List class
class CircularLinkedList
{
private:
    Node *tail; // Private member to store the tail of the list
                // (In CLL, tail->next points to head, giving access to both)

public:
    // Constructor to initialize an empty list
    CircularLinkedList()
    {
        tail = nullptr;
    }

    // Destructor to automatically free all memory
    ~CircularLinkedList()
    {
        prepareForDestruction();
        destroyList();
    }

    // --- Insertion Operations ---

    // 1. Inserts a new node at the beginning of the list
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        if (tail == nullptr) // If the list is empty
        {
            tail = newNode;
            tail->next = tail; // Point to itself
        }
        else
        {
            newNode->next = tail->next; // New node points to current head
            tail->next = newNode;       // Tail points to new node (new head)
        }
        cout << data << " inserted at the beginning." << endl;
    }

    // 2. Inserts a new node at the end of the list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (tail == nullptr) // If the list is empty
        {
            tail = newNode;
            tail->next = tail; // Point to itself
        }
        else
        {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode;       // Current tail points to new node
            tail = newNode;             // Update tail pointer to new node
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

        Node *temp = tail->next; // Start from head
        int count = 1;

        // Traverse to the node just before the desired position
        // Stop if we reach the tail to avoid infinite loop
        while (count < pos - 1 && temp != tail)
        {
            temp = temp->next;
            count++;
        }

        // Validate if position is out of bounds
        if (temp == tail && count < pos - 1)
        {
            cout << "Position " << pos << " is out of bounds!" << endl;
            return;
        }

        // Check if we are inserting at the end
        if (temp == tail)
        {
            insertAtEnd(data);
        }
        else
        {
            Node *newNode = new Node(data);
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

        Node *temp = tail->next; // Start from head
        do
        {
            if (temp->data == element)
            {
                if (temp == tail)
                {
                    insertAtEnd(data);
                }
                else
                {
                    Node *newNode = new Node(data);
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

        Node *temp = tail->next; // The head node
        cout << "Deleted " << temp->data << " from the beginning." << endl;

        if (tail == tail->next) // If only one node exists
        {
            tail = nullptr;
        }
        else
        {
            tail->next = temp->next; // Tail points to the second node
            temp->next = nullptr;    // Isolate node
        }
        delete temp;
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
            temp->next = tail->next;  // Second last points to head
            tail = temp;              // Update tail
            toDelete->next = nullptr; // Isolate
        }
        delete toDelete;
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

        // If position is out of bounds
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
        current->next = nullptr;
        cout << "Deleted " << current->data << " from position " << pos << "." << endl;
        delete current;
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

        Node *temp = tail->next; // Start from head
        cout << "List: HEAD -> ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "HEAD (Circular)" << endl;
    }

    // 9. Returns the number of nodes (Optional, added for menu consistency)
    int getLength()
    {
        if (tail == nullptr)
            return 0;
        int count = 0;
        Node *temp = tail->next;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }

    // 10. Deletes all nodes and frees the memory
    void destroyList()
    {
        if (tail == nullptr)
        {
            if (!isDestroying)
            {
                cout << "List is already empty." << endl;
            }
            return;
        }

        Node *current = tail->next; // Head
        tail->next = nullptr;       // Break the circle
        Node *nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        tail = nullptr;
        if (!isDestroying)
        {
            cout << "List destroyed." << endl;
        }
    }

private:
    // Helper flag for destructor logic
    bool isDestroying = false;
    void prepareForDestruction()
    {
        isDestroying = true;
    }
};

// --- Main Driver Program ---
int main()
{
    CircularLinkedList list; // Create object of CircularLinkedList class
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
        cout << "9. Length of the list" << endl;
        cout << "10. Destroy the list" << endl;
        cout << "11. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            cout << "Enter data to insert: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> pos;
            list.insertAtPosition(data, pos);
            break;
        case 4:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter the element to insert after: ";
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
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteFromPosition(pos);
            break;
        case 8:
            list.traverseInOrder();
            break;
        case 9:
            cout << "Length of the list is: " << list.getLength() << endl;
            break;
        case 10:
            list.destroyList();
            break;
        case 11:
            cout << "Exiting program. Goodbye!" << endl;
            return 0; // Destructor called automatically
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}