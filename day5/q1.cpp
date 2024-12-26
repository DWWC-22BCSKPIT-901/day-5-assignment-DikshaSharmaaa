#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of k in the array
int findFirstOccurrence(int k, const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == k) {
            return i + 1; // 1-based indexing
        }
    }
    return -1; // Element not found
}

int main() {
    int k;
    vector<int> arr;
    int n;

    // Input size of array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    arr.resize(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value to search for: ";
    cin >> k;

    int result = findFirstOccurrence(k, arr);

    cout << "Output: " << result << endl;

    return 0;
}
