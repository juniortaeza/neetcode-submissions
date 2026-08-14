class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())   return 0;
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return cost[1];

        int n = cost.size();
        vector<int> dp(n, 0);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};

/*

1) Define the problem (subproblem) and State

    - we want to minimize the cost it takes to get to the top
      of the stairs
    - the staircase that you land on is the cost that you take
        [1,2,3,4] -> taking arr[1] means taking cost 2
    - can either take one step or two steps from current position
    
    let OPT(i) or dp[i] represent the most minimal cost it takes
    to reach the i-th step

2) Recurrence Relation and Obvious Bases Cases

    we can either take one step or two steps for dp[i],
    choosing the minimum cost between the two steps

    let dp[i] = min(dp[i-1], dp[i-2])

    base cases:
    dp[0] = arr[0]
    dp[1] = min(arr[0], arr[1])

3) Implementation (memoization vs tabulation vs constant)

*/
