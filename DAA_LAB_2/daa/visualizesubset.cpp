#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

struct State {
    int index;
    int currentSum;
    vector<int> subset;
    int depth;  // Added to manage indentation for tree structure
};

void printBox(const string& title, const string& content, int depth) {
    int width = max(title.length(), content.length()) + 4;
    string indentation(depth * 4, ' ');  // Adjust indentation based on depth

    cout << indentation << "+" << string(width, '-') << "+\n";
    cout << indentation << "| " << setw(width - 2) << left << title << " |\n";
    cout << indentation << "|" << string(width, '-') << "|\n";
    cout << indentation << "| " << setw(width - 2) << left << content << " |\n";
    cout << indentation << "+" << string(width, '-') << "+\n";
}

void findSubsets(vector<int>& set, int target) {
    stack<State> stk;
    stk.push({0, 0, {}, 0});

    while (!stk.empty()) {
        State state = stk.top();
        stk.pop();

        if (state.index >= set.size() || state.currentSum > target)
            continue;

        // Exclude the current element (right branch)
        cout << "\n";
        printBox("Exclude", "Index: " + to_string(state.index + 1) + ", Sum: " + to_string(state.currentSum), state.depth);
        stk.push({state.index + 1, state.currentSum, state.subset, state.depth + 1});

        // Include the current element (left branch)
        state.subset.push_back(set[state.index]);
        cout << "\n";
        printBox("Include", "Index: " + to_string(state.index + 1) + ", Sum: " + to_string(state.currentSum + set[state.index]), state.depth);
        stk.push({state.index + 1, state.currentSum + set[state.index], state.subset, state.depth + 1});
    }
}

int main() {
    vector<int> set;
    int n;
    cout << "Enter No Of Elements" << endl;
    cin >> n;
    int input;
    cout << "Enter The Elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        set.push_back(input);
    }
    int target;
    cout << "Enter Sum" << endl;
    cin >> target;

    findSubsets(set, target);

    return 0;
}

