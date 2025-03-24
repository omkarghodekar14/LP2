#include<bits/stdc++.h>

using namespace std;

static bool comp(vector<int>&a, vector<int>&b) {
    return a[2] < b[2];
}

int find(int i, vector<int>& rank, vector<int>& parent) {

    if(i == parent[i]) {
        return parent[i];
    }

    return parent[i] = find(parent[i], rank, parent);
}

void Union(int u, int v, vector<int>& rank, vector<int>& parent) {

    int x_parent = find(u, rank, parent);
    int y_parent = find(v, rank, parent);

    if (x_parent == y_parent) 
        return;

    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

int kruskal(vector<vector<int>>& vec, vector<int>& rank, vector<int>& parent) {

    int sum = 0;
    for(auto it : vec) {

        int u = it[0];
        int v = it[1];
        int wt = it[2];

        int pV = find(v, rank, parent);
        int pU = find(u, rank, parent);

        if(pV != pU) {
            sum += wt;
            Union(v, u, rank, parent);
        }
    }

    return sum;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> vec;
    vector<int> rank(n, 0);
    vector<int> parent(n);

    for(int i = 0; i < n; i++) {

        int u , v , wt;
        parent[i] = i;
    
        cin >> u >> v >> wt;

        vec.push_back({u,v,wt});
    }

    sort(vec.begin(), vec.end(), comp);

    int sum = kruskal(vec, rank, parent);

    cout << sum ;
}


