
// Doubly Linked List implementation in C++ using classes
#include <iostream>

// Use the standard namespace
using namespace std;

// Defines the structure for each node in the list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize a new node
    Node(int dataValue)
    {
        this->data = dataValue;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Defines the Doubly Linked List class
class DoublyLinkedList
{
private:
    Node *head; // Private member to store the head of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Destructor to automatically free all memory
    ~DoublyLinkedList()
    {
        prepareForDestruction();
        destroyList();
    }

    // --- Insertion Operations ---

    // 1. Inserts a new node at the beginning of the list
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        // The check for 'new' returning nullptr is generally not needed in modern C++
        // as it throws a std::bad_alloc exception on failure.

        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
        cout << data << " inserted at the beginning." << endl;
    }

    // 2. Inserts a new node at the end of the list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        { // If list is empty, new node becomes the head
            head = newNode;
            cout << data << " inserted at the end." << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode;
        newNode->prev = temp;
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

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        cout << data << " inserted at position " << pos << "." << endl;
    }

    // 4. Inserts a new node after a node with a specific value
    void insertAfterElement(int data, int element)
    {
        Node *temp = head;
        while (temp != nullptr && temp->data != element)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Element " << element << " not found in the list." << endl;
            return;
        }

        Node *newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

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
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        cout << "Deleted " << temp->data << " from the beginning." << endl;
        delete temp; // Use delete instead of free
    }

    // 6. Deletes the node from the end
    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node *temp = head;
        if (temp->next == nullptr)
        { // Only one node in the list
            head = nullptr;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next; // Traverse to the last node
            }
            temp->prev->next = nullptr;
        }
        cout << "Deleted " << temp->data << " from the end." << endl;
        delete temp;
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
        for (int i = 1; i < pos && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        cout << "Deleted " << temp->data << " from position " << pos << "." << endl;
        delete temp;
    }

    // --- Search and Utility Operations ---

    // 8. Search for an element
    void searchForElement(int data)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                cout << "Element " << data << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << data << " not found in the list." << endl;
    }

    // 9. Returns the number of nodes in the list
    int getLength()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 10. Traverses and prints the list from beginning to end
    void traverseInOrder()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "List (Forward): NULL <- ";
        while (temp != nullptr)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 11. Traverses and prints the list from end to beginning
    void traverseInReverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *tail = head;
        while (tail->next != nullptr)
        { // Go to the last node
            tail = tail->next;
        }

        cout << "List (Reverse): NULL <- ";
        while (tail != nullptr)
        {
            cout << tail->data << " <-> ";
            tail = tail->prev;
        }
        cout << "NULL" << endl;
    }

    // 12. Deletes all nodes and frees the memory
    void destroyList()
    {
        if (head == nullptr )
        {
            // Only print a message if it's a user action.
            if (!isDestroying)
            {
                // isDestroying flag prevents double "List is empty" message from destructor
                cout << "List is already empty." << endl;
            } 
            return;
        }

        Node *current = head;
        Node *nextNode;
        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        if (!isDestroying){
            cout << "List destroyed." << endl;
        }
    }

private:
    // Helper flag to avoid double messages when destructor is called
    bool isDestroying = false;

    // This method is called by the destructor
    void prepareForDestruction()
    {
        isDestroying = true;
    }
};

// --- Main Driver Program ---
int main()
{
    DoublyLinkedList list; // Create an object of the DoublyLinkedList class
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position" << endl;
        cout << "4. Insert after an element" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete from a position" << endl;
        cout << "8. Search for an element" << endl;
        cout << "9. Length of the list" << endl;
        cout << "10. Traverse the list in order" << endl;
        cout << "11. Traverse the list in reverse" << endl;
        cout << "12. Destroy the list" << endl;
        cout << "13. Exit" << endl;
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
            cout << "Enter element to search: ";
            cin >> data;
            list.searchForElement(data);
            break;
        case 9:
            cout << "Length of the list is: " << list.getLength() << endl;
            break;
        case 10:
            list.traverseInOrder();
            break;
        case 11:
            list.traverseInReverse();
            break;
        case 12:
            list.destroyList();
            break;
        case 13:
            cout << "Exiting program. Goodbye!" << endl;
            // The destructor ~DoublyLinkedList() will be called automatically here,
            // cleaning up any remaining nodes.
            return 0; // Use return 0 to exit main gracefully
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
