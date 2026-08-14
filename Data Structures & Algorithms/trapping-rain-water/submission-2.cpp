class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;

        int L = 0, R = height.size()-1;
        int leftMax = height[L], rightMax = height[R];
        int res = 0;
        while(L < R){
            if(leftMax < rightMax){
                L += 1;
                leftMax = max(height[L], leftMax);
                res += leftMax - height[L];
            } else {
                R -= 1;
                rightMax = max(height[R], rightMax);
                res += rightMax - height[R];
            }
        }
        return res;
    }
};
