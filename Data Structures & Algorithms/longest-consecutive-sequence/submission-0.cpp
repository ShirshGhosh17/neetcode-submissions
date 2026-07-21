class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for(int ele : nums){
            s.insert(ele);
        }

        int ans = 0;

        for(int ele : s){
            
            if(s.find(ele-1) == s.end()){
                int count = 1;
                int curr = ele;

                while(s.find(curr+1) != s.end()){
                    count++;
                    curr++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
