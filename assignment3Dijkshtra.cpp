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

    vector<int> result(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    result[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (auto it : adj[u])
        {
            int distance = dist + it.second;

            if (result[it.first] > distance)
            {
                result[it.first] = distance;
                pq.push({distance, it.first});
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << result[i] << "  ";
    }
    cout << endl;

    return 0;
}