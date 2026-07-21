class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        
        unordered_set<int> s;
        int rep;
        int miss;
        int total = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                total += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    rep = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        int actual = ((n*n)*(n*n+1))/2;
        miss = actual-total+rep;

        vector<int> ans(2);
        ans[0] = rep;
        ans[1] = miss;
        return ans;
    }
};