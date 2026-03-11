class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int>res(k-1,-1);
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<k;){
            pq.push(arr[i]);
            i++;
        }
        res.push_back(pq.top());
        for(int i=k; i<n; i++){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }if(pq.size() == k)res.push_back(pq.top());
        }
        return res;
    }
};





// 2nd Method
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int>res(k-1,-1);
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<=n; i++){
            if(pq.size() < k) pq.push(arr[i]);
            else{
                res.push_back(pq.top());
                if(arr[i] > pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        return res;
    }
};




Question Link : https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/