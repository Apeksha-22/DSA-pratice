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



Another Solution


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        if (tickets[k] == 1)
            return k + 1;

        while (tickets[k] > 0) {
            for (int i = 0; i < tickets.size(); i++) {
                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }
                if (tickets[k] == 0)
                return time;
            }
        }
        return time;
    }
};

Quetion link : https://leetcode.com/problems/time-needed-to-buy-tickets/
