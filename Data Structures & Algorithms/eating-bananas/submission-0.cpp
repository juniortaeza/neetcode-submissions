class Solution {
public:
    int getMax(vector<int>& piles){
        int maxElement = piles[0];
        for(int num : piles)
            maxElement = max(maxElement, num);
        return maxElement;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1, R = getMax(piles);
        int res = R;
        while(L <= R){
            int k = (L+R)/2;
            long long totalTime = 0;
            for(int p : piles)
                totalTime += ceil(static_cast<double>(p) / k);
            
            if(totalTime <= h){
                res = k;
                R = k-1; 
            } else {
                L = k+1;
            }
        }
        return res;
    }
};
