#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}
int main() {
    int n, key, result;

    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    cout << "Enter element to search: ";
    cin >> key;

    result = binarySearch(arr, n, key);

    if (result == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at index " << result << "\n";

    delete[] arr;

    return 0;
}