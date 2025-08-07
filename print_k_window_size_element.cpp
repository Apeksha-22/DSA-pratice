#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
  public:
    void display(queue<int>q){
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }cout<<endl;
    }
    vector<int> printElements(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        queue<int>q;
        for(int i=0; i<k-1; i++){
            q.push(arr[i]);
        }
        
        for(int i = k-1; i<n; i++){
            q.push(arr[i]);
            display(q);
            q.pop();
        }
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, -2, 3, -4, 5};
    int k = 3;
    sol.printElements(arr, k);
    return 0;
}