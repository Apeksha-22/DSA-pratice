class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q;
        vector<int>res;
        for(int i=0; i<k-1; i++){
            while(!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(q.empty())q.push_back(i);
        }

        for(int i=k-1; i<n; i++){
            while(!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(q.front() <= i-k) q.pop_front();
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};


Question Link : https://leetcode.com/problems/sliding-window-maximum/description/