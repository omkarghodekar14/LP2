#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

int mismatched(vector<vector<int>> &s)
{
    // Define logic to compute heuristic (e.g., number of misplaced tiles)
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[i][j] != 0 && s[i][j] != goal[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
struct puzzleNode
{
    vector<vector<int>> state;
    int blankRow, blankCol, movesSoFar, estimatedCost;
    string path = "";

    puzzleNode(int r, int c, int g, vector<vector<int>> s)
    {
        blankRow = r;
        blankCol = c;
        movesSoFar = g;
        estimatedCost = g + mismatched(s); // assumes mismatched() is defined
        state = s;
    }
};

struct mycomp
{
    bool operator()(puzzleNode &a, puzzleNode &b)
    {
        return a.estimatedCost > b.estimatedCost;
    }
};

string getKey(vector<vector<int>> &state)
{
    string key = "";

    for (auto &row : state)
    {
        for (int val : row)
        {
            key += to_string(val);
        }
    }

    return key;
}

bool isGoal(vector<vector<int>> &s)
{
    return goal == s;
}
// Placeholder for the mismatched function

bool isSafe(int r, int c)
{
    return r < 3 && r >= 0 && c < 3 && c >= 0;
}

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> directionNames = {"UP", "DOWN", "LEFT", "RIGHT"};

void puzzleSolve(vector<vector<int>> &state, int r, int c)
{
    priority_queue<puzzleNode, vector<puzzleNode>, mycomp> pq;
    unordered_set<string> visited;
    visited.insert(getKey(state));
    puzzleNode node(r, c, 0, state);
    pq.push(node);

    while (!pq.empty())
    {

        puzzleNode current = pq.top();
        pq.pop();

        if (isGoal(current.state))
        {
            cout << "Goal found in moves : " << current.movesSoFar << endl;
            return;
        }

        for (int d = 0; d < 4; d++)
        {
            int newr = current.blankRow + directions[d].first;
            int newc = current.blankCol + directions[d].second;

            if (isSafe(newr, newc))
            {

                vector<vector<int>> newState = current.state;
                swap(newState[current.blankRow][current.blankCol], newState[newr][newc]);
                string key = getKey(newState);
                if (!visited.count(key))
                {
                    visited.insert(key);
                    puzzleNode node(newr, newc, current.movesSoFar + 1, newState);
                    pq.push(node);
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> initialState = {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}};

    puzzleSolve(initialState, 1, 1);
    return 0;
}
