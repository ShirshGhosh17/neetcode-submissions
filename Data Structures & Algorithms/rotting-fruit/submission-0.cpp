class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        q.push({-1,-1});

        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(x==-1 && y==-1){
                time++;
                if(!q.empty()){
                    q.push({-1,-1});
                }
                continue;
            }

            for(int i=0; i<4; i++){
                int dx = x+dir[i][0];
                int dy = y+dir[i][1];

                if(dx<0 || dy<0 || dx>=m || dy>=n || grid[dx][dy] == 0 || grid[dx][dy] == 2) continue;

                if(grid[dx][dy] == 1){
                    fresh--;
                    grid[dx][dy] = 2;
                    q.push({dx,dy});
                }
            }
        }

        if(fresh != 0) return -1;

        return time-1;
    }
};
