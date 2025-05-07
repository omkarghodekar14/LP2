#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Evaluation
{
private:
    string name;
    map<string, vector<float>> competencies;
    map<string, vector<float>> performance;

    void getInput(map<string, vector<float>> &section, const string &title, int &weightTotal)
    {
        cout << "\n--- " << title << " ---\n";
        for (auto &kv : section)
        {
            cout << "Enter rating for \"" << kv.first << "\" (1-3): ";
            cin >> kv.second[0];
            do
            {
                cout << "Enter weightage for \"" << kv.first << "\" (remaining: " << 100 - weightTotal << "): ";
                cin >> kv.second[1];
                if (kv.second[1] + weightTotal > 100)
                    cout << "⚠ Total weightage exceeded 100. Try again.\n";
            } while (kv.second[1] + weightTotal > 100);
            weightTotal += kv.second[1];
        }
    }

    void calculateScores(map<string, vector<float>> &section)
    {
        for (auto &kv : section)
        {
            kv.second[2] = kv.second[0] * kv.second[1] / 100.0;
        }
    }

    void printTable(const map<string, vector<float>> &section, const string &title)
    {
        cout << "\n--- " << title << " ---\n";
        cout << left << setw(20) << "Criteria" << setw(10) << "Rating" << setw(10) << "Weight" << setw(15) << "Weighted Score" << "\n";
        cout << string(55, '-') << "\n";
        for (const auto &kv : section)
        {
            cout << left << setw(20) << kv.first
                 << setw(10) << kv.second[0]
                 << setw(10) << kv.second[1]
                 << setw(15) << fixed << setprecision(2) << kv.second[2] << "\n";
        }
    }

    float totalScore(const map<string, vector<float>> &section)
    {
        float total = 0;
        for (const auto &kv : section)
            total += kv.second[2];
        return total;
    }

    string performanceLevel(float score)
    {
        if (score >= 2.7)
            return "🌟 Exceeds Expectations";
        else if (score >= 1.7)
            return "✅ Meets Expectations";
        else
            return "❌ Fails Expectations";
    }

public:
    Evaluation()
    {
        cout << "Enter employee name: ";
        getline(cin, name);

        competencies = {
            {"Communication", {0, 0, 0}},
            {"Productivity", {0, 0, 0}},
            {"Creativity", {0, 0, 0}},
            {"Integrity", {0, 0, 0}},
            {"Punctuality", {0, 0, 0}}};

        performance = {
            {"Target Achievement", {0, 0, 0}},
            {"Efficiency", {0, 0, 0}},
            {"Initiative", {0, 0, 0}},
            {"Team Goals", {0, 0, 0}},
            {"Deadline Adherence", {0, 0, 0}}};
    }

    void evaluate()
    {
        int totalWeight = 0;

        getInput(competencies, "Competency Evaluation", totalWeight);
        getInput(performance, "Performance Evaluation", totalWeight);

        if (totalWeight != 100)
        {
            cout << "\n⚠ Total weightage must be exactly 100. Evaluation aborted.\n";
            return;
        }

        calculateScores(competencies);
        calculateScores(performance);

        printTable(competencies, "Competency Results");
        printTable(performance, "Performance Results");

        float total = totalScore(competencies) + totalScore(performance);
        cout << "\n>>> Final Evaluation of " << name << " <<<\n";
        cout << "Total Score (out of 3.0): " << fixed << setprecision(2) << total << endl;
        cout << "Performance Level: " << performanceLevel(total) << "\n";
    }
};

int main()
{
    Evaluation e;
    e.evaluate();
    return 0;
}