
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int>res(n,0);
        stack<int>st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int idx=st.top();
                st.pop();
                int rng=-1;
                if(st.empty())
                rng=i;
                else
                rng=i-st.top()-1;
                
                res[rng-1] = max(res[rng-1],arr[idx]);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int idx=st.top();
            st.pop();
            int rng=-1;
            if(st.empty())
            rng=n;
            else
            rng=n-st.top()-1;
            
            res[rng-1] = max(res[rng-1],arr[idx]);
        }
        
        for(int i=n-1; i>0; i--){
            res[i-1] = max(res[i],res[i-1]);
        }
        return res;
    }
};

question link https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions
