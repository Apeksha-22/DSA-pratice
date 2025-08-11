//USING MAP SC -> O(n) and TC -> O(n)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int a=-1;
        for(int i:nums){
            freq[i]++;
            if(freq[i] > n/2)  a = i;
        }
        return a;
    }
};


//USING BOYER MOORE VOTING ALGORITHM SC -> O(1) and TC -> O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), cnt=0, can;

        for(int i=0; i<n; i++){
            if(cnt == 0) can = nums[i];
            if(can == nums[i]) cnt++;
            else cnt--;
        }
        return can;
    }
};



Question Link : https://leetcode.com/problems/majority-element/description/