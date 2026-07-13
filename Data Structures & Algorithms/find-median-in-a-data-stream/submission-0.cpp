class MedianFinder {
public:
    priority_queue<int,vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        if(max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() - min_heap.size() == 0){
            double temp = ( max_heap.top() + min_heap.top() ) / 2.0;
            return temp;
        } 
        if(max_heap.size() > min_heap.size()){
            return max_heap.top();
        }
        return min_heap.top();
        
        
    }
};
