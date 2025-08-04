class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k>q.size()) return q;
        queue<int>res;
        stack<int>st;
        int i=0;
        while(!q.empty() && i<k){
            st.push(q.front());
            q.pop();
            i++;
        }
        
        while(!st.empty()){
            res.push(st.top());
            st.pop();
        }
        
        while(!q.empty()){
            res.push(q.front());
            q.pop();
        }
        return res;
    }
};




Question link : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions
