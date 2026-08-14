class Solution {
public:
    // sorted arr.
    // searching for two elems.
    // two pointers.
    // ==> custom binary search 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size()-1;
        while(L < R){
            int sum = numbers[L] + numbers[R];

            if(sum > target)
                R -= 1;
            else if(sum < target)
                L += 1;
            else
                return {L+1, R+1};
        }

        return {};
    }
};
