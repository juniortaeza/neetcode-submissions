class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> occ;
        for(int i = 0; i < nums.size(); i++){
            if(occ.find(nums[i]) == occ.end())
                occ.insert({nums[i], 1});
            else
                return true;
        }
        return false;
    }
};
