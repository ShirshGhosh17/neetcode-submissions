class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = -1;
        int currmin = INT_MAX;
        int n = prices.size();

        for(int i=0; i<n; i++){
            currmin = min(currmin,prices[i]);
            int profit = prices[i]-currmin;
            ans = max(ans,profit);
        }
        return ans;
    }
};
