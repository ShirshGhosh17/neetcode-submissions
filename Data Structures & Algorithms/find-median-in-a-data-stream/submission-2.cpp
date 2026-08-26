class MedianFinder {
public:

    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;

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
            int temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }      
        if(maxheap.size() > minheap.size()+1){
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
    }
    
    double findMedian() {
        if(minheap.size() > maxheap.size()) return minheap.top();
        else if(maxheap.size() > minheap.size()) return maxheap.top();
        else{
            return ((maxheap.top() + minheap.top())/2.0);
        }
    }
};
