#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 5;

void bfs(int adjList[][MAX_VERTICES], int vertices, int startNode) {
    bool visited[MAX_VERTICES] = {false};

    int q[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startNode] = true;
    q[++rear] = startNode;

    while (front <= rear) {
        int currentNode = q[front++];
        cout << currentNode << " ";

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (adjList[currentNode][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                q[++rear] = neighbor;
            }
        }
    }
}

void addEdge(int adjList[][MAX_VERTICES], int u, int v) {
    adjList[u][v] = 1;
}

int main() {
    int vertices = 5;

    int adjList[MAX_VERTICES][MAX_VERTICES] = {0};

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    cout << "Breadth First Traversal starting from vertex 0: ";
    bfs(adjList, vertices, 0);

    return 0;
}
