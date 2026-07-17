class MedianFinder {
public:
    priority_queue<double> maxheap;
    priority_queue<double,vector<double>,greater<double>> minheap;
    double median;
    MedianFinder() {
        median=-1;
    }
    void addNum(int num) {
        if(maxheap.size()==minheap.size()){
            if(num>median){
                minheap.push(num);
                median=minheap.top();
            }
            else{
                maxheap.push(num);
                median=maxheap.top();
            }
        }
        else if(maxheap.size()>minheap.size()){
            if(num>median){
                minheap.push(num);
                median=(minheap.top()+maxheap.top())/2;
            }
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                median=(minheap.top()+maxheap.top())/2;
            }
        }
        else{
            if(num<median){
                maxheap.push(num);
                median=(minheap.top()+maxheap.top())/2;
            }
            else{
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
                median=(minheap.top()+maxheap.top())/2;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */