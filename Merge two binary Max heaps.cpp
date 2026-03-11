// User function Template for C++

class Solution {
  public:
    void heapify(vector<int>&a, int idx, int n){
        int largest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        
        if(left < n && a[largest] < a[left])
        largest = left;
        if(right < n && a[largest] < a[right])
        largest = right;
        
        if(largest != idx){
            swap(a[largest] , a[idx]);
            heapify(a, largest, n);
        }
    }
    void maxHeap(vector<int>& a, int n){
        for(int i=n/2 - 1; i>=0; i--)
        heapify(a, i, n);
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        for(int i : b)
        a.push_back(i);
        
        maxHeap(a, n+m);
        return a;
    }
};




Question Link : https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/