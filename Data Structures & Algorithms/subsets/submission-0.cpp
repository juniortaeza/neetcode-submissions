class Solution {
private:
    void backtrack(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }

        // decision to include nums[i]
        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset, res);

        // decision to not include nums[i]
        subset.pop_back();
        backtrack(nums, i+1, subset, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, 0, subset, res);
        return res;
    }
};
