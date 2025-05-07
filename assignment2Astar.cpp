#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

// Target goal state
vector<vector<int>> goalState = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

// Directions: up, down, left, right
vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<string> directionNames = {"UP", "DOWN", "LEFT", "RIGHT"};

// Misplaced tiles heuristic (Hamming distance)
int misplacedTiles(const vector<vector<int>> &state)
{
    int misplaced = 0;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            int value = state[row][col];
            if (value != 0 && value != goalState[row][col])
            {
                misplaced++;
            }
        }
    }
    return misplaced;
}

// Convert matrix to string key for hashing
string getStateKey(const vector<vector<int>> &state)
{
    string key;
    for (const auto &row : state)
        for (int val : row)
            key += to_string(val);
    return key;
}

// Puzzle node
struct PuzzleNode
{
    vector<vector<int>> state;
    int blankRow, blankCol;
    int movesSoFar;         // g(n)
    int estimatedTotalCost; // f(n) = g(n) + h(n)
    string moveSequence;

    PuzzleNode(vector<vector<int>> s, int r, int c, int g, string path)
    {
        state = s;
        blankRow = r;
        blankCol = c;
        movesSoFar = g;
        estimatedTotalCost = g + misplacedTiles(s); // Use misplacedTiles heuristic
        moveSequence = path;
    }
};

// Custom comparator for min-heap (based on f(n) = g(n) + h(n))
struct ComparePuzzleNode
{
    bool operator()(const PuzzleNode &a, const PuzzleNode &b)
    {
        return a.estimatedTotalCost > b.estimatedTotalCost;
    }
};

// Check if a position is valid
bool isValidPosition(int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3;
}

// Check if current state is goal
bool isGoalState(const vector<vector<int>> &state)
{
    return state == goalState;
}

// A* Search
void solvePuzzle(const vector<vector<int>> &startState, int startRow, int startCol)
{
    // Priority queue (min-heap based on f(n))
    priority_queue<PuzzleNode, vector<PuzzleNode>, ComparePuzzleNode> openList;
    unordered_set<string> visited;

    PuzzleNode start(startState, startRow, startCol, 0, "");
    openList.push(start);
    visited.insert(getStateKey(startState));

    while (!openList.empty())
    {
        PuzzleNode current = openList.top();
        openList.pop();

        if (isGoalState(current.state))
        {
            cout << "Solved in " << current.movesSoFar << " moves.\n";
            cout << "Moves:" << current.moveSequence << endl;
            return;
        }

        for (int d = 0; d < 4; ++d)
        {
            int newRow = current.blankRow + directions[d].first;
            int newCol = current.blankCol + directions[d].second;

            if (isValidPosition(newRow, newCol))
            {
                vector<vector<int>> newState = current.state;
                swap(newState[current.blankRow][current.blankCol], newState[newRow][newCol]);

                string newKey = getStateKey(newState);
                if (!visited.count(newKey))
                {
                    visited.insert(newKey);
                    string newPath = current.moveSequence + " " + directionNames[d];
                    PuzzleNode next(newState, newRow, newCol, current.movesSoFar + 1, newPath);
                    openList.push(next);
                }
            }
        }
    }

    cout << "No solution found.\n";
}

int main()
{
    // You can change the initial state here
    vector<vector<int>> initialState = {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}};

    int blankRow = 1, blankCol = 2; // Position of blank (0)

    solvePuzzle(initialState, blankRow, blankCol);

    return 0;
}
