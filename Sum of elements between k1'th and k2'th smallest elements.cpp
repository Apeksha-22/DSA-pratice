class Solution {
  public:
    long long maxHeap(long long A[], long long n, long long k){
        priority_queue<long long>pq;
        long long sum=0;
        
        for(int i=0; i<n; i++){
            if(pq.size() < k)pq.push(A[i]);
            else{
                if(A[i] < pq.top()){
                    pq.pop();
                    pq.push(A[i]);
                }
            }
        }
        
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        return maxHeap(A, N, K2-1) - maxHeap(A, N, K1);
    }
};



Question Link : https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133