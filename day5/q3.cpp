#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find target indices after sorting
vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> result;

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Find the target indices
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int n, target;
    vector<int> nums;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    nums.resize(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    vector<int> result = targetIndices(nums, target);

    // Output the result
    if (!result.empty()) {
        cout << "Output: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    } else {
        cout << "Output: []" << endl;
    }

    return 0;
}
