class MedianFinder {
public:
    priority_queue<int>maxHp;
    priority_queue<int,vector<int>,greater<int>>minHp;

    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHp.empty() || num<maxHp.top()){
            maxHp.push(num);
        } else{
            minHp.push(num);
        }
        
        if(abs((int)maxHp.size()-(int)minHp.size())>1){
            minHp.push(maxHp.top());
            maxHp.pop();
        } else if(maxHp.size()<minHp.size()){
            maxHp.push(minHp.top());
            minHp.pop();
        }
    }
    
    double findMedian() {
        if(maxHp.size()==minHp.size()){
            return (double)(maxHp.top()+minHp.top())/2;
        }
        
        return maxHp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 Question Link : https://leetcode.com/problems/find-median-from-data-stream/