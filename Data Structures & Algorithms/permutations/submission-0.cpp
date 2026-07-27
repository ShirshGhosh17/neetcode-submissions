class Solution {
public:

    void helper(vector<int> &nums, vector<int> &res, vector<vector<int>> &ans, vector<bool> &vis){
        if(res.size() == nums.size()){
            ans.push_back(res);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                vis[i] = true;
                res.push_back(nums[i]);
                helper(nums,res,ans,vis);
                res.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> vis(n,false);

        helper(nums,res,ans,vis);
        return ans;
    }
};
