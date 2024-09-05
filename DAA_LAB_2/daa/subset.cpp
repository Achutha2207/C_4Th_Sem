#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void findSubsets(vector<int>& set, int target) {
    struct State {
        int index;
        int currentSum;
        vector<int> subset;
    };

    stack<State> stk;
    stk.push({0, 0, {}});

    while (!stk.empty()) {
        State state = stk.top();
        stk.pop();

        // Print current state
        cout << "Processing State: Index = " << state.index 
             << ", CurrentSum = " << state.currentSum 
             << ", Subset = { ";
        for (int num : state.subset)
            cout << num << " ";
        cout << "}\n";

        // Print stack
        cout << "Stack (Top to Bottom):\n";
        stack<State> temp = stk; // Copy the stack for safe iteration
        while (!temp.empty()) {
            State s = temp.top();
            temp.pop();
            cout << "\tIndex = " << s.index 
                 << ", CurrentSum = " << s.currentSum 
                 << ", Subset = { ";
            for (int num : s.subset)
                cout << num << " ";
            cout << "}\n";
        }
        cout << "-----------------------------\n";

        if (state.currentSum == target) {
            cout << "Found Subset: { ";
            for (int num : state.subset)
                cout << num << " ";
            cout << "}\n";
        }

        if (state.index >= set.size() || state.currentSum > target)
            continue;

        // Include the current element
        state.subset.push_back(set[state.index]);
        stk.push({state.index + 1, state.currentSum + set[state.index], state.subset});

        // Exclude the current element (backtracking)
        state.subset.pop_back();
        stk.push({state.index + 1, state.currentSum, state.subset});
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

