class MedianFinder {
public:

    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty()){
            minheap.push(num);
            return;
        }

        int ele = minheap.top();
        if(num > ele){
            minheap.push(num);
        }
        else maxheap.push(num);

        if(minheap.size() > maxheap.size()+1){
            int val = minheap.top();
            minheap.pop();
            maxheap.push(val);
        }

        if(maxheap.size() > minheap.size()+1){
            int val = maxheap.top();
            maxheap.pop();
            minheap.push(val);
        }
    }
    
    double findMedian() {
        if(minheap.size() > maxheap.size()) return minheap.top();
        else if(maxheap.size() > minheap.size()) return maxheap.top();
        
        return (minheap.top()+maxheap.top())/2.0;
        
    }
};
