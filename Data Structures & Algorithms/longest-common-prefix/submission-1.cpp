class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        string word1 = strs[0];
        string word2 = strs[n-1];

        int i=0;
        int j=0;

        string ans ="";

        while(i<word1.size() && j<word2.size()){
            if(word1[i] == word2[j]){
                ans += word1[i];
                j++;
                i++;
            }
            else break;
        }
        return ans;
    }
};