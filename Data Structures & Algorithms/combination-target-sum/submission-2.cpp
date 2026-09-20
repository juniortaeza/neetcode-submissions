class Solution {
private:
    void backtrack(vector<int>& nums, int target, int total, int i, vector<int>& currSub, vector<vector<int>>& res) {
        if(i == nums.size() || total > target)  { return; }
        if(total == target)                     { res.push_back(currSub); return; }

        currSub.push_back(nums[i]);
        backtrack(nums, target, total + nums[i], i, currSub, res);
        currSub.pop_back();
        backtrack(nums, target, total, i+1, currSub, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        int total = 0;
        int index = 0;
        backtrack(nums, target, total, index, subset, result);
        return result;
    }
};
