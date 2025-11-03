
#include <iostream>
#include <queue>
using namespace std;

int optimalMergeCost(int files[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    // Step 1: Insert all file sizes into min-heap
    for (int i = 0; i < n; i++)
        pq.push(files[i]);

    int totalCost = 0;

    // Step 2: Keep merging two smallest files
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int mergeCost = first + second;
        totalCost += mergeCost;

        pq.push(mergeCost);
    }

    return totalCost;
}

int main() {
    int files[] = {20, 30, 10, 5};
    int n = sizeof(files) / sizeof(files[0]);

    cout << "Minimum Total Merge Cost = " << optimalMergeCost(files, n) << endl;
    return 0;
}