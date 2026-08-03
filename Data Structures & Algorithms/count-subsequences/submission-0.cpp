class Solution {
public:

    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        int n = s.size();
        int m = t.size();

        if(j==m) return 1;
        if(i==n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int take = solve(s,t,i+1,j+1,dp);
            int leave = solve(s,t,i+1,j,dp);

            return dp[i][j] = take+leave;
        }
        else return dp[i][j] = solve(s,t,i+1,j,dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(s,t,0,0,dp);
    }
};
