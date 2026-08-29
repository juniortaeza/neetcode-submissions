class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int x : nums)
            s.insert(x);

        return s.size() != nums.size();
    }
};