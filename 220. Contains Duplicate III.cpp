class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> win;
        for (int i = 0; i < nums.size(); i++) {
            auto it = win.lower_bound((long long)nums[i] - valueDiff);
            if (it != win.end() && abs(*it - nums[i]) <= valueDiff) {
                return true;
            }

            win.insert(nums[i]);

            if (i >= indexDiff) {
                win.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};



Question Link : https://leetcode.com/problems/contains-duplicate-iii//