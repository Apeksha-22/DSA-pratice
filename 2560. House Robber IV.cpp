class Solution {
public:
	bool chck(vector<int>& nums, int k, int n){
        int i=0;
        int cnt=0;
        while(i<nums.size()){
            if(nums[i] <= n){
                cnt++;
                i +=2;
            }else i++;

            if(cnt >= k) return true;
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        while(l<h){
            int mid = (h + l)/2;
            if(chck(nums,k,mid))h = mid;
            else l = mid + 1;
        }
    	return l;
    }
};
  
Question Link: https: https://leetcode.com/problems/house-robber-iv/description/
