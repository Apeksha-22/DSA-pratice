#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int Equilibrium_Indices(vector<int>& arr){
        int n=arr.size();
        int ans=-1;
        int sum1=0,sum=0;
        for(int x : arr)
        sum += x;
        for(int i=0; i<n; i++){
            (sum1 == sum - sum1 -arr[i]) ? ans = i : ans = -1;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, -3, -2, -1};
    cout << sol.Equilibrium_Indices(arr) << endl;
    return 0;
}
