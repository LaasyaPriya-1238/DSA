#include <iostream>
#include <cstdlib> // for malloc, free

using namespace std;

class graph {
private:
    struct node {
        int data;
        struct node* next;
    } *list[9]; // Max 9 vertices

    int numvertices;

public:
    graph(int vertices) {
        if (vertices > 9) {
            cout << "Number of vertices entered greater than maxsize\n";
            vertices = 9;
        }
        numvertices = vertices;
        for (int i = 0; i < numvertices; i++) {
            list[i] = nullptr;
        }
    }

    int edgexists(int, int);
    int insert(int, int);
    int delete1(int, int);
    int search(int, int);
    void display();
};

int graph::edgexists(int src, int dest) {
    struct node* temp = list[src];
    while (temp) {
        if (temp->data == dest) {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

int graph::insert(int src, int dest) {
    if (src > 8 || dest > 8 || src < 0 || dest < 0) {
        cout << "Enter valid src and dest values\n";
        return -1;
    }

    struct node* newnode1 = (struct node*)malloc(sizeof(struct node));
    newnode1->data = dest;
    newnode1->next = list[src];
    list[src] = newnode1;

    struct node* newnode2 = (struct node*)malloc(sizeof(struct node));
    newnode2->data = src;
    newnode2->next = list[dest];
    list[dest] = newnode2;

    return 1;
}

int graph::delete1(int src, int dest) {
    if (src > 8 || dest > 8 || src < 0 || dest < 0) {
        cout << "Enter valid src and dest values\n";
        return -1;
    }

    if (edgexists(src, dest) == 1) {
        // Delete dest from src's list
        struct node* curr = list[src];
        struct node* prev = nullptr;
        while (curr) {
            if (curr->data == dest) {
                if (prev == nullptr)
                    list[src] = curr->next;
                else
                    prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // Delete src from dest's list
        curr = list[dest];
        prev = nullptr;
        while (curr) {
            if (curr->data == src) {
                if (prev == nullptr)
                    list[dest] = curr->next;
                else
                    prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Deletion successful\n";
        return 1;
    }

    cout << "Cannot perform deletion\nVertices not connected\n";
    return -1;
}

int graph::search(int src, int dest) {
    if (src > 8 || dest > 8 || src < 0 || dest < 0) {
        cout << "Enter valid src and dest values\n";
        return -1;
    }

    if (edgexists(src, dest) == 1) {
        cout << src << " and " << dest << " are connected\n";
        return 1;
    }

    cout << "No such edge exists\n";
    return -1;
}

void graph::display() {
    for (int i = 0; i < numvertices; i++) {
        cout << i << " -> ";
        struct node* temp = list[i];
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice, src, dest, vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph g1(vertices);

    while (1) {
        cout << "Enter 1 to insert\n";
        cout << "Enter 2 to delete\n";
        cout << "Enter 3 to search\n";
        cout << "Enter 4 to display\n";
        cout << "Enter 5 to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the src vertex to insert: ";
            cin >> src;
            cout << "Enter the dest vertex to insert: ";
            cin >> dest;
            g1.insert(src, dest);
            break;
        case 2:
            cout << "Enter the src vertex to delete: ";
            cin >> src;
            cout << "Enter the dest vertex to delete: ";
            cin >> dest;
            g1.delete1(src, dest);
            break;
        case 3:
            cout << "Enter the src vertex to search for: ";
            cin >> src;
            cout << "Enter the dest vertex to search for: ";
            cin >> dest;
            g1.search(src, dest);
            break;
        case 4:
            g1.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Enter valid choice\n";
        }

        cout << "\n";
    }

    return 0;
}
