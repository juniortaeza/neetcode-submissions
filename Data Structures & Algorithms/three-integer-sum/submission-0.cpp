class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort input array
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // for each element use 2 pointer method to grab 2 sum
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int L = i+1, R = nums.size()-1;
            while (L < R){
                int sum = nums[i] + nums[L] + nums[R];
                
                if (sum > 0)
                    R -= 1;
                else if (sum < 0)
                    L += 1;
                else {
                    res.push_back({nums[i], nums[L], nums[R]});
                    L += 1;
                    while(nums[L] == nums[L-1] && L < R)
                        L += 1;
                }
            }
        }

        return res;
    }
};
