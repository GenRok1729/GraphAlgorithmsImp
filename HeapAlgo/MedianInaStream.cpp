class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
public:
    
    
    //TC O(5logn) + 1;
    //SC O(n)
    
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() + large.top()) / 2.0;
    }
};
