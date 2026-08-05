class Solution {
public:

    #define pp pair<int,int>

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pp>> adj(n+1);

        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<int> dist(n+1, INT_MAX);
        int count = 0;

        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            auto[time,node] = pq.top();
            pq.pop();

            if(time > dist[node]) continue;
            count++;

            if(count == n) return dist[node];

            for(auto neigh : adj[node]){
                int t = neigh.second;
                int adjnode = neigh.first;

                if(dist[adjnode] > time+t){
                    dist[adjnode] = time+t;
                    pq.push({time+t,adjnode});
                }
            }
        }

        return -1;
    }
};
