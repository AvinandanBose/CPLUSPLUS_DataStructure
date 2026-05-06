#include <iostream>

using namespace std;

// Node structure for the Circular Doubly Linked List
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to create a new node
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Class for the Circular Doubly Linked List
class CircularDoublyLinkedList
{
public:
    Node *head; // Pointer to the head node

    // Constructor to initialize an empty list
    CircularDoublyLinkedList()
    {
        head = nullptr;
    }

    // Destructor to free memory automatically
    ~CircularDoublyLinkedList()
    {
        destroyList();
    }

    // 1. Insert at the beginning
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            // List is empty, so the new node points to itself.
            newNode->prev = newNode;
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            // Find the last node (which is head->prev) and link it.
            Node *last = head->prev;

            newNode->next = head; // New node points forward to old head
            newNode->prev = last; // New node points back to last node
            head->prev = newNode; // Old head's prev points to new node
            last->next = newNode; // Last node's next points to new node
            head = newNode;       // Update the head pointer
        }
        cout << data << " inserted at the beginning." << endl;
    }

    // 2. Insert at the end
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            // If list is empty, same as insertAtBeginning
            newNode->prev = newNode;
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            // O(1) Access: Get the last node directly
            Node *last = head->prev;

            newNode->next = head; // New node points forward to head
            newNode->prev = last; // New node points back to old last
            last->next = newNode; // Old last's next points to new node
            head->prev = newNode; // Head's prev points to the new last node
        }
        cout << data << " inserted at the end." << endl;
    }

    // 3. Insert at a specific position
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
        if (head == nullptr)
        {
            cout << "Position out of bounds! List is empty." << endl;
            return;
        }

        Node *temp = head;

        // --- LOOP TECHNIQUE PRESERVED: FOR LOOP ---
        // Traverse to the node *before* the insertion point
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

        Node *newNode = new Node(data);

        newNode->next = temp->next;
        newNode->prev = temp;

        // Update links
        temp->next->prev = newNode;
        temp->next = newNode;

        cout << data << " inserted at position " << pos << "." << endl;
    }

    // 4. Insert after an element
    void insertAfterElement(int data, int element)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;

        // --- LOOP TECHNIQUE PRESERVED: DO-WHILE LOOP ---
        do
        {
            if (temp->data == element)
            {
                // Found the element
                Node *newNode = new Node(data);

                newNode->next = temp->next;
                newNode->prev = temp;

                // Update pointers
                temp->next->prev = newNode;
                temp->next = newNode;

                cout << data << " inserted after " << element << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Element " << element << " not found in the list." << endl;
    }

    // 5. Delete from the beginning
    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = head;
        cout << "Deleted " << temp->data << " from the beginning." << endl;

        if (head->next == head)
        {
            // Case 1: Only one node in the list
            head = nullptr;
        }
        else
        {
            // Case 2: Multiple nodes
            Node *last = head->prev;
            head = head->next; // Move head to the second node
            head->prev = last; // New head's prev points to last
            last->next = head; // Last's next points to new head
        }
        delete temp;
    }

    // 6. Delete from the end
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // O(1) Access to last node
        Node *last = head->prev;
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
        delete last;
    }

    // 7. Delete from a specific position
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

        // --- LOOP TECHNIQUE PRESERVED: FOR LOOP ---
        // Traverse to the node *at* the position
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
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        cout << "Deleted " << temp->data << " from position " << pos << "." << endl;
        delete temp;
    }

    // 8. Traverse the list in order
    void traverseInOrder()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;

        // --- LOOP TECHNIQUE PRESERVED: DO-WHILE LOOP ---
        cout << "List (Forward): head <-> ";
        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "head" << endl;
    }

    // 9. Destroy the list
    void destroyList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        Node *nextNode;

        // --- LOOP TECHNIQUE PRESERVED: DO-WHILE LOOP ---
        do
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        cout << "List destroyed." << endl;
    }
};

// --- Main Driver Program ---
int main()
{
    CircularDoublyLinkedList list;
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Circular Doubly Linked List Menu ---" << endl;
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
            list.destroyList();
            break;
        case 10:
            cout << "Exiting program. Goodbye!" << endl;
            // Destructor will strictly handle cleanup
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}