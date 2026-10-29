#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent);
}

void kruskal(vector<Edge> edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0;
    cout << "\nMinimum Cost LAN Network:\n";

    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];

        int a = findParent(e.u, parent);
        int b = findParent(e.v, parent);

        if (a != b) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;
            parent[a] = b;
            cost += e.weight;
        }
    }

    cout << "Total Minimum Cost = " << cost << endl;
}

void dijkstra(vector<vector<int> > graph, int n,
              int source, int destination) {
    vector<int> dist(n, INT_MAX);
    vector<int> visited(n, 0);
    vector<int> previous(n, -1);

    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "\nNo path exists.\n";
        return;
    }

    vector<int> path;
    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = previous[current];
    }

    reverse(path.begin(), path.end());

    cout << "\nShortest Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1)
            cout << " -> ";
    }

    cout << "\nShortest Distance = "
         << dist[destination] << endl;
}

int main() {
    int n = 5;

    // 0 = Admin, 1 = Lab1, 2 = Lab2,
    // 3 = Library, 4 = Computer Center

    vector<Edge> edges;
    edges.push_back({0, 1, 4});
    edges.push_back({0, 2, 2});
    edges.push_back({1, 2, 1});
    edges.push_back({1, 3, 5});
    edges.push_back({2, 3, 8});
    edges.push_back({2, 4, 10});
    edges.push_back({3, 4, 2});

    vector<vector<int> > graph(n, vector<int>(n, 0));

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    cout << "College LAN Design\n";
    cout << "0=Admin, 1=Lab1, 2=Lab2\n";
    cout << "3=Library, 4=Computer Center\n";

    kruskal(edges, n);

    int source, destination;
    cout << "\nEnter source laboratory (0-4): ";
    cin >> source;

    cout << "Enter destination laboratory (0-4): ";
    cin >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {
        cout << "Invalid laboratory number!\n";
    } else {
        dijkstra(graph, n, source, destination);
    }

    return 0;
}
