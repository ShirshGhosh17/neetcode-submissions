class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        if(n==1) return nums[0];

        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            if(mid == 0 && nums[0] != nums[1]){
                return nums[0];
            }

            if(mid == n-1 && nums[n-1] != nums[n-2]){
                return nums[n-1];
            }

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if(mid%2 == 0){
                if(nums[mid] == nums[mid-1]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(nums[mid] == nums[mid+1]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        return -1;
    }
};