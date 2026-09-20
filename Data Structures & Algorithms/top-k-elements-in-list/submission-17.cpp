class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums)
            m[num]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for(const auto& pair : m){
            int num = pair.first;
            int occ = pair.second;
            bucket[occ].push_back(num);
        }

        vector<int> res;
        for(int i = bucket.size()-1; i >= 0; i--){
            vector<int> bt = bucket[i];
            for(int n : bt){
                res.push_back(n);
                if(res.size()==k)
                    return res;
            }
        }

        return res;
    }
};
