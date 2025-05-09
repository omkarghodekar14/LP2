#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to assign color c to vertex v
bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &color, int c)
{
    for (int neighbor : graph[v])
    {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

// Recursive backtracking coloring function
bool colorGraph(int v, const vector<vector<int>> &graph, vector<int> &color, int m)
{
    if (v == graph.size())
        return true; // All vertices colored

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (colorGraph(v + 1, graph, color, m))
                return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main()
{
    int v = 0, e = 0, m = 0;
    cout << "Enter the number of vertices:";
    cin >> v;
    cout << "Enter the number of edges:";
    cin >> e;

    cout << "Enter the number of colors: ";
    cin >> m;

    vector<vector<int>> adj(v);
    cout << "Enter edges:" << endl;
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    vector<int> color(v, 0);
    if (colorGraph(0, adj, color, m))
    {
        cout << "Graph coloring possible. Color assignment:\n";
        for (int i = 0; i < v; ++i)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
    else
    {
        cout << "No solution exists with " << m << " colors.\n";
    }

    return 0;
}
