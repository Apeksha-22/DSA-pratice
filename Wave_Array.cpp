//The array elements int the resultant array must be such that arr[o] >= arr[1] <= arr[2] >= arr[3] <= arr[4]....
//if there are multiple sorted orders in wave form, return the one which is lexicographically smallest.
//the array may contain duplicates.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void Wave_Array(vector<int>& arr){
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i+=2){
            if(i+1<n){
                swap(arr[i],arr[i+1]);
            }
        }
    }
};
int main(){
    Solution sol;
    vector<int> arr = {2, 1, 4, 3, 9, 6, 5, 8, 7};
    sol.Wave_Array(arr);
    for(int x : arr)
    cout << x << " ";
    cout << endl;
    return 0;
}