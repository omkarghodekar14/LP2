#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort by profit descending
static bool mycomp(const vector<int> &a, const vector<int> &b)
{
    return a[2] > b[2];
}

pair<vector<int>, int> jobSequencing(vector<vector<int>> &jobs)
{
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), mycomp);

    int maxDeadline = 0;
    for (auto &job : jobs)
    {
        maxDeadline = max(maxDeadline, job[1]); // job[1] = deadline
    }

    vector<bool> slot(maxDeadline + 1, false);
    vector<int> scheduledJobs;
    int totalProfit = 0;

    for (auto &job : jobs)
    {
        int id = job[0];
        int deadline = job[1];
        int profit = job[2];

        // Find a free time slot before or at deadline
        for (int j = deadline; j > 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                scheduledJobs.push_back(id);
                totalProfit += profit;
                break;
            }
        }
    }

    return {scheduledJobs, totalProfit};
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<vector<int>> jobs;
    cout << "Enter deadline and profit for each job:\n";
    for (int i = 0; i < n; i++)
    {
        int d, p;
        cin >> d >> p;
        jobs.push_back({i + 1, d, p}); // ID = i+1
    }

    auto [selectedJobs, totalProfit] = jobSequencing(jobs);

    cout << "\nSelected Job IDs: ";
    for (int id : selectedJobs)
        cout << id << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
