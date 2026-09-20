class Solution {
private:
    void dfs(vector<int>& nums, int i, vector<int>& currSub, vector<vector<int>>& res) {
        if(i == nums.size()){
            res.push_back(currSub);
            return;
        }
        currSub.push_back(nums[i]);
        dfs(nums, i+1, currSub, res);
        currSub.pop_back();
        dfs(nums, i+1, currSub, res);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        int index = 0;
        dfs(nums, index, subset, result);
        return result;
    }
};
