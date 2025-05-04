#include <iostream>
#include <vector>
using namespace std;

#define INF 9999999

class graph {
private:
    int v;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> edge;

public:
    graph(int vertices) : v(vertices) {
        adj.resize(v);
    }

    int addedge(int, int, int);
    int prims();
    int findparent(vector<int>& parent, int u);
    int kruskals();
    int dijkstra(int src);
};

int graph::addedge(int u, int V, int w) {
    if (u >= v || V >= v || u < 0 || V < 0) {
        cout << "Invalid vertex\n";
        return 0;
    }
    adj[u].push_back(make_pair(V, w));
    adj[V].push_back(make_pair(u, w));
    edge.push_back({w, u, V});  // storing edge as {weight, u, v}
    return 1;
}

int graph::prims() {
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);
    vector<int> key(v, INF);
    key[0] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = -1;
        int min_key = INF;
        for (int i = 0; i < v; i++) {
            if (!visited[i] && key[i] < min_key) {
                min_key = key[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int neighbor = adj[u][i].first;
            int weight = adj[u][i].second;
            if (!visited[neighbor] && weight < key[neighbor]) {
                key[neighbor] = weight;
                parent[neighbor] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < v; i++) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << "\n";
    }

    return 1;
}

int graph::findparent(vector<int>& parent, int u) {
    if (parent[u] != u)
        parent[u] = findparent(parent, parent[u]);
    return parent[u];
}

int graph::kruskals() {
    // Bubble sort edges by weight
    for (int i = 0; i < edge.size(); i++) {
        for (int j = i + 1; j < edge.size(); j++) {
            if (edge[i][0] > edge[j][0]) {
                swap(edge[i], edge[j]);
            }
        }
    }

    vector<int> parent(v);
    for (int i = 0; i < v; i++)
        parent[i] = i;

    vector<pair<int, int>> mst;
    for (int i = 0; i < edge.size(); i++) {
        int w = edge[i][0];
        int u = edge[i][1];
        int vv = edge[i][2];

        int pu = findparent(parent, u);
        int pv = findparent(parent, vv);

        if (pu != pv) {
            mst.push_back(make_pair(u, vv));
            parent[pu] = pv;
        }
    }

    cout << "Kruskal's MST:\n";
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].first << " - " << mst[i].second << "\n";
    }

    return 1;
}

int graph::dijkstra(int src) {
    if (src >= v || src < 0) {
        cout << "Invalid source vertex\n";
        return -1;
    }

    vector<int> dist(v, INF);
    vector<bool> visited(v, false);
    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = -1;
        int min_dist = INF;

        for (int i = 0; i < v; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int neighbor = adj[u][i].first;
            int weight = adj[u][i].second;

            if (!visited[neighbor] && dist[u] + weight < dist[neighbor]) {
                dist[neighbor] = dist[u] + weight;
            }
        }
    }

    cout << "Shortest distances from " << src << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "To " << i << " = ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 1;
}

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    graph g1(vertices);

    while (1) {
        int choice;
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Prim's MST\n";
        cout << "3. Kruskal's MST\n";
        cout << "4. Dijkstra's Shortest Path\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g1.addedge(u, v, w);
                break;
            }
            case 2:
                g1.prims();
                break;
            case 3:
                g1.kruskals();
                break;
            case 4: {
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                g1.dijkstra(src);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
