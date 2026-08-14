class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // store elements into a set for quick look-up
        unordered_set<int> numSet;
        for(int n : nums)
            numSet.insert(n);

        // traverse array finding longest consecutive sequence
        int longest = 0;
        for(int n : nums){
            // check if start of seq, if it is, find length of it's consecutive seq
            if(numSet.find(n-1) == numSet.end()){
                int length = 0;
                while(numSet.find(n++) != numSet.end())
                    length += 1;
                longest = max(length, longest);
            }
        }

        // return longest sequence
        return longest;
    }
};
