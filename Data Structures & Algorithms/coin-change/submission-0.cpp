class Solution {
public:

    int helper(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
        int n = coins.size();
        if(i >= n || amount < 0) return 1e9;
        if(amount == 0) return 0;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 1+helper(coins,amount-coins[i],i,dp);
        int leave = helper(coins,amount,i+1,dp);

        return dp[i][amount] = min(take,leave);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = helper(coins,amount,0,dp);

        if(ans >= 1e9) return -1;
        return ans;
    }
};
