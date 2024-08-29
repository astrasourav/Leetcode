class MedianFinder {
public:
    priority_queue<int>lh;//max heap
    priority_queue<int, vector<int>, greater<int>>rh;//min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lh.empty() || num < lh.top()) {
            lh.push(num); 
        } else {
            rh.push(num);
        }

        if (abs((int)lh.size() - (int)rh.size()) > 1) {
            rh.push(lh.top());
            lh.pop();
        } else if (lh.size() < rh.size()) {
            lh.push(rh.top());
            rh.pop();
        }
    }
    
    double findMedian() {
        if (lh.size() == rh.size()) {
            return (double)(lh.top() + rh.top())/2;
        } 

        return lh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
