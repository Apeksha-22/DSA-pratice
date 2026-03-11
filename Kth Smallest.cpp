class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        
        for(int i=0; i < arr.size(); i++){
            if(pq.size() < k)
            pq.push(arr[i]);
            
            else{
                if(arr[i] < pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        return pq.top();
    }
};


Question Link : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/