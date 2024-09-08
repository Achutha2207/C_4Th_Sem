#include <iostream>
#include <vector>
#include <set> // Include set for unique sums
using namespace std;

// Function to print all subsets
void printAllSubsets(const vector<int>& vec) {
    int n = vec.size();
    int totalSubsets = 1 << n; // 2^n subsets

    cout << "All Subsets:" << endl;
    for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) {
        cout << "{ ";
        for (int i = 0; i < n; ++i) {
            if (subsetMask & (1 << i)) {
                cout << vec[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}

// Function to print unique subset sums
void printUniqueSubsetSums(const vector<int>& vec) {
    int n = vec.size();
    int totalSubsets = 1 << n;
    set<int> uniqueSums; // Set to store unique sums

    // Iterate through all subsets and calculate their sums
    for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (subsetMask & (1 << i)) {
                sum += vec[i];
            }
        }
        uniqueSums.insert(sum);
    }

    cout << "Unique Subset Sums: ";
    for (int sum : uniqueSums) {
        cout << sum << " ";
    }
    cout << endl;
}

// Function to find subsets that sum to the target
void findAndPrintSubsetsWithSum(const vector<int>& vec, int target) {
    vector<vector<int>> result;
    int n = vec.size();
    int totalSubsets = 1 << n;

    cout << "Subsets with sum " << target << ":" << endl;
    for (int subsetMask = 0; subsetMask < totalSubsets; ++subsetMask) {
        vector<int> subset;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (subsetMask & (1 << i)) {
                sum += vec[i];
                subset.push_back(vec[i]);
            }
        }
        if (sum == target) {
            cout << "{ ";
            for (int element : subset) {
                cout << element << " ";
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> vec(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> target;

    printAllSubsets(vec);
    printUniqueSubsetSums(vec);
    findAndPrintSubsetsWithSum(vec, target);

    return 0;
}

