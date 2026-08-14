class Solution {
public:
    int rob(vector<int>& houses) {
        if(houses.empty())   return 0;
        if(houses.size()==1) return houses[0];
        if(houses.size()==2) return max(houses[0], houses[1]);

        int n = houses.size();

        int prev2 = houses[0];
        int prev1 = max(houses[0], houses[1]);

        for(int i = 2; i < n - 1; i++){
            int current = max(prev1, prev2 + houses[i]);
            prev2 = prev1;
            prev1 = current;
        }

        int prev4 = houses[1];
        int prev3 = max(houses[1], houses[2]);

        for(int i = 2; i < n; i++){
            int current = max(prev3, prev4 + houses[i+1]);
            prev4 = prev3;
            prev3 = current;
        }
        
        return max(prev1, prev4);
    }
};
