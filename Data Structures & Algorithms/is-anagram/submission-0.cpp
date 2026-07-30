class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            if(m.find(t[i]) != m.end() && m[t[i]] > 0){
                m[t[i]]--;
            }

            else{
                return false;
            }
        }
        return true;
    }
};
