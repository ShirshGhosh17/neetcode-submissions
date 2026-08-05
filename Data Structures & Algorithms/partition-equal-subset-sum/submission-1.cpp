class Solution {
public:

    bool solve(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n){
            if(target == 0) return true;
            return false;
        }

        if(target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = solve(nums,target-nums[i],i+1,dp);
        bool leave = solve(nums,target,i+1,dp);
        return dp[i][target] = take||leave;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            total += nums[i];
        }

        if(total%2 == 1) return false;
        int target = total/2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(nums,target,0,dp);
    }
};
