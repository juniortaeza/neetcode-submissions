class Solution {
public:
    int rob(vector<int>& houses) {
        if(houses.empty())   return 0;
        if(houses.size()==1) return houses[0];
        if(houses.size()==2) return max(houses[0], houses[1]);

        int n = houses.size();

        vector<int> dp1(n, 0);  // exclude last house
        dp1[0] = houses[0];
        dp1[1] = max(houses[0], houses[1]);

        for(int i = 2; i < n - 1; i++){
            dp1[i] = max(dp1[i-1], houses[i] + dp1[i-2]);
        }

        vector<int> dp2(n+1, 0);  // exclude first house
        dp2[0] = houses[1];
        dp2[1] = max(houses[1], houses[2]);

        for(int i = 2; i < n; i++){
            dp2[i] = max(dp2[i-1], houses[i+1] + dp2[i-2]);
        }
        
        return max(dp1[n-2], dp2[n-2]);
    }
};
