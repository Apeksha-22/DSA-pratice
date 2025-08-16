class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flip = 0;
        deque<int>q;
        for(int i=0; i<n; i++){
            if(!q.empty() && i > q.front()) q.pop_front();

            if((q.empty() && nums[i] == 0) || (q.size() % 2 == nums[i])){
                if(i+k-1 >= n) return -1;
                flip++;
                q.push_back(i+k-1);
            }
            
        }
        return flip;
    }
};



Question Link : https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/