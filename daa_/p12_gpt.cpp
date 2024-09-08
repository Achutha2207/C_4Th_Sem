#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Array to store input elements
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate the total number of subsets which is 2^n
    int totalSubsets = 1; // Starting with 2^0 = 1
    for (int i = 0; i < n; i++) {
        totalSubsets *= 2; // Equivalent to calculating 2^n iteratively
    }

    // Array to store the sums of all subsets
    int subsetSums[totalSubsets];
    int index = 0;

    // Generate each subset and calculate its sum
    for (int i = 0; i < totalSubsets; i++) {
        int sum = 0;

        // Iterate over each element to decide if it should be in the subset
        for (int j = 0; j < n; j++) {
            // Check if the j-th bit in i is set (i.e., include arr[j] in the subset)
            if ((i >> j) & 1) {
                sum += arr[j];
            }
        }

        // Store the sum of the current subset
        subsetSums[index++] = sum;
    }

    // Display the sums of all subsets
    cout << "Sums of all subsets: " <<endl;
    for (int i = 0; i < totalSubsets; i++) {
        cout << subsetSums[i] << " ";
    }
	cout<<endl;
    return 0;
}
