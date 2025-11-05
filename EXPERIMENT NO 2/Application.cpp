/* Sorting video in an App using Merge Sort*/

#include <iostream>
#include <vector>
using namespace std;


struct Video {
    string title;
    int views;
    float duration; 
};

void displayVideos(const vector<Video>& videos) {
    for (auto v : videos) {
        cout << v.title << " | Views: " << v.views
             << " | Duration: " << v.duration << " mins\n";
    }
    cout << endl;
}

// Merge two sorted halves
void merge(vector<Video>& videos, int left, int mid, int right) {
    vector<Video> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (videos[i].views >= videos[j].views)  // sort in descending order by views
            temp.push_back(videos[i++]);
        else
            temp.push_back(videos[j++]);
    }

    while (i <= mid) temp.push_back(videos[i++]);
    while (j <= right) temp.push_back(videos[j++]);

    for (int k = left; k <= right; k++)
        videos[k] = temp[k - left];
}

// Recursive merge sort
void mergeSort(vector<Video>& videos, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(videos, left, mid);
    mergeSort(videos, mid + 1, right);
    merge(videos, left, mid, right);
}

int main() {
    vector<Video> videos = {
        {"Travel Vlog", 8500, 12.5},
        {"Tech Review", 15000, 8.2},
        {"Cooking Tips", 5600, 5.0},
        {"Comedy Skit", 23000, 6.8},
        {"Music Video", 18000, 4.2},
        {"Short Film", 12000, 15.0}
    };

    cout << "🎥 Videos before sorting:\n";
    displayVideos(videos);

    // Sort videos by views (descending)
    mergeSort(videos, 0, videos.size() - 1);

    cout << "✅ Videos after sorting by views (most popular first):\n";
    displayVideos(videos);

    return 0;
}


