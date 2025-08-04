#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    bool Mountain_Array(vector<int>& arr){
        int n=arr.size();
        int peak=0;
        if(n<3)return false;
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                peak = i;
            }
        }
        for(int i=0; i<peak-1; i++){
            if(arr[i] >= arr[i+1]){
                return false;
            }
        }
        for(int i=peak; i<n-1; i++){
            if(arr[i]<= arr[i+1]){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 1};
    if(sol.Mountain_Array(arr)){
        cout << "The array is a mountain array." << endl;
    } else {
        cout << "The array is not a mountain array." << endl;
    }
    return 0;
}