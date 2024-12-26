#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to perform relative sort
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> rank;

    // Assign rank based on arr2's order
    for (int i = 0; i < arr2.size(); ++i) {
        rank[arr2[i]] = i;
    }

    // Custom comparator for sorting
    auto comparator = [&rank](int a, int b) {
        if (rank.count(a) && rank.count(b)) {
            return rank[a] < rank[b]; // Both in arr2, sort by rank
        } else if (rank.count(a)) {
            return true; // a is in arr2 but b is not
        } else if (rank.count(b)) {
            return false; // b is in arr2 but a is not
        } else {
            return a < b; // Neither in arr2, sort ascending
        }
    };

    sort(arr1.begin(), arr1.end(), comparator);

    return arr1;
}

int main() {
    int n1, n2;
    vector<int> arr1, arr2;

    // Input size of arr1
    cout << "Enter the number of elements in arr1: ";
    cin >> n1;
    arr1.resize(n1);
    cout << "Enter the elements of arr1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }

    // Input size of arr2
    cout << "Enter the number of elements in arr2: ";
    cin >> n2;
    arr2.resize(n2);
    cout << "Enter the elements of arr2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }

    vector<int> result = relativeSortArray(arr1, arr2);

    // Output the result
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
