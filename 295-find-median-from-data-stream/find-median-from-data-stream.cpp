class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > 0 && maxHeap.size() > 0) {
            if (maxHeap.top() > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        // if(minHeap.size()+1>maxHeap.size()) {
        //     maxHeap.push(minHeap.top());
        //     minHeap.pop();
        // }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */