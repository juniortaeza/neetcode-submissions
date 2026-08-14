class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                int curr = 0;
                while(true){
                    curr = nums[curr];
                    slow = nums[slow];
                    if(curr == slow)
                        return curr;
                }
            }
        }
    }
};
