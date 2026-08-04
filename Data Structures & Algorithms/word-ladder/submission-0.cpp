class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        queue<pair<string,int>> q;

        for(string str : wordList){
            s.insert(str);
        }

        q.push({beginWord,1});

        while(! q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord){
                return level;
                break;
            }

            for(int i=0; i<word.size(); i++){
                int orignal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word,level+1});
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};
