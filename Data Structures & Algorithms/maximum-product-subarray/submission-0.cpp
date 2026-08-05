class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxend = nums[0];
        int minend = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++){
            int ele = nums[i];

            if(ele < 0) swap(maxend,minend);

            maxend = max(maxend*ele,ele);
            minend = min(minend*ele,ele);

            ans = max(ans,maxend);
        }
        return ans;
    }
};
