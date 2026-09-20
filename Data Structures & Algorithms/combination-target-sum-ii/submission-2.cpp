class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int i, int total, vector<int>& currSub, vector<vector<int>>& res) {
        if(total == target)             { res.push_back(currSub); return; }
        if(total > target)              { return; }
        if(i == candidates.size())      { return; }

        currSub.push_back(candidates[i]);
        backtrack(candidates, target, i+1, total + candidates[i], currSub, res);
        currSub.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            i += 1;
        backtrack(candidates, target, i+1, total, currSub, res);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> subset;
        int index = 0;
        int total = 0;
        backtrack(candidates, target, index, total, subset, result);
        return result;
    }
};
