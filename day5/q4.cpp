#include <iostream>
#include <vector>
using namespace std;

// Function to find the insert position or the index of the target
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    // If target is not found, left is the insert position
    return left;
}

int main() {
    int n, target;
    vector<int> nums;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    nums.resize(n);
    cout << "Enter the elements of the array (sorted in ascending order): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    int result = searchInsert(nums, target);

    cout << "Output: " << result << endl;

    return 0;
}
