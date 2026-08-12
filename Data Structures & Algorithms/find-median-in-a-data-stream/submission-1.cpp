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

        int ele =  minheap.top();
        if(num > ele){
            minheap.push(num);
        }
        else maxheap.push(num);

        if(minheap.size()+1 < maxheap.size()){
            int temp =  maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }

        if(maxheap.size()+1 < minheap.size()){
            int temp =  minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size()) return minheap.top()*1.0;
        else if(maxheap.size() > minheap.size()) return maxheap.top()*1.0;

        return ((minheap.top()+maxheap.top())/2.0);
    }
};
