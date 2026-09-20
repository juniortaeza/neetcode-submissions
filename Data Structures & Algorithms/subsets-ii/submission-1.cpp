class Solution {
private:
    void backtrack(vector<int>& nums, int i, vector<int>& currSub, vector<vector<int>>& res) {
        if(i == nums.size()){ 
            res.push_back(currSub); 
            return; 
        }
        currSub.push_back(nums[i]);
        backtrack(nums, i+1, currSub, res);
        currSub.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i += 1;
        backtrack(nums, i+1, currSub, res);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        int index = 0;
        backtrack(nums, index, subset, result);
        return result;
    }
};
