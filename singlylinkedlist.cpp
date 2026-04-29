#include <iostream>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} Node;

Node *head; // global variable can be accessed anywhere in the program



//+++++++ Creating  Empty List ++++++ //

void createEmptyList(Node **head)
{
    
    *head = nullptr; // Set the head pointer to nullptr, effectively creating an empty list
    cout << endl;
    cout << endl;
    cout << "Empty list created!!!" << endl;
    cout << endl;
    cout << endl;
}

//+++++++ Inserting a Node at the Beginning ++++++ //

void insertAtBeginning(Node **head, int data) //->1

{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node

    // Check if memory allocation was successful
    if (newNode == nullptr)
    {
        // Handle memory allocation error (e.g., print an error message and return)
        cout << "Error: Memory allocation failed." << endl;
        return; // Exit the function if memory allocation failed
    }
    // Assign data to the new node
    newNode->data = data;

    // Check if the list is empty
    if (*head == nullptr)
    {
        // If the list is empty, make the new node the head of the list
        newNode->next = nullptr; // Set the next pointer of the new node to nullptr
        *head = newNode;         // Update the head pointer to point to the new node
    }
    else
    {
        // If the list is not empty, insert the new node at the beginning
        newNode->next = *head; // Update the next pointer of the new node to point to the current head
        *head = newNode;       // Update the head pointer to point to the new node
    } 

}

//+++++++ Inserting a Node at the End ++++++ //

void insertAtEnd(Node **head, int data) //->2
{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node

    // Check if memory allocation was successfulSide Bar EntrySide Bar EntrySide Bar EntrySide Bar EntrySide Bar EntrySide Bar EntrySide Bar EntrySide Bar EntrySide Bar Entry
    if (newNode == nullptr)
    {
        // Handle memory allocation error (e.g., print an error message and return)
        cout << "Error: Memory allocation failed." << endl;
        return; // Exit the function if memory allocation failed
    }
    // Assign data to the new node
    newNode->data = data;    // Assign data to the new node
    newNode->next = nullptr; // Set the next pointer of the new node to nullptr

    // Check if the list is empty
    if (*head == nullptr)
    {
        // If the list is empty, make the new node the head of the list
        *head = newNode; // Update the head pointer to point to the new node
    }
    else
    {
        // If the list is not empty, insert the new node at the end
        Node *current = *head; // Create a pointer to traverse the list
        while (current->next != nullptr)
        {
            current = current->next; // Move to the next node
        }
        current->next = newNode; // Update the next pointer of the last node to point to the new node
    }
}

//+++++++ Inserting a Node at a Given Position, indexing 1 i.e. starting Node is 1 to N ++++++ //

void insertAtPosition(Node **head, int data, int position) //->3
{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node

    // Check if memory allocation was successful
    if (newNode == nullptr)
    {
        // Handle memory allocation error (e.g., print an error message and return)
        cout << "Error: Memory allocation failed." << endl;
        return; // Exit the function if memory allocation failed
    }

    // Assign data to the new node
    newNode->data = data; // Assign data to the new node

    // Handle the case where position is 1 (insert at beginning)
    if (position == 1)
    {
        newNode->next = *head; // Link the new node to the old head
        *head = newNode;       // Update the head pointer to point to the new node
        return;
    }

    // Check if the list is empty (position cannot be greater than 1)
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function if the list is empty
    }

    // Handle invalid positions (less than 1)
    if (position < 1) // Check if the specified position is less than 1
    {
        cout << "Error: Invalid position." << endl; // Print an error message
        return;                                     // Exit the function if the specified position is invalid
    }
    else
    {
        // If the list is not empty
        Node *current = *head; // Create a pointer to traverse the list
        int i = 1;             // Counter variable to keep track of the current position

        // Traverse the list until the specified position arrives
        while (i < position - 1 && current != nullptr) // Check if the current node is not NULL and the counter is less than the specified position
        {
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }

        // Check if the specified position is valid
        if (current == nullptr) // If the current node is NULL, the specified position is invalid
        {
            cout << "Error: Invalid position." << endl; // Print an error message
            return;                                     // Exit the function if the specified position is invalid
        }

        else
        {
            // Insert the new node at the specified position
            newNode->next = current->next; // Update the next pointer of the new node to point to the next node
            current->next = newNode;       // Update the next pointer of the current node to point to the new node
        }
    }
}

//+++++++ Inserting a Node at a Given Position , indexing 0 i.e. starting node is : 0  to N-1 ++++++ //

void insertAtPosition2(Node **head, int data, int position) //->4
{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node

    // Check if memory allocation was successful
    if (newNode == nullptr)
    {
        // Handle memory allocation error (e.g., print an error message and return)
        cout << "Error: Memory allocation failed." << endl;
        return; // Exit the function if memory allocation failed
    }

    // Assign data to the new node
    newNode->data = data; // Assign data to the new node

    // Handle the case where position is 1 (insert at beginning)
    if (position == 0)
    {
        newNode->next = *head; // Link the new node to the old head
        *head = newNode;       // Update the head pointer to point to the new node
        return;
    }

    // Check if the list is empty (position cannot be greater than 0)
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function if the list is empty
    }

    // Handle invalid positions (less than 0)
    if (position < 0) // Check if the specified position is less than 0
    {
        cout << "Error: Invalid position." << endl; // Print an error message
        return;                                     // Exit the function if the specified position is invalid
    }
    else
    {
        // If the list is not empty
        Node *current = *head; // Create a pointer to traverse the list
        int i = 0;             // Counter variable to keep track of the current position

        // Traverse the list until the specified position arrives
        while (i < position - 1 && current != nullptr) // Check if the current node is not NULL and the counter is less than the specified position
        {
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }

        // Check if the specified position is valid
        if (current == nullptr) // If the current node is NULL, the specified position is invalid
        {
            cout << "Error: Invalid position." << endl; // Print an error message
            return;                                     // Exit the function if the specified position is invalid
        }

        else
        {
            // Insert the new node at the specified position
            newNode->next = current->next; // Update the next pointer of the new node to point to the next node
            current->next = newNode;       // Update the next pointer of the current node to point to the new node
        }
    }
}


         
//+++++++ Deleting a Node from the Beginning ++++++ //

void deleteFromBeginning(Node **head) //->6
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl;
        return; // Exit the function if the list is empty
    }
    else
    {
        // Store the head node
        Node *temp = *head;
        // Update head pointer to point to the next node
       *head = (*head)->next;
        cout << "Deleted node: " << temp->data << endl; // Print the data of the deleted node
        temp->next = nullptr; // Set the next pointer of the deleted node to nullptr to stop pointing to address that next pointer holds earlier
        // Free the memory of the deleted node
        free(temp);
        temp = nullptr; // Set temp to nullptr to avoid dangling pointers in memory
    }
    cout << "Node is deleted successfully." << endl; // Print a success message indicating that the node is deleted successfully
}



//+++++++ Deleting a Node from the End ++++++ //

void deleteFromEnd(Node **head) //->7
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl;
        return; // Exit the function if the list is empty
    }
    // If the list is not empty
    else
    {
        // Create two pointers to keep track of the current and previous nodes
        Node *current = *head;    // The node we are currently at
        Node *previous = nullptr; // The node before current

        // Traverse the list until the last node is reached
        while (current->next != nullptr)
        {
            previous = current;      // Update the previous pointer to point to the current node
            current = current->next; // Move to the next node
        }
        // Delete the last node
        if (previous == nullptr)
        {
            // If the list has only one node, set the head pointer to nullptr
            *head = nullptr;
            
        }
        else
        {
            // Set the next pointer of the previous node to nullptr, effectively removing the last node
            previous->next = nullptr;
        }
        cout << "Deleted node: " << current->data << endl; // Print the data of the deleted node
        // Free the memory allocated for the removed node
        free(current);
        current = nullptr; // Set current to nullptr to avoid dangling pointers
        previous = nullptr; //Set previous to nullptr to avoid dangling pointers
        cout << "Node is deleted successfully." << endl; // Print a success message indicating that the node is deleted successfully
    }
}

//+++++++ Deleting a Node from a Given Position , indexing from 1 to N ++++++ //

void deleteAtPosition(Node **head, int position) //->8
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl;
        return; // Exit the function if the list is empty
    }
    if (position < 1) // Check if the specified position is less than 1
    {
        cout << "Error: Invalid position." << endl; // Print an error message
        return;                                     // Exit the function if the specified position is invalid
    }
    else
    {
        // Create two pointers to keep track of the current and previous nodes
        Node *current = *head;    // The node we are currently at.
        Node *previous = nullptr; // The node before current.
        int i = 1;                // Counter to keep track of the position.

        // Traverse the list until the specified position is reached
        while (i < position && current != nullptr)
        {
            previous = current;      // Update the previous pointer to point to the current node
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }
        //Check if the specified position is valid
        if (current == nullptr)
        {
            cout << "Error: Invalid position." << endl; // Print an error message
            return;                                     // Exit the function if the position is invalid.
        }
        else
        {
            // Delete the node at the specified position
            if (previous == nullptr)
            {
                //*head = previous; // Set the head pointer to nullptr(option :1)
                // If the node to be deleted is the head node
                *head = current->next; // Set the head pointer to nullptr to remove the head node(or apply this option)
            }
            else
            {
                // Update the next pointer of the previous node to skip the current node
                previous->next = current->next;
            }
            cout << "Deleted node: " << current->data << endl; // Print the data of the deleted node
            current->next = nullptr; // Set the next pointer of the deleted node to nullptr to avoid dangling pointers in memory
            // Free the memory allocated for the removed node
            free(current);
            current = nullptr; // Set current to nullptr to avoid dangling pointers
            previous = nullptr; //Set previous to nullptr to avoid dangling pointers
            cout << "Node is deleted successfully." << endl; // Print a message indicating that the node is deleted successfully
        }
    }
}

//+++++++ Deleting a Node from a Given Position , indexing from 0 to N-1 ++++++ //

void deleteAtPosition2(Node **head, int position) //->9
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl;
        return; // Exit the function if the list is empty
    }
    if (position < 0)
    {
        cout << "Error: Invalid position." << endl;
        return; // Exit the function if the specified position is invalid
    }
    else
    {
        // Create two pointers to keep track of the current and previous nodes
        Node *current = *head;    // The node we are currently at.
        Node *previous = nullptr; // The node before current.
        int i = 0;                // Counter to keep track of the position.

        // Traverse the list until the specified position is reached
        while (i < position && current != nullptr)
        {
            previous = current;      // Update the previous pointer to point to the current node
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }
        // Check if the specified position is valid
        if (current == nullptr)
        {
            cout << "Error: Invalid position." << endl;
            return; // Exit the function if the position is invalid.
        }
        else
        {
            // Delete the node at the specified position
            if (previous == nullptr)
            {
                // If the node to be deleted is the head node
                *head = current->next; // Set the head pointer to the new head.
            }
            else
            {
                // Update the next pointer of the previous node to skip the current node
                previous->next = current->next;
            }
            cout << "Deleted node: " << current->data << endl; // Print the data of the deleted node
            current->next = nullptr;                           // Set the next pointer of the deleted node to nullptr to avoid dangling pointers in memory
            // Free the memory allocated for the removed node
            free(current);
            current = nullptr; // Set current to nullptr to avoid dangling pointers
            previous = nullptr; // Set previous to nullptr to avoid dangling pointers
            cout << "Node is deleted successfully." << endl; // Print a message indicating that the node is deleted successfully
        }
    }
}

//+++++++ Search An Element in Linked List(Iterative) ++++++ //

bool searchElementInSortedListIterative(Node **head, int key) //->10
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl;
        return false; // Exit the function if the list is empty
    }
    else
    {
        // Create a pointer to traverse the list
        Node *current = *head;
        // Traverse the list until the key is found
        while (current != nullptr)
        {
            // If the key is found, return true
            if (current->data == key)
            {
                return true;
            }
            current = current->next; // Move to the next node
        }
        // If the key is not found, return false
        return false;
    }
}

// The above is an iterative approach and a linear search algorithm.//

//+++++++ Search An Element in Linked List(Recursive) ++++++ //

bool searchElementInSortedListRecursive(Node **head, int key) //->11
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        return false; // Exit the function if the list is empty
    }
    else
    {
        // Base case: If the key is found, return true
        if ((*head)->data == key)
        {
            return true;
        }
        // Recursive case: Move to the next node and search for the key
        else
        {
            return searchElementInSortedListRecursive(&((*head)->next), key);
        }
    }
}

// The above is an recursive approach and a linear search algorithm.//

//+++++++ Search An Element through AuxiliarySearch Function ++++++ //

void auxiliarySearch(Node **head, int key, Node **ploc, Node **loc) //->12
{
    // Check if the list is empty

    if (*head == nullptr) // If the list is empty
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function
    }

    if ((*head)->data == key) // If the key is found at the head node
    {
        *loc = *head; // Set the location pointer to the head node
        return;
    }

    *ploc = *head;        // Set the previous location pointer to the head node
    *loc = (*head)->next; // Set the location pointer to the next node

    while (*loc != nullptr) // Traverse the list until the key is found
    {
        if ((*loc)->data == key) // If the key is found
        {
            return;
        }
        else // If the key is not found
        {
            *ploc = *loc;        // Update the previous location pointer
            *loc = (*loc)->next; // Move to the next node
        }
    }

    // If the key is not found, loc will be nullptr
}

//+++++++ Search In Unsorted Linked List ++++++ //

Node *searchInUnsortedList(Node **head, int key) //->13
{
    Node *current = *head;                             // Use a temporary pointer to traverse the list
    while (current != nullptr && current->data != key) // Traverse the list until the key is found or the end of the list is reached
    {
        current = current->next; // Move to the next node
    }
    return current; // Return the node containing the key or nullptr if the key is not found
}

//+++++++ Insert After Element ++++++ //

void insertAfterElement(Node **head, int data, int after) //->5
{
    Node *ptr, *loc;
    ptr = (Node *)malloc(sizeof(Node));      // Allocate memory for the new node
    loc = searchInUnsortedList(head, after); // Search for the node after which the new node is to be inserted
    if (loc == nullptr)                      // If the node is not found
    {
        cout << "Error: Element not found." << endl; // Print an error message
        return;                                      // Exit the function
    }
    ptr->data = data;      // Assign data to the new node
    ptr->next = loc->next; // Link the new node to the next node
    loc->next = ptr;       // Link the current node to the new node
}

//+++++++ Reverse a Linked List ++++++ //

void reverseList(Node **head) //->14
{

    if (*head == nullptr) // Check if the list is empty
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function if the list is empty
    }
    // Initialize three pointers to keep track of the previous, current, and next nodes
    Node *previous = nullptr; // The node before the current node
    Node *current = *head;    // The node we are currently at
    Node *next = nullptr;     // The node after the current node

    // Traverse the list and reverse the links between the nodes
    while (current != nullptr)
    {
        next = current->next;     // Save the next node
        current->next = previous; // Reverse the link
        previous = current;       // Move the previous pointer one step forward
        current = next;           // Move the current pointer one step forward
    }
    // Update the head pointer to point to the last node, which is now the first node
    *head = previous;
}

// Function to reverse the linked list using stack
void reverseListUsingStack(Node **head) //->15
{
    if (*head == nullptr) // Check if the list is empty
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function if the list is empty
    }
    else
    {
        stack<Node *> s;           // Create a stack of nodes to store the nodes of the list
        Node *current = *head;     // Initialize a pointer to traverse the list
        while (current != nullptr) // Traverse the list and push each node to the stack
        {
            s.push(current);         // Push the current node to the stack
            current = current->next; // Move to the next node
        }
        *head = s.top();   // Set the head pointer to the top of the stack
        s.pop();           // Pop the top node from the stack
        current = *head;   // Initialize a pointer to traverse the list again
        while (!s.empty()) // Traverse the stack and link the nodes together
        {
            current->next = s.top(); // Link the current node to the top of the stack
            s.pop();                 // Pop the top node from the stack
            current = current->next; // Move to the next node
        }
        current->next = nullptr; // Set the last node's next pointer to nullptr to indicate the end of the list
    }
}

// Function to reverse the linked list using recursion
void reverseListUsingRecursion(Node **head) //->16
{
    if (*head == nullptr) // Check if the list is empty
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return;                                  // Exit the function if the list is empty
    }
    else
    {
        Node *first = *head;      // The first node in the list
        Node *rest = first->next; // The rest of the list after the first node
        if (rest == nullptr)      // Check if the rest of the list is empty
        {
            return; // Exit the function if the rest of the list is empty
        }
        reverseListUsingRecursion(&rest); // Reverse the rest of the list using recursion
        first->next->next = first;        // Link the first node to the rest of the list
        first->next = nullptr;            // Set the next pointer of the first node to nullptr to indicate the end of the list
        *head = rest;                     // Set the head pointer to the rest of the list    
    
    }
}

//+++++++ Find the Length of a Linked List ++++++ //

int lengthOfList(Node **head) //->17
{
    // Initialize a counter variable to keep track of the length
    int length = 0;
    // Create a pointer to traverse the list
    Node *current = *head;
    // Traverse the list and increment the counter for each node
    while (current != nullptr)
    {
        length++;                // Increment the counter
        current = current->next; // Move to the next node
    }
    // Return the length of the list
    return length;
}

//+++++++ function to get Nth node in a Linked List ,1 based indexing ++++++ //

int getNthNode(Node **head, int node) //->18
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return -1;                               // Return -1 if the list is empty
    }
    if (node < 1 || node > lengthOfList(head)) // Check if the node is out of range or below 1
    {
        cout << "Error: Invalid index." << endl; // Print an error message
        return -1;                               // Return -1 if the node is out of range or below 1
    }
    else
    {
        // Create a pointer to traverse the list
        Node *current = *head;
        int i = 1; // Counter variable to keep track of the current index

        // Traverse the list until the specified index is reached
        while (i < node)
        {
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }
        
        return current->data;
        
    }
}

//+++++++ function to get Nth node in a Linked List ,0 based indexing ++++++ //
int getNthNode2(Node **head, int node) //->19
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Error: List is empty." << endl; // Print an error message
        return -1;                               // Return -1 if the list is empty
    }
    if (node < 0) // Check if the node is less than 0
    {
        return -1;   // Return -1 if the node is less than 0
    }
    else
    {
        // Create a pointer to traverse the list
        Node *current = *head;
        int i = 0; // Counter variable to keep track of the current index

        // Traverse the list until the specified index is reached
        while (i < node && current != nullptr)
        {
            current = current->next; // Move to the next node
            i++;                     // Increment the counter
        }

        if(current == nullptr){
            return -1; // Return -1 if the node is out of range
        }
        else{
            // Return the data of the node at the specified index
            return current->data;
        }      
    }
}

//+++++++ Nth node from the end of a Linked List ,1 based indexing++++++ //

int getNthNodeFromEnd(Node **head, int node) //->20
{
    int len = 0;     // len is the length of the list and i is the counter variable
    Node *current;   // Create a pointer to traverse the list
    current = *head; // Initialize the current pointer to the head of the List
    // Traverse the list to get the length of the list
    while (current != nullptr) // While the current node is not nullptr, increment the counter
    {
        current = current->next; // Move to the next node
        len++;                   // Increment the counter
    }
    if (node < 1 || node > len) // Check if the node is out of range or below 1
    {
        cout << "Error: Invalid index." << endl; // Print an error message
        return -1;                               // Return -1 if the index is invalid
    }
    else
    {
        current = *head; // Reset the current pointer to the head of the list
        // Traverse the list to get the Nth node from the end
        for (int i = 0; i < len - node; i++)
        {
            current = current->next; // Move to the next node
        }
        return current->data; // Return the data of the Nth node from the end
    }
}

//+++++++ Nth node from the end of a Linked List ,0 based indexing++++++ //

int getNthNodeFromEnd2(Node **head, int node) //->21
{
    int len = 0;     // len is the length of the list and i is the counter variable
    Node *current;   // Create a pointer to traverse the list
    current = *head; // Initialize the current pointer to the head of the List

    // Traverse the list to get the length of the list
    while (current != nullptr) // While the current node is not nullptr, increment the counter
    {
        current = current->next; // Move to the next node
        len++;                   // Increment the counter
    }
    if (node < 0 || node >= len) // Check if the node is out of range
    {
        cout << "Error: Invalid index." << endl; // Print an error message
        return -1;                               // Return -1 if the index is invalid
    }
    else
    {
        current = *head; // Reset the current pointer to the head of the list
        // Traverse the list to get the Nth node from the end
        for (int i = 0; i < len - node - 1; i++)
        {
            current = current->next; // Move to the next node
        }
        return current->data; // Return the data of the Nth node from the end
    }
}

//+++++++ Traverse List In Order ++++++ //

void TraverseListInorder(Node **head) //->22
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "List is empty." << endl; // If the list is empty, print a message
        return;                           // Exit the function if the list is empty
    }
    else
    {
        // Traverse the list and print each node's data
        Node *current = *head;     // The node we are currently at.
        while (current != nullptr) // While the current node is not nullptr, print the data and move to the next node
        {
            cout << current->data << " "; // Print the data of the current node
            current = current->next;      // Move to the next node
        }
        cout << endl; // Print a new line after printing all the nodes
    }
}

//+++++++ Traverse List In Order 2 (using for loop) ++++++ //

void TraverseListInorder2(Node **head) //->23
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "List is empty." << endl; // If the list is empty, print a message
        return;                           // Exit the function if the list is empty
    }
    else
    {
        for (Node **current = head; *current != nullptr; current = &((*current)->next))
        {
            cout << (*current)->data << " "; // Print the data of the current node
        }
        cout << endl; // Print a new line after printing all the nodes
    }
}

//+++++++ Traverse List In Reverse Order 1 (iterative) ++++++ //

void TraverseListReverseOrderIterative(Node **head) //->24
{
    // Check if the list is empty
    if (*head == nullptr) // If the list is empty, print a message
    {
        cout << "List is empty." << endl;
        return; // Exit the function if the list is empty
    }

    // Reverse the list
    reverseList(head);

    // Print the reversed list
    Node **current = head;      // The node we are currently at.
    while (*current != nullptr) // While the current node is not nullptr, print the data and move to the next node
    {
        cout << (*current)->data << " "; // Print the data of the current node
        current = &((*current)->next);   // Move to the next node
    }
    cout << endl; // Print a new line after printing all the nodes

    // Restore the original list order by reversing it again
    reverseList(head); // Reverse the list again to restore the original order
}

//+++++++ Traverse List In Reverse Order 2 (iterative using stack library) ++++++ //

void TraverseListReverseOrderUsingStack(Node **head) //->25
{
    // Check if the list is empty
    if (*head == nullptr) // If the list is empty, print a message
    {
        cout << "List is empty." << endl;
        return; // Exit the function if the list is empty
    }

    // Create a stack to store the nodes
    stack<Node *> s;
    Node **current = head; // The node we are currently at.

    // Push all the nodes onto the stack
    while (*current != nullptr) // While the current node is not nullptr, push the node onto the stack and move to the next node
    {
        s.push(*current);              // Push the current node onto the stack
        current = &((*current)->next); // Move to the next node
    }

    // Pop and print the nodes from the stack
    while (!s.empty()) // While the stack is not empty, pop the node from the stack and print the data
    {
        cout << s.top()->data << " "; // Print the data of the top node
        s.pop();                      // Pop the top node from the stack
    }
    cout << endl; // Print a new line after printing all the nodes
}

//+++++++ Traverse List In Reverse Order 3 (Recursive) ++++++ //

void TraverseListReverseOrderRecursive(Node **head) //->26
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "List is empty." << endl; // If the list is empty, print a message
        return;                           // Exit the function if the list is empty
    }
    else
    {
        // Traverse the list in reverse order using recursion
        if ((*head)->next != nullptr) // If the next node is not nullptr, call the function recursively
        {
           
            TraverseListReverseOrderRecursive(&(*head)->next); // Call the function recursively with the next node
        }
        cout << (*head)->data << " "; // Print the data of the current node
    }
}

// Function to destroy the linked list

void destroyList(Node **head) //->27
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "List is empty." << endl; // If the list is empty, print a message
        return;                           // Exit the function if the list is empty
    }
    Node **current = head; // Pointer to traverse the list
    Node *next; // Pointer to store the next node
    while (*current != nullptr) // Traverse the list and free each node
    {
        next = (*current)->next; // Store the next node
        free(*current); // Free the current node
        *current = next; // Move to the next node i.e. nullptr
    }
    
}



//+++++++ Main Function ++++++ //

int main()
{

   createEmptyList(&head);

    
    while (1)
    {
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a position,indexing node from 1 to N" << endl;
        cout << "4. Insert at a position,indexing node from 0 to N-1" << endl;
        cout << "5. Insert after an element" << endl;
        cout << "6. Delete from the beginning" << endl;
        cout << "7. Delete from the end" << endl;
        cout << "8. Delete from a position,indexing node from 1 to N" << endl;
        cout << "9.Delete from a position,indexing node from 0 to N-1" << endl;
        cout << "10.Search for an element in sorted list(iterative)" << endl;
        cout << "11.Search for an element in sorted list(recursive)" << endl;
        cout << "12.Auxiliary Search for an element in sorted list" << endl;
        cout << "13.Search for an element in unsorted list" << endl;
        cout << "14.Reverse the list" << endl;
        cout << "15.Reverse the list using stack" << endl;
        cout << "16.Reverse the list using recursion" << endl;
        cout << "17.Length of the List" << endl;
        cout << "18.Nth node from the beginning,1 based indexing" << endl;
        cout << "19.Nth node from the beginning,0 based indexing" << endl;
        cout << "20.Nth node from the end,1 based indexing" << endl;
        cout << "21.Nth node from the end,0 based indexing" << endl;
        cout << "22.Traverse List In Order 1:(using while loop)" << endl;
        cout << "23.Traverse List In Order 2:(using for loop)" << endl;
        cout << "24.Traverse List Reverse Order Iterative" << endl;
        cout << "25.Traverse List Reverse Order Using Stack" << endl;
        cout << "26.Traverse List Reverse Order Recursive" << endl;
        cout << "27.Destroy List" << endl;
        cout << "28.Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << endl;
            cout << endl;
            int data;
            cout << "Enter the data: ";
            cin >> data;
            insertAtBeginning(&head, data);
            cout << "Now, the list is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            cout << endl;
            int data;
            cout << "Enter the data: ";
            cin >> data;
            insertAtEnd(&head, data);
            cout << "Now, the list is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            cout << endl;
            cout << "Insert at a position,indexing node from 1 to N:" << endl;
            cout << endl;
            int data,position;
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the position: ";
            cin >> position;
            insertAtPosition(&head, data, position);
            cout << "Now, the list is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 4:
        {
            cout << endl;
            cout << endl;
            cout << "Insert at a position,indexing node from 0 to N-1:" << endl;
            cout << endl;
            int data, position;
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the position: ";
            cin >> position;
            insertAtPosition2(&head, data, position);
            cout << "Now, the list is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 5:
        {
            cout << endl;
            cout << endl;
            int data, after;
            cout << "Enter the data: ";
            cin >> data;
            cout << "Enter the element after which to insert: ";
            cin >> after;
            insertAfterElement(&head, data, after);
            cout << "Now, the list is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 6:
        {
            cout << endl;
            cout << endl;
            deleteFromBeginning(&head);
            cout << "Now, the list after deletion at the beginning is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 7:
        {
            cout << endl;
            cout << endl;
            deleteFromEnd(&head);
            cout << "Now, the list after deletion at the end is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 8:
        {
            cout << endl;
            cout << endl;
            cout << "Delete at a position,indexing node from 1 to N:" << endl;
            cout << endl;
            int position;
            cout << "Enter the node position to delete: ";
            cin >> position;
            deleteAtPosition(&head, position);
            cout << "Now, the list after deletion after position:" << position << " is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 9:
        {
            cout << endl;
            cout << endl;
            cout << "Delete at a position,indexing node from 0 to N-1:" << endl;
            cout << endl;
            int position;
            cout << "Enter the node position to delete: ";
            cin >> position;
            deleteAtPosition2(&head, position);
            cout << "Now, the list after deletion after position:" << position << " is:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 10:
        {
            cout << endl;
            cout << endl;
            int key;
            cout << "Enter the element to search: ";
            cin >> key;
            if (searchElementInSortedListIterative(&head, key))
            {
                cout << "Element found." << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            cout << endl;
            cout << endl;
            break;
        }

        case 11:
        {
            cout << endl;
            cout << endl;
            int key;
            cout << "Enter the element to search: ";
            cin >> key;
            if (searchElementInSortedListRecursive(&head, key))
            {
                cout << "Element found." << endl;
            }
            else
            {
                cout << "Element not found or List is Empty." << endl;
            }
            cout << endl;
            cout << endl;
            break;
        }

        case 12:
        {
            cout << endl;
            cout << endl;
            Node *ploc = nullptr, *loc = nullptr;
            int key;
            cout << "Enter the element to search: ";
            cin >> key;
            auxiliarySearch(&head, key, &ploc, &loc);
            if (loc != nullptr)
            {
                cout << "Element " << key << " found." << endl;
                if (ploc != nullptr && loc != nullptr)
                {
                    cout << "Previous element is " << ploc->data << "." << endl;
                    cout << "Searched Element is " << loc->data << "." << endl;
                }
                else
                {
                    cout << loc->data << " is at the head of the list." << endl;
                    cout << "Previous Element is absent ,and ploc's value is nullptr." << endl;
                }
            }
            else
            {
                cout << "Element " << key << " not found." << endl;
            }
            cout << endl;
            cout << endl;
            break;
        }
        case 13:
        {
            cout << endl;
            cout << endl;
            int key;
            cout << "Enter the element to search: ";
            cin >> key;
            if (searchInUnsortedList(&head, key) != nullptr)
            {
                Node *cur = searchInUnsortedList(&head, key);
                cout << "Element is:" << cur->data << endl;
                cout << "Element found." << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            cout << endl;
            cout << endl;
            break;
        }
        case 14:
        {
            cout << endl;
            cout << endl;
            reverseList(&head);
            cout << "Reverse List:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }

        case 15:
        {
            cout << endl;
            cout << endl;
            reverseListUsingStack(&head);
            cout << "Reverse List Using Stack:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 16:
        {
            cout << endl;
            cout << endl;
            reverseListUsingRecursion(&head);
            cout << "Reverse List Using Recursion:" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 17:
        {
            cout << endl;
            cout << endl;
            cout << "The length of the list is: " << lengthOfList(&head) << endl;
            cout << endl;
            cout << endl;
            break;
        }
        case 18:
        {
            cout << endl;
            cout << endl;
            cout << "Nth node from beginning , where 1 is the first node(1 based indexing):" << endl;
            int n;
            cout << "Enter the node: ";
            cin >> n;
            cout << "The " << n << "th node is from the beginning: " << getNthNode(&head, n) << endl;
            cout << endl;
            cout << endl;
            break;
        }

        case 19:
        {
            cout << endl;
            cout << endl;
            cout << "Nth node from beginning , where 0 is the first node(0 based indexing):" << endl;
            int n;
            cout << "Enter the node: ";
            cin >> n;
            if(getNthNode2(&head,n)==-1){

                cout <<"Error:Invalid Index" << endl;// When index is < 0 or > than length of linked list
                
            }
            else{
                cout << "The " << n << "th node is from the beginning: " << getNthNode2(&head, n) << endl;
            }
            cout << endl;
            cout << endl;
            break;
        }
        case 20:
        {
            cout << endl;
            cout << endl;
            cout << "Nth node from end , where 1 is the last node(1 based indexing):" << endl;
            int n;
            cout << "Enter the value of node: ";
            cin >> n;
            cout << "The " << n << "th node from the end is: " << getNthNodeFromEnd(&head, n) << endl;
            cout << endl;
            cout << endl;
            break;
        }
        case 21:
        {
            cout << endl;
            cout << endl;
            cout << "Nth node from end , where 0 is the last node(0 based indexing):" << endl;
            int n;
            cout << "Enter the value of node: ";
            cin >> n;
            cout << "The " << n << "th node from the end is: " << getNthNodeFromEnd2(&head, n) << endl;
            cout << endl;
            cout << endl;
            break;
        }
        case 22:
        {
            cout << endl;
            cout << endl;
            cout << "Traverse List In Order 1:(While Loop)" << endl;
            TraverseListInorder(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 23:
        {
            cout << endl;
            cout << endl;
            cout << "Traverse List In Order 2:(For Loop)" << endl;
            TraverseListInorder2(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 24:
        {
            cout << endl;
            cout << endl;
            cout << "Traverse List Reverse Order Iterative" << endl;
            TraverseListReverseOrderIterative(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 25: // This case is for traversing the list in reverse order
        {
            cout << endl;
            cout << endl;
            cout << "Traverse List Reverse Order Iterative Using Stack" << endl;
            TraverseListReverseOrderUsingStack(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 26:
        {
            cout << endl;
            cout << endl;
            cout << "Traverse List Reverse Order Recursive" << endl;
            TraverseListReverseOrderRecursive(&head);
            cout << endl;
            cout << endl;
            break;
        }
        case 27:
        {
            cout << endl;
            cout << endl;
            cout << "Destroying List....." << endl;
            destroyList(&head);
            cout << "List Destroyed." << endl;
            cout << endl;
            cout << endl;
            break;
        }

        case 28:
        {
            cout << endl;
            cout << endl;
            cout << "Exiting the program......" << endl;
            cout << endl;
            cout << endl;
            exit(0);
        }
        default:
        {
            cout << endl;
            cout << endl;
            cout << "Invalid choice." << endl;
            cout << endl;
            cout << endl;
            break;
        }
        }
    }

    return 0;
}