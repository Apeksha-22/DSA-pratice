class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0, ans=-1, r=nums.size()-1;

        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m] == tar) return m;
            else if(nums[m] >= nums[0]){
                if(tar <= nums[m] && tar >= nums[0])
                r = m - 1;
                else l = m + 1;
            }else{
                if(tar <= nums[nums.size() - 1] && tar >= nums[m])
                l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};



Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array