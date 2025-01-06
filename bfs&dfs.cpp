#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int u) {
    
    if(visited[u] == true)
        return;
    
    visited[u] = true;
    cout << u << " ";
    
    for(auto v : adj[u]) {
        
        if(!visited[v]) {
            dfs(adj, visited, v);
        }
    }
}

int main(){

    int n;
    cout << "Enter the no of edges : ";
    cin >> n;
    
    vector<pair<int, int>> edges(n);

    
    unordered_map<int, vector<int>> adj;
    
    for(int i = 0; i < n; i++) {
        
        cin >> edges[i].first >> edges[i].second;
    }
    
    for(auto it : edges) {
        int u = it.first;
        int v = it.second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    vector<bool> visited(n, false);
    vector<int> result;
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    cout << "BFS traversal " << endl;
    
    while(!q.empty()) {
        
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for(auto v : adj[u]) {
            
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    
    cout << endl << endl;
    
    cout << "DFS traversal " << endl;
    
    fill(visited.begin(), visited.end(), false);
    
    dfs(adj, visited, 0);
    
}