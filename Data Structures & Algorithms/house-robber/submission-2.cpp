class Solution {
public:
    int rob(vector<int>& houses) {
        if(houses.empty())   return 0;
        if(houses.size()==1) return houses[0];
        if(houses.size()==2) return max(houses[0],houses[1]);

        int n = houses.size();

        int prev2 = houses[0];
        int prev1 = max(houses[0],houses[1]);

        for(int i = 2; i < n; i++){
            int curr = max(prev1, prev2+houses[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return max(prev2, prev1);
    }
};

/*

1) Define the problem and state

    - we want to maximize the amount of money we can get
      up to the i-th house

    let OPT(i) or dp[i] represent the maximum amount of money
    at the i-th house

2) Recurrence Relation and obvious base cases

    1) choose to not rob a house
        - if we choose to not rob a house, bring along
          the previous money we've gathered and move onto
          the next house

        dp[i] = dp[i-1]

    2) choose to rob a house
        - if we choose to rob a house, steal the house's money
          and add it to our total money gathered previously

        dp[i] = max(dp[i-1], d[i-2]+houses[i])

3) Implementation -> space optimization necessary?

*/








