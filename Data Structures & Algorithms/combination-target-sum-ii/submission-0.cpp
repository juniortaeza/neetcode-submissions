class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int i, int total, vector<int>& currCombination, vector<vector<int>>& res){
        // Base Cases -> when target reached
        //               when total exceeds target
        //               when candidates fully traversed
        if(total == target)        { res.push_back(currCombination); return; }
        if(total > target)         { return; }
        if(i == candidates.size()) { return; }

        // 1) Can choose to add candidate to total
        currCombination.push_back(candidates[i]);
        backtrack(candidates, target, i+1, total+candidates[i], currCombination, res);

        // 2) Can choose to not add candidate (exceeds target, etc.)
        currCombination.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            i += 1;
        backtrack(candidates, target, i+1, total, currCombination, res);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> currentCombination;
        backtrack(candidates, target, 0, 0, currentCombination, res);
        return res;
    }
};
