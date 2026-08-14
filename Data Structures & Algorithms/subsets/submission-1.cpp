class Solution {
private:
    void backtrack(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& finalSubsets){
        if(i >= nums.size()){
            finalSubsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset, finalSubsets);

        subset.pop_back();
        backtrack(nums, i+1, subset, finalSubsets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalSubsets;
        vector<int> subset;
        backtrack(nums, 0, subset, finalSubsets);
        return finalSubsets;
    }
};
