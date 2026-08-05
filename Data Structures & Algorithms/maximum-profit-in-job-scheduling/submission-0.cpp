class Solution {
public:

    int nextjob(vector<vector<int>> jobs, int target){
        int n = jobs.size();
        int lo = 0;
        int hi = n-1;

        int ans = n;

        while(lo <= hi){
            int mid = lo+(hi-lo)/2;

            if(jobs[mid][0] >= target){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }

    int helper(vector<vector<int>> jobs, int i, vector<int> &dp){
        int n = jobs.size();
        if(i==n) return 0;

        if(dp[i] != -1) return dp[i];

        int next = nextjob(jobs,jobs[i][1]);

        int take = jobs[i][2]+helper(jobs,next,dp);
        int leave = helper(jobs,i+1,dp);
        
        return dp[i] = max(take,leave);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3));

        for(int i=0; i<n; i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(),jobs.end());
        vector<int> dp(n,-1);

        return helper(jobs,0,dp);
    }
};