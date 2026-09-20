class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSub = 0;
        for(int num : nums){
            if(curSub < 0)
                curSub = 0;
            curSub += num;
            maxSub = max(maxSub, curSub);
        }
        return maxSub;
    }
};
