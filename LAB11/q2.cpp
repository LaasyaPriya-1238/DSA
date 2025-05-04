
#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> isOccupied;
    int size;

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, -1);
        isOccupied.resize(size, false);
    }

    void insert(int key);
    void deleteKey(int key);
    void search(int key);
    void display();
};
int main() {
    int size, choice, key;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable h(size);

    do {
        cout << "\nMenu:\n";
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
                h.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                h.deleteKey(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                h.search(key);
                break;
            case 4:
                h.display();
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
void HashTable::insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    while (isOccupied[index]) {
        if (table[index] == key) {
            cout << "Key " << key << " already exists in the table.\n";
            return;
        }
        index = (originalIndex + i * i) % size;
        i++;
        if (i > size) {
            cout << "Hash table is full! Cannot insert key " << key << ".\n";
            return;
        }
    }

    table[index] = key;
    isOccupied[index] = true;
    cout << "Key " << key << " inserted.\n";
}

void HashTable::deleteKey(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    while (isOccupied[index]) {
        if (table[index] == key) {
            table[index] = -1;
            isOccupied[index] = false;
            cout << "Key " << key << " deleted.\n";
            return;
        }
        index = (originalIndex + i * i) % size;
        i++;
        if (i > size) {
            break;
        }
    }
    cout << "Key " << key << " not found.\n";
}

void HashTable::search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    while (isOccupied[index]) {
        if (table[index] == key) {
            cout << "Key " << key << " found at index " << index << ".\n";
            return;
        }
        index = (originalIndex + i * i) % size;
        i++;
        if (i > size) {
            break;
        }
    }
    cout << "Key " << key << " not found.\n";
}

void HashTable::display() {
    cout << "Hash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << i << " : " << (isOccupied[i] ? to_string(table[i]) : "EMPTY") << "\n";
    }
}