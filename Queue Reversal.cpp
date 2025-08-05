// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        stack<int>st;
        while(!q.empty()){
            int x = q.front();
            st.push(x);
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        return q;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/queue-reversal/1?page=1&difficulty[]=-1&category[]=Queue&sortBy=submissions
