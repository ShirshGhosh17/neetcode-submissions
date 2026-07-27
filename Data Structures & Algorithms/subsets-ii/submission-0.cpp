class Solution {
public:

    void helper(vector<int> &nums, int i, vector<int> &res, vector<vector<int>> &ans){
        int n = nums.size();
        if(i==n){
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        helper(nums,i+1,res,ans);
        res.pop_back();

        int idx = i+1;
        while(idx < n && nums[idx] == nums[idx-1]){
            idx++;
        }

        helper(nums,idx,res,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        helper(nums,0,res,ans);
        return ans;
    }
};
