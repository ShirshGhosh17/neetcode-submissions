class Solution {
public:

    void helper(vector<int> &nums, int target, int i, vector<int> &res, vector<vector<int>> &ans){
        int n = nums.size();

        if(target == 0){
            ans.push_back(res);
            return;
        }

        if(i==n || target<0) return;

        res.push_back(nums[i]);
        helper(nums,target-nums[i],i+1,res,ans);
        res.pop_back();

        int idx = i+1;
        while(idx<n && nums[idx] == nums[idx-1]){
            idx++;
        }
        helper(nums,target,idx,res,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());

        helper(candidates,target,0,res,ans);
        return ans;
    }
};
