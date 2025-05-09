#include <bits/stdc++.h>

using namespace std;
int main()
{

    int v = 0, e = 0;

    cout << "Enter no of Vertices : ";
    cin >> v;
    cout << "Enter no of Edges : ";
    cin >> e;

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cout << "Enter source, Destination and weight : ";
        cin >> s >> d >> w;
        adj[s].push_back(make_pair(d, w));
        adj[d].push_back(make_pair(s, w));
    }

    vector<bool> inMst(v, false);
    vector<bool> parent(v);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMst[u] == true)
        {
            continue;
        }

        inMst[u] = true;
        sum += w;

        for (auto it : adj[u])
        {
            int neighbour = it.first;
            int wt = it.second;

            if (inMst[neighbour] == false)
            {
                pq.push({wt, neighbour});
            }
        }
    }

    cout << "Minimum Spanning Tree Cost: " << sum << endl;

    return 0;
}