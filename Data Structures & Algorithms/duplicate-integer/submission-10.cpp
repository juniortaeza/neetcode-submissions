class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Time: O(N), iterating through nums | Space: O(N), WC: nums is all unique
        // set<int> s1;
        // for(int x : nums)
        //     s1.insert(x);
        // return s1.size() != nums.size();

        set<int> s2;
        for(int x : nums){
            if(s2.contains(x))
                return true;
            else
                s2.insert(x);
        }
        return false;
    }
};