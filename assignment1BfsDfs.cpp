#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    cout << node << " ";
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, adj, visited);
        }
    }
}

void BFS(int startnode, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(startnode);
    visited[startnode] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    int v = 0, e = 0;
    cout << "Enter the number of vertices:";
    cin >> v;
    cout << "Enter the number of edges:";
    cin >> e;

    vector<vector<int>> adj(v);
    cout << "Enter edges:" << endl;
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    vector<bool> visitedDFS(v, false);
    cout << "DFS traversal:";
    DFS(0, adj, visitedDFS);

    cout << endl;

    vector<bool> visitedBFS(v, false);
    cout << "BFS traversal:";
    BFS(0, adj, visitedBFS);

    return 0;
}