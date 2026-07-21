class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;

        unordered_map<char,int> m;
        int ans = 0;

        for(int r=0; r<n; r++){
            m[s[r]]++;
            while(m[s[r]] > 1){
                m[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
