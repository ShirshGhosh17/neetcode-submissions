class Solution {
public:

    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1 && j==n-1) return grid[i][j];
        if(i>=m || j>=n) return 1e5;

        if(dp[i][j] != -1) return dp[i][j];

        int down = grid[i][j] + solve(grid,i+1,j,dp);
        int right = grid[i][j] + solve(grid,i,j+1,dp);

        return dp[i][j] = min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(grid,0,0,dp);
    }
};