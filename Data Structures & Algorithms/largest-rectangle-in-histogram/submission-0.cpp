class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n);
        vector<int> psi(n);

        stack<int> st;
        st.push(n-1);
        nsi[n-1] = n;
        
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                st.pop();
            }
            if(st.empty()) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        st.push(0);
        psi[0] = -1;

        for(int i=1; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) psi[i] = -1;
            else psi[i] = st.top();
            st.push(i);
        }

        int rect = 0;

        for(int i=0; i<n; i++){
            int width = nsi[i]-psi[i]-1;
            int height = heights[i];
            rect = max(rect,height*width);
        }
        return rect;
    }
};
