#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int maxs=0;
        int curr=0;
        for(int x : arr){
            curr = max(x, curr + x);
            maxs = max(maxs, curr);
        }
        return maxs;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSumSubarray(arr);
    cout << "The maximum sum of a subarray is: " << result << endl;
    return 0;
}