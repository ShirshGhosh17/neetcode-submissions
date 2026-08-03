class Solution {
public:

    int atmost(vector<int> &nums,int k){
        int n = nums.size();
        unordered_map<int,int> m;

        int l=0;
        int ans = 0;
        for(int r=0; r<n; r++){
            m[nums[r]]++;

            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0) m.erase(nums[l]);
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};