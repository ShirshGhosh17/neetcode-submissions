class Solution {
public:

    bool solve(string s, vector<string> &wordDict, unordered_set<string> &word, int idx, vector<int> &dp){
        if(idx == s.size()) return true;
        string ans = "";

        if(dp[idx] != -1) return dp[idx];

        for(int i=idx; i<s.size(); i++){
            ans += s[i];
            if(word.find(ans) != word.end()){
                if(solve(s,wordDict,word,i+1,dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word;
        for(string s : wordDict){
            word.insert(s);
        }

        vector<int> dp(s.size(),-1);

        return solve(s,wordDict,word,0,dp);
    }
};
