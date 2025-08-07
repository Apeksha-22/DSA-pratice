class Solution {
  public:
    int chck(queue<int>q){
        while(!q.empty()){
            if(q.front() < 0)
            return q.front();
            q.pop();
        }
        return 0;
    }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        queue<int>q;
        vector<int>res;
        for(int i=0; i<k-1; i++){
            if(arr[i] < 0)
            q.push(i);
        }
        
        for(int i = k-1; i<n; i++){
            if(arr[i]<0){
                q.push(i);
            }
            if(q.empty()){
                res.push_back(0);
            }else{
                if(q.front() <= i-k){
                    q.pop();
                }if(q.empty()){
                    res.push_back(0);
                }else{
                    res.push_back(arr[q.front()]);
                }
            }
        }
        return res;
    }
};



Question link: https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
