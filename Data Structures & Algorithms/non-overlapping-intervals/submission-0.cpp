class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans =  0;

        sort(intervals.begin(),intervals.end());
        int last = intervals[0][1];

        for(int i=1; i<n; i++){
            if(intervals[i][0] < last){
                ans++;
                last =  min(intervals[i][1],last);
            }
            else{
                last = intervals[i][1];
            }
        }
        return ans;
    }
};
