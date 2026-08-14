class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size()-1, res = 0;
        while(L < R){
            // area of rect = length * width
            int area = (R-L) * min(heights[L], heights[R]);
            res = max(area, res);

            // update pointers based off smallest height
            if(heights[L] < heights[R])
                L += 1;
            else
                R -= 1;
        }
        return res;
    }
};
