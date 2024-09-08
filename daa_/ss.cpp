#include <iostream>
#include <vector>
#include <stack>
#include <set>        // Include for std::set
#include <algorithm>  // Include for std::sort

using namespace std;

void findSubsets(vector<int>& set, int target) {
    struct State {
        int index;
        int currentSum;
        vector<int> subset;
    };

    stack<State> stk;
    stk.push({0, 0, {}});

    std::set<std::vector<int>> uniqueSubsets;  // Correct syntax with proper spacing

//    set< vector<int> > uniqueSubsets;  // Set to store unique subsets

    while (!stk.empty()) {
        State state = stk.top();
        stk.pop();

        if (state.currentSum == target) {
            // Sort subset before inserting to handle duplicates due to different orderings
            vector<int> sortedSubset = state.subset;
            sort(sortedSubset.begin(), sortedSubset.end());

            if (uniqueSubsets.find(sortedSubset) == uniqueSubsets.end()) {
                uniqueSubsets.insert(sortedSubset);

                cout << "{ ";
                for (int num : sortedSubset)
                    cout << num << " ";
                cout << "}" << endl;
            }
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

