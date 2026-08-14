class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> nodeSet;
        for(int x : nums){
            if(nodeSet.find(x) != nodeSet.end())
                return x;
            nodeSet.insert(x);
        }
        return 0;
    }
};
