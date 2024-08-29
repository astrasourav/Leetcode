#include <bits/stdc++.h>
using namespace std;

// Function to swap elements in a vector
void swap(vector<int>& arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// Function to find the minimum number of swaps required to sort the array
int minSwaps(int arr[], int n) {
    vector<int> tmp(n);  // Initialize vector with size n
    unordered_map<int, int> mpp;

    int cnt = 0;

    // Fill the temporary vector and the map with array values
    for (int i = 0; i < n; i++) {
        tmp[i] = arr[i];
        mpp[arr[i]] = i;
    }

    sort(tmp.begin(), tmp.end());  // Sort the temporary vector

    // Traverse through the original array
    for (int i = 0; i < n; i++) {
        // If the element is not at the correct position
        if (arr[i] != tmp[i]) {
            cnt++;

            // Element to be swapped with
            int a = arr[i];

            // Perform the swap
            swap(arr, i, mpp[tmp[i]]);

            // Update the map after swapping
            mpp[a] = mpp[tmp[i]];
            mpp[tmp[i]] = i;
        }
    }

    return cnt;  // Return the number of swaps
}

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of swaps required: " << minSwaps(arr, n) << endl;
    return 0;
}

