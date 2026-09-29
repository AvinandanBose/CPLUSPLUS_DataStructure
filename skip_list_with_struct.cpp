#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

// Maximum level for this skip list.
// Level 3 means nodes can exist on levels 0, 1, 2, and 3.
#define MAX_LEVEL 3

// Node structure
struct Node {
  int key;
  // Array of pointers to next nodes, one for each level
  struct Node **forward;
};

// Skip List structure
struct SkipList {
  int level;           // Current maximum level in the list
  struct Node *header; // Pointer to the header node
};

// Function to generate a random level for a new node (probabilistic height)
int randomLevel() {
  int lvl = 0;
  // 50% probability to increase the level
  while ((rand() % 2) == 0 && lvl < MAX_LEVEL) {
    lvl++;
  }
  return lvl;
}

// Function to create a new node using malloc
struct Node *createNode(int key, int level) {
  // Allocate memory for the node
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->key = key;

  // Allocate memory for the forward pointer array (level + 1 elements)
  n->forward = (struct Node **)malloc(sizeof(struct Node *) * (level + 1));

  // Initialize pointers to NULL
  for (int i = 0; i <= level; i++) {
    n->forward[i] = NULL;
  }
  return n;
}

// Function to initialize the skip list
struct SkipList *createSkipList() {
  struct SkipList *lst = (struct SkipList *)malloc(sizeof(struct SkipList));
  lst->level = 0;

  // The header node doesn't store real data, so we use -1 as a placeholder.
  // It must have the maximum possible level.
  lst->header = createNode(-1, MAX_LEVEL);
  return lst;
}

// Insert a key into the skip list
void insertElement(struct SkipList *lst, int key) {
  struct Node *current = lst->header;

  // Array to keep track of the path we took (nodes needing pointer updates)
  struct Node *update[MAX_LEVEL + 1];
  memset(update, 0, sizeof(struct Node *) * (MAX_LEVEL + 1));

  // Start from the highest current level and move down
  for (int i = lst->level; i >= 0; i--) {
    while (current->forward[i] != NULL && current->forward[i]->key < key) {
      current = current->forward[i];
    }
    update[i] = current;
  }

  // Move to level 0 and look at the next node
  current = current->forward[0];

  // If the key doesn't already exist, insert it
  if (current == NULL || current->key != key) {
    int rlevel = randomLevel();

    // If the random level is greater than the list's current max level,
    // initialize the update array for the new levels to point to the header.
    if (rlevel > lst->level) {
      for (int i = lst->level + 1; i <= rlevel; i++) {
        update[i] = lst->header;
      }
      lst->level = rlevel;
    }

    // Create the new node and rewire pointers
    struct Node *n = createNode(key, rlevel);
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
void searchElement(struct SkipList *lst, int key) {
  struct Node *current = lst->header;

  // Traverse from highest level to the lowest
  for (int i = lst->level; i >= 0; i--) {
    while (current->forward[i] != NULL && current->forward[i]->key < key) {
      current = current->forward[i];
    }
  }

  // Step into the exact match at level 0
  current = current->forward[0];

  if (current != NULL && current->key == key) {
    cout << "Found key " << key << " in the Skip List." << endl;
  } else {
    cout << "Key " << key << " not found." << endl;
  }
}

// Delete a key from the skip list
void deleteElement(struct SkipList *lst, int key) {
  struct Node *current = lst->header;
  struct Node *update[MAX_LEVEL + 1];
  memset(update, 0, sizeof(struct Node *) * (MAX_LEVEL + 1));

  // Find the node, keeping track of pointers that point to it
  for (int i = lst->level; i >= 0; i--) {
    while (current->forward[i] != NULL && current->forward[i]->key < key) {
      current = current->forward[i];
    }
    update[i] = current;
  }

  current = current->forward[0];

  // If the target node is found
  if (current != NULL && current->key == key) {
    // Rewire the pointers to bypass the deleted node
    for (int i = 0; i <= lst->level; i++) {
      if (update[i]->forward[i] != current) {
        break; // If a level doesn't point to current, higher levels won't
               // either
      }
      update[i]->forward[i] = current->forward[i];
    }

    // Free memory using free()
    free(current->forward);
    free(current);

    // Reduce the maximum level of the list if layers become empty
    while (lst->level > 0 && lst->header->forward[lst->level] == NULL) {
      lst->level--;
    }
    cout << "Successfully deleted key " << key << endl;
  } else {
    cout << "Key " << key << " not found. Cannot delete." << endl;
  }
}

// Display the skip list layer by layer
void displayList(struct SkipList *lst) {
  cout << "\n--- Skip List ---" << endl;
  for (int i = 0; i <= lst->level; i++) {
    struct Node *node = lst->header->forward[i];
    cout << "Level " << i << ": ";
    while (node != NULL) {
      cout << node->key << " ";
      node = node->forward[i];
    }
    cout << endl;
  }
  cout << "-----------------" << endl;
}

// Function to completely destroy the skip list and free all memory
void destroyList(struct SkipList *lst) {
  // Start at the header
  struct Node *current = lst->header;
  struct Node *next;

  // We only need to traverse level 0 (the "local train" level)
  // because it is the only level guaranteed to contain EVERY node.
  while (current != NULL) {
    // 1. Save the pointer to the next node
    next = current->forward[0];

    // 2. Free the dynamically allocated array of pointers
    free(current->forward);

    // 3. Free the node itself
    free(current);

    // 4. Move to the next node
    current = next;
  }

  // Finally, free the main Skip List structure
  free(lst);
  cout << "Memory successfully freed. Skip List destroyed." << endl;
}

int main() {
  // Seed random number generator for random levels
  srand((unsigned)time(0));

  struct SkipList *list = createSkipList();
  int choice, key;

  while (true) {

    cout << "\n===== Skip List Menu =====" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Display" << endl;
    cout << "5. Destroy/Clear List" << endl; // New option
    cout << "6. Exit" << endl;               // Shifted down
    cout << "Enter your choice: ";

    if (!(cin >> choice)) {
      cout << "Invalid input. Exiting." << endl;
      break;
    }

    switch (choice) {
    case 1:
      cout << "Enter key to insert: ";
      cin >> key;
      insertElement(list, key);
      break;
    case 2:
      cout << "Enter key to delete: ";
      cin >> key;
      deleteElement(list, key);
      break;
    case 3:
      cout << "Enter key to search: ";
      cin >> key;
      searchElement(list, key);
      break;
    case 4:
      displayList(list);
      break;
    case 5:
      cout << "Destroying the current list..." << endl;
      destroyList(list);

      // CRITICAL: We must give the program a fresh, empty list
      // so it doesn't crash if the user tries to insert again.
      list = createSkipList();
      break;
    case 6:
      cout << "Exiting program..." << endl;
      destroyList(list); // Clean up before fully exiting
      return 0;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }
  return 0;
}

