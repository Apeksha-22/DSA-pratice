#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution{
    public:
    int flipGame(vector<int>&arr){
        int n=arr.size();
        int tl_1s = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                arr[i] = -1;
                tl_1s++;
            }
            else arr[i] = 1;
        }
        int curr = 0;
        int maxF=INT_MIN;
        for(int x : arr){
            curr = max(x, curr+x);
            maxF = max(maxF, curr);
        }
        return tl_1s + maxF;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1,0,0,1,0};
    int result = sol.flipGame(arr);
    cout << "The maximum number of 1s after flipping is: " << result << endl;
    return 0;
}