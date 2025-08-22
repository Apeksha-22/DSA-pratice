class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size(), ans=-1;
        int l=1, r=1e7;

        while(l<=r){
            int mid = l + (r - l)/2;

            double hrs = 0;
            for(int i=0; i<n; i++){
                if(i == n-1)
                hrs += (double)dist[i]/mid;
                else
                hrs += ceil((double)dist[i]/mid);
            }
            if(hrs <= hour){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};


Question Link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time