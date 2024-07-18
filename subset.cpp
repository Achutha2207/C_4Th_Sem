#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSubset(const vector<string>& subset) {
    cout << "{ ";
    for (size_t i = 0; i < subset.size(); ++i) {
        cout << subset[i];
        if (i != subset.size() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

void findSubsets(const vector<int>& arr, vector<string>& subset, string current, int index) {
    if (index == arr.size()) {
        if (!current.empty()) {
            subset.push_back(current);
        }
        return;
    }

    // Exclude the current element and move to the next
    findSubsets(arr, subset, current, index + 1);

    // Include the current element and move to the next
    findSubsets(arr, subset, current + to_string(arr[index]), index + 1);
}

void generateSubsets(const vector<int>& arr) {
    vector<string> subset;
    findSubsets(arr, subset, "", 0);
    printSubset(subset);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "All possible subsets are:" << endl;
    generateSubsets(arr);

    return 0;
}

