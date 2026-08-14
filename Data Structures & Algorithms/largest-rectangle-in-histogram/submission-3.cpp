class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            int start = i, h = heights[i];
            while(!st.empty() && st.top().second > h){
                pair<int,int> p = st.top(); st.pop();
                int index = p.first, height = p.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({ start,h });
        }

        while(!st.empty()){
            pair<int,int> p = st.top(); st.pop();
            int i = p.first, h = p.second;
            maxArea = max(maxArea, h * (n - i));
        }
        
        return maxArea;
    }
};
