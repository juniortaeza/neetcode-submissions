class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use hashset for quick look-up
        unordered_set<int> s;
        for(int n : nums)
            s.insert(n);

        int longest = 0;
        for(int x : nums){
            // check if x is start of a seq, if it is, obtain sequence length
            if(s.find(x-1) == s.end()){
                int length = 0;
                while(s.find(x) != s.end()){ // O(1) check
                    length += 1;
                    x += 1;
                }
                longest = max(longest, length); // update longest
            }
        }

        return longest;
    }
};
