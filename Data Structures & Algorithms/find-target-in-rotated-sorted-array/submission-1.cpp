class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int ans = -1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(nums[mid] == target){
                ans = mid;
                break;
            }

            else if(nums[lo] > nums[mid]){
                if(nums[mid] < target && target <= nums[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
            else{
                if(nums[mid] > target && target >= nums[lo]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        return ans;
    }
};
