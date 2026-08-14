class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            // after sorting, if curr nums is > 0, no b+c could ever make a+b+c == 0
            if(nums[i] > 0)
                break;

            // to prevent duplicates, update a to non-duplicate index
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            // a is now set, use 2sum II approach for b and c
            int a = i, b = i+1, c = nums.size()-1;
            while(b < c){
                int sum = nums[a] + nums[b] + nums[c];
                if(sum > 0)
                    c -= 1;
                else if(sum < 0)
                    b += 1;
                else {
                    res.push_back({nums[a], nums[b], nums[c]});
                    // update left pointer preventing duplicates
                    b += 1;
                    while(nums[b] == nums[b-1] && b < c)
                        b += 1;
                }
            }
        }
        return res;
    }
};
