class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int ans = 0;

        for(int r=0; r<n; r++){
            if(nums[r] == 1) continue;
            else{
                ans = max(ans,r-l);
                l = r+1;
            }
        }
        ans = max(ans,n-l);
        return ans;
    }
};