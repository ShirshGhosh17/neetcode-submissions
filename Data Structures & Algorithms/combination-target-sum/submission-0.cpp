class Solution {
public:

    void helper(vector<int> &nums, int target, int i, vector<int> &res, vector<vector<int>> &ans){
        int n = nums.size();

        if(i==n || target < 0) return;
        if(target == 0){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        helper(nums,target-nums[i],i,res,ans);
        res.pop_back();
        helper(nums,target,i+1,res,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        helper(nums,target,0,res,ans);

        return ans;
    }
};
