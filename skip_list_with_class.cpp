#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class SkipList {
private:
    // Maximum level for this skip list.
    static const int MAX_LEVEL = 3;

    // Node is now a STRICT C++ CLASS, nested securely inside SkipList
    class Node {
    public: // Must explicitly declare public so SkipList can access data
        int key;
        Node **forward;

        // Constructor handles node memory allocation via 'new'
        Node(int k, int level) {
            key = k;
            forward = new Node*[level + 1];
            for (int i = 0; i <= level; i++) {
                forward[i] = nullptr;
            }
        }

        // Destructor handles automatic array cleanup via 'delete[]'
        ~Node() {
            delete[] forward;
        }
    };

    int level;      // Current maximum level in the list
    Node *header;   // Pointer to the header node

    // Private helper function for probabilistic height
    int randomLevel() const {
        int lvl = 0;
        // 50% probability to increase the level
        while ((rand() % 2) == 0 && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

public:
    // Constructor initializes the Skip List
    SkipList() {
        level = 0;
        // Header node acts as a dummy root
        header = new Node(-1, MAX_LEVEL);
    }

    // Destructor completely destroys the list when the object goes out of scope
    ~SkipList() {
        clearList();
        delete header; 
    }

    // Insert a key into the skip list
    void insertElement(int key) {
        Node *current = header;

        // Temporary array for rewiring (Stack allocated)
        Node *update[MAX_LEVEL + 1];
        
        // Pure C++ initialization (Replacing C-style memset)
        for (int i = 0; i <= MAX_LEVEL; i++) {
            update[i] = nullptr;
        }

        // Find insertion point
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        // Insert if it doesn't already exist
        if (current == nullptr || current->key != key) {
            int rlevel = randomLevel();

            // Expand list level if the coin flip beat the current maximum
            if (rlevel > level) {
                for (int i = level + 1; i <= rlevel; i++) {
                    update[i] = header;
                }
                level = rlevel;
            }

            // Create new node and rewire pointers
            Node *n = new Node(key, rlevel);
            for (int i = 0; i <= rlevel; i++) {
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
            cout << "Successfully inserted key " << key << endl;
        } else {
            cout << "Key " << key << " already exists in the list." << endl;
        }
    }

    // Search for a key in the skip list
    void searchElement(int key) const {
        Node *current = header;

        // Traverse down the levels
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        if (current != nullptr && current->key == key) {
            cout << "Found key " << key << " in the Skip List." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    // Delete a key from the skip list
    void deleteElement(int key) {
        Node *current = header;
        Node *update[MAX_LEVEL + 1];
        
        // Pure C++ initialization (Replacing C-style memset)
        for (int i = 0; i <= MAX_LEVEL; i++) {
            update[i] = nullptr;
        }

        // Find the node and track the rewiring path
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        // If found, bypass and delete
        if (current != nullptr && current->key == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current) {
                    break; 
                }
                update[i]->forward[i] = current->forward[i];
            }

            // The Node destructor automatically deletes the dynamic forward array!
            delete current; 

            // Reduce max level if upper tracks become empty
            while (level > 0 && header->forward[level] == nullptr) {
                level--;
            }
            cout << "Successfully deleted key " << key << endl;
        } else {
            cout << "Key " << key << " not found. Cannot delete." << endl;
        }
    }

    // Display the skip list layer by layer
    void displayList() const {
        cout << "\n--- Skip List ---" << endl;
        for (int i = 0; i <= level; i++) {
            Node *node = header->forward[i];
            cout << "Level " << i << ": ";
            while (node != nullptr) {
                cout << node->key << " ";
                node = node->forward[i];
            }
            cout << endl;
        }
        cout << "-----------------" << endl;
    }

    // Clears all nodes (Option 5 in Menu)
    void clearList() {
        Node *current = header->forward[0];
        
        // Traverse level 0 and delete every node
        while (current != nullptr) {
            Node *next = current->forward[0];
            delete current; // Calls ~Node() automatically
            current = next;
        }

        // Reset the header to empty
        for (int i = 0; i <= MAX_LEVEL; i++) {
            header->forward[i] = nullptr;
        }
        level = 0;
        
        cout << "Memory successfully freed. Skip List cleared." << endl;
    }
};

int main() {
    // Seed random number generator
    srand((unsigned)time(0));

    // Instantiate the class as a standard stack object
    SkipList list; 
    int choice, key;

    while (true) {
        cout << "\n===== Skip List Menu =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Clear List" << endl; 
        cout << "6. Exit" << endl;       
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            list.insertElement(key);
            break;
        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            list.deleteElement(key);
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            list.searchElement(key);
            break;
        case 4:
            list.displayList();
            break;
        case 5:
            cout << "Clearing the current list..." << endl;
            list.clearList();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            // The list destructor is automatically called when main() returns.
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}