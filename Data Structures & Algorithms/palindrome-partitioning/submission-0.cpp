class Solution {
public:

    bool ispal(string &s){
        string rev = s;
        reverse(rev.begin(),rev.end());

        for(int i=0; i<s.size(); i++){
            if(s[i] != rev[i]){
                return false;
                break;
            }
        }
        return true;
    }

    void helper(string &s, vector<string> &res, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(res);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string curr = s.substr(0,i+1);
            string rem = s.substr(i+1);

            if(ispal(curr)){
                res.push_back(curr);
                helper(rem,res,ans);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;

        helper(s,res,ans);
        return ans;
    }
};
