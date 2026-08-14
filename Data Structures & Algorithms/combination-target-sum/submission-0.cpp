class Solution {
private:
    void backtrack(vector<int>& nums, int target, int i, int total, vector<int>& subset, vector<vector<int>>& res){
        // Base Cases
        if(total == target)  { res.push_back(subset); return; }
        if(total > target)   { return; }
        if(i == nums.size()) { return; }

        // Decision Tree:
        // 1) can choose to use a number (can reuse inf. amount of times) -> update total
        subset.push_back(nums[i]);
        backtrack(nums, target, i, total+nums[i], subset, res);

        // 2) can choose to not use a number (go to next element) -> don't update total
        subset.pop_back();
        backtrack(nums, target, i+1, total, subset, res);
    }
public:
    // T: O(k*2^n) -> where k is length of a valid combination and 2^n is generated subsets for k
    // S: O(k*R)   -> where k is recursive stack that grows to size of valid combo, and R holds the final subsets output
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // create our initial resulting and subset arrays
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums, target, 0, 0, subset, res);
        return res;
    }
};
