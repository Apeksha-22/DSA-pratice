class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int last = INT_MIN, ans = 0, cnt = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] - 1 == last) {
                cnt++;
                last = a[i];
            } else if(a[i] != last) {
                cnt = 1;
                last = a[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};



Question Link : https://leetcode.com/problems/longest-consecutive-sequence/