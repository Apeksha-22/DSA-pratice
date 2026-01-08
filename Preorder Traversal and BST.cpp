// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int>lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left, right, idx=0;
        for(int i=0; i<N; i++){
            if(arr[i] <= lower.top()) return 0;
            while(arr[i] >= upper.top()){
                lower.pop();
                upper.pop(); 
            }
            left = lower.top();
            right = upper.top();
            lower.pop(), upper.pop();
            lower.push(arr[i]);
            upper.push(right);
            lower.push(left);
            upper.push(arr[i]);
            idx++;
        }
        return idx == N;
    }
};





// sometimes it give runtime error because of meemory issue in case of recursion
// its use stack memory but whenever we use stack its use heap memory so
// stack don't give error but recursion can give due to memory overflow
class Solution {
  public:
    void chck(int arr[], int& idx, int lower, int upper, int N){
        if(idx == N || arr[idx] <= lower || arr[idx] >= upper)
        return;
        
        int val = arr[idx++];
        chck(arr,idx,lower,val,N);
        chck(arr,idx,val,upper,N);
    }
    int canRepresentBST(int arr[], int N) {
        // code here
        int idx = 0;
        chck(arr, idx, INT_MIN, INT_MAX, N);
        return idx == N;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1