class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& currPermutation, vector<vector<int>>& res){
        // Base Case
        if(currPermutation.size() == nums.size()){
            res.push_back(currPermutation);
            return ;
        }

        /*
            [1, 1, 1] -> visited
            [1, 2, 3] -> nums
            [0, 1, 2] -> index

            [ [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1] ] -> final result
        */

        // Generate permutations
        for(int i = 0; i < nums.size(); i++){
            // When do we want to add to current permutation? -> when an index has not been visited
            if(!visited[i]){
                // add to permutation
                currPermutation.push_back(nums[i]);
                visited[i] = true;

                // recurse to add next element
                backtrack(nums, visited, currPermutation, res);

                // backtrack, mark nodes as unvisited and pop nodes -> unwinding the stack
                currPermutation.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currPermutation;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, currPermutation, res);
        return res;
    }
};