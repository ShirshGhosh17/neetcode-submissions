class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;

        sort(intervals.begin(),intervals.end(),cmp);

        merged.push_back(intervals[0]);

        for(int i=0; i<n; i++){
            vector<int> temp = merged.back();
            if(intervals[i][0] <= temp[1]){
                vector<int> v(2);
                merged.pop_back();
                v[0] = temp[0];
                v[1] = max(temp[1],intervals[i][1]);
                merged.push_back(v);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
