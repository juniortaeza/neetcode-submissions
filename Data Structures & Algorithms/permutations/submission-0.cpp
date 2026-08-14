class Solution {
private:
    void backtrack(const vector<int>& nums, vector<bool>& visited, vector<int>& permutation, vector<vector<int>>& res){
        if(permutation.size() == nums.size()){
            res.push_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                permutation.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, visited, permutation, res);
                visited[i] = false;
                permutation.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, permutation, res);
        return res;
    }
};
