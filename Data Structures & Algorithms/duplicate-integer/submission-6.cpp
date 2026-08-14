class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(nums[i]) != 0)
                return true;
            map.insert({nums[i], 0});
        }
        return false;
    }
};