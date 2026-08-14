class Solution {
public:

    /*
        Questions:
            1) what if nums size is 1? --> false
            2) what if nums size is 0? --> false

        Approaches:
            1) we can use a map (ordered/unordered) to keep track of number occurrences
            ~~~~~2) we can use a set (ordered/unordered) to keep track of number occurrences~~~~
            3) we can create our own little look-up/hash table if provided sufficient info
                // [ 0 0 0 0 0 0 0 0 ... 0 ]
                // [ 0 1 0 0 0 0 0 0 ... 0 ] --> need to know bounds [x, y]

        Structure:
            - iterate through the array once and once only (ideally)
            - want to lookup if current element that we are on already exists in our DS
                - if it does, a duplicate exists return true
                - else insert element to DS and continue iterating

        Time and Space Complexity:
            - O(N) Time  --> iterating through nums array
            - O(N) Space --> can grow up to original nums' size (all elements unique)
    */

    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> occ;
        for(int x : nums){
            if(occ.find(x) != occ.end())
                return true;
            occ.insert(x);
        }
        return false;
    }
};
