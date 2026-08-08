class Solution {
public:

    int solve(vector<int> &nums, int i, vector<int> &dp){
        int n = nums.size();
        if(i==n-1) return nums[i];
        if(i==n-2) return max(nums[n-1],nums[n-2]);

        if(dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i]+solve(nums,i+2,dp),solve(nums,i+1,dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};
