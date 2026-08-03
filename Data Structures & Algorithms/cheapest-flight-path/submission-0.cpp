class Solution {
public:

    #define pp pair<int,pair<int,int>>

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<vector<int>> dist(n, vector<int> (k+2, INT_MAX));

        pq.push({0,{src,0}});

        while(! pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int stop = pq.top().second.second;
            pq.pop();

            if(node == dst) return cost;
            if(stop > k) continue;

            for(auto neigh : adj[node]){
                int adjnode = neigh.first;
                int wt = neigh.second;

                int newcost = cost+wt;
                if(dist[adjnode][stop+1] > newcost){
                    dist[adjnode][stop+1] = newcost;
                    pq.push({newcost,{adjnode,stop+1}});
                }
            }        
        }
        return -1;
    }
};
