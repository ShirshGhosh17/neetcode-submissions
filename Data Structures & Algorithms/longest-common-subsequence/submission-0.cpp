class Solution {
public:

    int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
        int m = text1.size();
        int n = text2.size();

        if(i==m || j==n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1+solve(text1,text2,i+1,j+1,dp);
        }

        int p1 = solve(text1,text2,i,j+1,dp);
        int p2 = solve(text1,text2,i+1,j,dp);

        return dp[i][j] = max(p1,p2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(text1,text2,0,0,dp);
    }
};
