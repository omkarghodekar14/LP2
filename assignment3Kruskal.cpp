#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool mycomp(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2];
}

vector<int> parent;

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return findParent(parent[x]); // This is Path compression
}
void unionSet(int X, int Z)
{
    int x = findParent(X);
    int y = findParent(Z);

    if (x == y)
        return;

    parent[x] = y;
}

int main()
{

    int v = 0, e = 0;

    cout << "Enter no of Vertices : ";
    cin >> v;
    cout << "Enter no of Edges : ";
    cin >> e;

    vector<vector<int>> edges;
    parent.resize(v);

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cout << "Enter source, Destination and weight : ";
        cin >> s >> d >> w;
        edges.push_back({s, d, w});
    }

    sort(edges.begin(), edges.end(), mycomp);

    int sum = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int parentu = findParent(u);
        int parentv = findParent(v);

        if (parentu != parentv)
        {
            unionSet(u, v);
            sum += w;
        }
    }

    cout << "Minimum Spanning Tree Cost: " << sum << endl;

    return 0;
}