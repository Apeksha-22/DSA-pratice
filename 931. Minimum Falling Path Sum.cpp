class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<vector<int>>& mat, int row, int col){
        int n=mat.size();
        
        //base cases
        if(col>=n || col < 0) return INT_MAX;
        if(row == n-1) return mat[row][col];

        // dp check 
        if(dp[row][col] != INT_MAX) return dp[row][col];

        // main kaam
        int x = INT_MAX;
        x = min({rec(mat, row+1, col),rec(mat, row+1, col-1),rec(mat, row+1, col+1)});
        if(x != INT_MAX) dp[row][col] = x + mat[row][col];
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        dp.assign(n,vector<int>(n,INT_MAX));
        int mini=INT_MAX;
        int j=0;
        for(int i=0; i<n; i++){
            mini = min(mini,rec(mat,0,i));
        }
        return mini;
    }
};


Question Link : https://leetcode.com/problems/minimum-falling-path-sum/