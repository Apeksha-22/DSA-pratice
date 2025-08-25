// 118. Pascal's Triangle



class Solution {
public:
    int c(int n, int r){
        if(r>n) return 0;
        int res=1;
        for(int i=0; i<r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i=0; i<n; i++){
            vector<int>row;
            for(int j=0; j<=i; j++){
                row.push_back(c(i,j));
            }
            res.push_back(row);
        }
        return res;
    }
};


Question Link : https://leetcode.com/problems/pascals-triangle/