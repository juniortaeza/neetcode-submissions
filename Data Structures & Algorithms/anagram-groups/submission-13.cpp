class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create hashmap mapping unique key to array of strings matching key
        unordered_map<string, vector<string>> group;

        // Iterate over input array
        for(int i = 0; i < strs.size(); i++){
            // Obtain current string and get unique key
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());

            // Check to see if it exists in hashmap
            if(group.find(sortedStr) != group.end()){
                group[sortedStr].push_back(strs[i]);
            } else {
                group.insert({sortedStr, {strs[i]}});
            }
        }

        // Obtain grouping of strings
        vector<vector<string>> result;
        unordered_map<string, vector<string>>::iterator it;
        for(it = group.begin(); it != group.end(); ++it)
            result.push_back(it->second);

        // Return resulting array
        return result;
    }
};

// Problem
// - anagram: when two strings have the same exact characters, regardless of arrangement
// - return in any order --> assumes O(1) insertion/lookup for unordered data structures
// - empty strings are valid
// - each string is made up of lowercase English letters

// Approaches
// - we can use a hashmap where the key is a sorted string
//   and the value is a vector of strings that match the key
//     - sorting takes O(m*nlogn) time
//         - where m = length of input arr
//         - where n = length of each string
//     - space = O(n), considering if every string is unique

// - we can use a hashmap with a customized key strategy
//   and the value is a vector of strings that match the key
//     - O(m*n) time, cutting out sorting
//     - O(n) space, if every string is unique

// Follow ups




