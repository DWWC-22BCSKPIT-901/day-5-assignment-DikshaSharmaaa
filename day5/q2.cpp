#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to search for k in a sorted array using binary search
bool binarySearch(const vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == k) {
            return true; // Element found
        } else if (arr[mid] < k) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // Element not found
}

int main() {
    int n, k;
    vector<int> arr;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    arr.resize(n);
    cout << "Enter the elements of the array (sorted in ascending order): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value to search for: ";
    cin >> k;

    bool result = binarySearch(arr, k);

    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
