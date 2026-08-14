class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create unordered hashmap
        unordered_map<int, int> table;

        // Iterate over nums array --> 1 pass only
        for(int i = 0; i < nums.size(); i++){
            // Get complement of current element
            int complement = target - nums[i];

            // Check to see if complement exists in hashmap
            if(table.find(complement) != table.end())
                return {table[complement], i};
            
            // Otherwise, insert element to map alongside it's index
            table.insert({nums[i], i});
        }

        // By default, return empty array --> shouldn't ever be hit
        return {};
    }
};

/*
Problem
- return indexes i and j such that nums[i] + nums[j] = target
- we don't i and j to be the same such that i != j
- we are guaranteed a solution/pair of indices for every input

- potential edge cases/base cases:
    - [5 5 7 3], target = 10
    - returns [0 1], we don't want [0 0] or [1 1] because i = j

Strategy
- 1) brute force, double for loop adding nums[i] + nums[j] till = target
    - O(N^2) Time because we are iterating over nums a second time for every element
    - O(1) Space because no data structure is created for any kind of tracking
- 2) hashmap such that key:value = num:index --> 1 pass approach obtaining a complement
     number and seeing if it exists in the map, if it does, return it's index along
     with the current element's index
    - complexity of a hashmap?
        - assuming it's unordered
            - avg case for look-up and insertion is O(1) constant
            - this assumes that we are using a really good hash function
            - in case of collissions, the complexity for LU and insertion is O(N)
    - O(N) Time because we are only iterating over nums once
    - O(N) Space assuming the hashmap grows to the size of nums
*/
