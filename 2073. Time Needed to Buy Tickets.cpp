class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int i=0,time=0;
        while(i<=k){
            time += min(tickets[k],tickets[i]);
            i++;
        }

        while(i<n){
            time += min(tickets[k]-1, tickets[i]);
            i++;
        }
        return time;
    }
};


Quetion link : https://leetcode.com/problems/time-needed-to-buy-tickets/
