#include "util.hpp"

class MedianFinder {
private:
    int n;
    int first;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    MedianFinder() : n(0), minHeap(), maxHeap() { }

    // Adds a number into the data structure.
    void addNum(int num) {
        n++;
        if (n == 1)
            first = num;
        else if (n == 2) {
            if (first > num)
                swap(first, num);
            maxHeap.push(first);
            minHeap.push(num);
        } else {
            if (num <= maxHeap.top())
                maxHeap.push(num);
            else
                minHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        cout << maxHeap.size() << ' ' << minHeap.size() << endl;
    }

    // Returns the median of current data stream
    double findMedian() {
        if (n == 1) return first;

        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) * 0.5;
        else if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};

int main() {
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    finder.addNum(3);
    finder.addNum(4);
    cout << finder.findMedian() << endl;
}
