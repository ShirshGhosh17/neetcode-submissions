class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        int a;
        int b;

        int acsum = 0;
        int expsum = ((n*n)*(n*n+1))/2;
        unordered_set<int> s;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                acsum += grid[i][j];
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        b = expsum+a-acsum;
        return {a,b};
    }
};