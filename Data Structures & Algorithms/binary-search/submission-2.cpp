class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        while(L <= R){
            // get midpoint
            int mid = L+((R-L)/2);

            // update pointers based off mid
            if(nums[mid] < target)
                L = mid + 1;
            else if(nums[mid] > target)
                R = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
