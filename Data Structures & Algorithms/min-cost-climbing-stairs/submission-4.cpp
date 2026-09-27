class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())        return 0;
        if(cost.size() == 1)    return 1;

        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i = 2; i < n; i++){
            int curr = cost[i] + min(prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev2, prev1);
    }
};
