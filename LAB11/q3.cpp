#include <iostream>
#include <list>
#include <vector>
#include<algorithm>
using namespace std;

class HashTable {
private:
    vector<list<int>> table; 
    int size;                

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Function to insert a key
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Key " << key << " inserted at index " << index << ".\n";
    }

    // Function to delete a key
    void deleteKey(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        auto it = find(chain.begin(), chain.end(), key);

        if (it != chain.end()) {
            chain.erase(it);
            cout << "Key " << key << " deleted from index " << index << ".\n";
        } else {
            cout << "Key " << key << " not found.\n";
        }
    }

    // Function to search for a key
    void search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        auto it = find(chain.begin(), chain.end(), key);

        if (it != chain.end()) {
            cout << "Key " << key << " found at index " << index << ".\n";
        } else {
            cout << "Key " << key << " not found.\n";
        }
    }

    // Function to display the hash table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable hashTable(size);

    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                hashTable.deleteKey(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                hashTable.search(key);
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
