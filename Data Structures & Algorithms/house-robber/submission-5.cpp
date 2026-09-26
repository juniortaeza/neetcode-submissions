class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())        return 0;                       // no houses to rob
        if(nums.size() == 1) return nums[0];                    // no choice but to rob it
        if(nums.size() == 2) return max(nums[0], nums[1]);      // rob the house with more money
        int n = nums.size();
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        // run recurrence relation, skip or rob non-adjacent house
        for(int i = 2; i < n; i++){
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
