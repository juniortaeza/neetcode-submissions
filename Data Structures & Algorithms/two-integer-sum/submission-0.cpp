class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> occ;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(occ.find(complement) != occ.end())
                return {occ[complement], i};
            occ.insert({nums[i], i});
        }
        return {};
    }
};
