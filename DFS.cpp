
#include <iostream>
#include <stack>

using namespace std;

const int MAX_VERTICES = 5;

void DFS(int adjList[][MAX_VERTICES], int vertices, int startNode) {
    bool visited[MAX_VERTICES] = {false};

    stack<int> stack;

    stack.push(startNode);
    visited[startNode] = true;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        cout << current << " ";

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (adjList[current][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
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

    cout << "Depth First Traversal starting from vertex 0: ";
    DFS(adjList, vertices, 0);

    return 0;
}
