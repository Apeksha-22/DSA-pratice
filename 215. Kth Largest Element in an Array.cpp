class Solution {
public:
    int partion(vector<int>& nums, int l, int r){
        int tar = nums[r];//take last element

        int i=l;
        for(int j=l; j<r; j++){
            if(nums[j] > tar){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);//correct pos of pivot element
        return i;//pivot idx
    }
    void QuickSelect(vector<int>& nums, int l, int r, int k){
        if(l>=r) return;
        int pvtidx = partion(nums, l, r);
        if(pvtidx == k) return;
        else if(pvtidx < k)
        QuickSelect(nums, pvtidx + 1, r, k);
        else
        QuickSelect(nums, l, pvtidx - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int tar=k-1;
        QuickSelect(nums, 0, n - 1, tar);
        int x = nums[tar];
        return x;
    }
};



Question Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/