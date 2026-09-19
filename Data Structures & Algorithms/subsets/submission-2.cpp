class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<int>& currSub, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(currSub);
            return;
        }

        // decision tree to include a number in the subset
        currSub.push_back(nums[i]);
        dfs(nums, i+1, currSub, res);

        // decision tree to not include a number in the subset
        currSub.pop_back();
        dfs(nums, i+1, currSub, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        int index = 0;
        dfs(nums, index, sub, res);
        return res;
    }
};
