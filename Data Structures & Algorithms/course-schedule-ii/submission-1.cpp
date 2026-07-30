class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto edge : prerequisites){
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }

        vector<int> indeg(numCourses);

        for(int i=0; i<numCourses; i++){
            for(auto neigh : adj[i]){
                indeg[neigh]++;
            }
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neigh : adj[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
