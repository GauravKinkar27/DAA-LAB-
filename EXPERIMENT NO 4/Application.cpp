// Video Streaming Services as a real-life application of the Greedy Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct VideoSegment {
    string name;
    double size;        // in MB
    double importance;  // based on popularity or viewing probability
};

bool cmp(VideoSegment a, VideoSegment b) {
    double r1 = a.importance / a.size;
    double r2 = b.importance / b.size;
    return r1 > r2;
}

double bufferVideo(vector<VideoSegment>& segments, double bandwidth) {
    sort(segments.begin(), segments.end(), cmp);
    double totalSize = 0.0, totalImportance = 0.0;

    cout << "\n🎥 Segments Buffered:\n";

    for (auto& seg : segments) {
        if (totalSize + seg.size <= bandwidth) {
            totalSize += seg.size;
            totalImportance += seg.importance;
            cout << "- " << seg.name << " (Fully Loaded)\n";
        } else {
            double remain = bandwidth - totalSize;
            double fraction = remain / seg.size;
            totalImportance += seg.importance * fraction;
            cout << "- " << seg.name << " (Partially Loaded: " << fraction * 100 << "%)\n";
            break;
        }
    }

    cout << "\n💾 Total Data Used: " << totalSize << " MB\n";
    return totalImportance;
}

int main() {
    vector<VideoSegment> segments = {
        {"Intro", 50, 70},
        {"Main Scene 1", 100, 120},
        {"Main Scene 2", 120, 150},
        {"Ending", 60, 80}
    };

    double bandwidth;
    cout << "Enter available buffering bandwidth (in MB): ";
    cin >> bandwidth;

    double totalValue = bufferVideo(segments, bandwidth);

    cout << "\n⚙️ Streaming Quality Score (Utility): " << totalValue << "\n";
    return 0;
}
