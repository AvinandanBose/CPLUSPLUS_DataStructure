#include <cstdint> // Required for uintptr_t (essential for pointer XOR)
#include <iostream>

using namespace std;

// Node structure for the XOR Linked List
class Node
{
public:
    int data;
    Node *npx; // XOR of next and prev pointer

    Node(int val)
    {
        this->data = val;
        this->npx = nullptr;
    }
};

class XORLinkedList
{
private:
    Node *head;

    // Helper Function for XOR Operation
    Node *XOR(Node *a, Node *b)
    {
        return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
    }

public:
    XORLinkedList()
    {
        head = nullptr;
    }

    ~XORLinkedList()
    {
        destroyList();
    }

    // 1. Insert at the beginning
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        // newNode->npx = NULL ^ current_head
        newNode->npx = XOR(nullptr, head);

        if (head != nullptr)
        {
            // Update old head's npx: (NewNode ^ next_of_old_head)
            Node *next = XOR(nullptr, head->npx);
            head->npx = XOR(newNode, next);
        }

        head = newNode;
        cout << data << " inserted at the beginning." << endl;
    }

    // 2. Insert at the end
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            Node *prev = nullptr;
            Node *next;

            // Traverse to the last node
            while (XOR(prev, curr->npx) != nullptr)
            {
                next = XOR(prev, curr->npx);
                prev = curr;
                curr = next;
            }

            // Update last node: npx was (prev ^ NULL), now (prev ^ newNode)
            curr->npx = XOR(prev, newNode);
            // Update newNode: npx is (last_node ^ NULL)
            newNode->npx = XOR(curr, nullptr);
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

        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        for (int i = 1; curr != nullptr && i < pos - 1; i++)
        {
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }

        if (curr == nullptr)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        next = XOR(prev, curr->npx); // This is the node currently at 'pos'
        Node *newNode = new Node(data);

        newNode->npx = XOR(curr, next);
        curr->npx = XOR(prev, newNode);

        if (next != nullptr)
        {
            Node *nextNext = XOR(curr, next->npx);
            next->npx = XOR(newNode, nextNext);
        }
        cout << data << " inserted at position " << pos << "." << endl;
    }

    // 4. Insert after an element
    void insertAfterElement(int data, int element)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        while (curr != nullptr && curr->data != element)
        {
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }

        if (curr == nullptr)
        {
            cout << "Element " << element << " not found." << endl;
            return;
        }

        next = XOR(prev, curr->npx);
        Node *newNode = new Node(data);

        newNode->npx = XOR(curr, next);
        curr->npx = XOR(prev, newNode);

        if (next != nullptr)
        {
            Node *nextNext = XOR(curr, next->npx);
            next->npx = XOR(newNode, nextNext);
        }
        cout << data << " inserted after " << element << "." << endl;
    }

    // 5. Delete from the beginning
    void deleteFromBeginning()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        Node *next = XOR(nullptr, head->npx);

        if (next != nullptr)
        {
            Node *nextNext = XOR(temp, next->npx);
            next->npx = XOR(nullptr, nextNext);
        }

        head = next;
        cout << "Deleted " << temp->data << " from beginning." << endl;
        delete temp;
    }

    // 6. Delete from the end
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;

        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        while (XOR(prev, curr->npx) != nullptr)
        {
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }

        if (prev != nullptr)
        {
            Node *prevPrev = XOR(prev->npx, curr);
            prev->npx = XOR(prevPrev, nullptr);
        }
        else
        {
            head = nullptr;
        }

        cout << "Deleted " << curr->data << " from end." << endl;
        delete curr;
    }

    // 7. Delete from a position
    void deleteFromPosition(int pos)
    {
        if (head == nullptr || pos < 1)
            return;
        if (pos == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        for (int i = 1; curr != nullptr && i < pos; i++)
        {
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }

        if (curr == nullptr)
            return;

        next = XOR(prev, curr->npx);
        Node *prevPrev = XOR(prev->npx, curr);
        prev->npx = XOR(prevPrev, next);

        if (next != nullptr)
        {
            Node *nextNext = XOR(curr, next->npx);
            next->npx = XOR(prev, nextNext);
        }

        cout << "Deleted " << curr->data << " from position " << pos << "." << endl;
        delete curr;
    }

    // 8. Traverse the list
    void traverseInOrder()
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        cout << "List (Forward): ";
        while (curr != nullptr)
        {
            cout << curr->data << " <-> ";
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        cout << "NULL" << endl;
    }

    // 9. Destroy the list
    void destroyList()
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next;

        while (curr != nullptr)
        {
            next = XOR(prev, curr->npx);
            delete curr;
            prev = curr; // address is used as a value for calculation only
            curr = next;
        }
        head = nullptr;
        cout << "Memory cleared. List destroyed." << endl;
    }
};

int main()
{
    XORLinkedList list;
    int choice, data, pos, element;

    while (true)
    {
        cout << "\n--- Memory Efficient XOR Linked List (Class-Based) ---" << endl;
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Insert after Element" << endl;
        cout << "5. Delete Beginning\n6. Delete End\n7. Delete Position\n8. Traverse\n9. Destroy\n10. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 10)
            break;

        switch (choice)
        {
        case 1:
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 3:
            cin >> data >> pos;
            list.insertAtPosition(data, pos);
            break;
        case 4:
            cin >> data >> element;
            list.insertAfterElement(data, element);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cin >> pos;
            list.deleteFromPosition(pos);
            break;
        case 8:
            list.traverseInOrder();
            break;
        case 9:
            list.destroyList();
            break;
        default:
            cout << "Invalid!" << endl;
        }
    }
    return 0;
}