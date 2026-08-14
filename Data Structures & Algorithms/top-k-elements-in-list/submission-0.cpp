class Solution {
public:
    // approach: using occurrences as indexes and values are
    //           numbers of that occurrence
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // store occurence of each number in map
        unordered_map<int, int> count;
        for(int n : nums){
            if(count.find(n) != count.end())
                count[n] += 1;
            else
                count.insert({n, 1});
        }

        // for each key:value in map, store in freq table
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int, int>::iterator it;
        for(it = count.begin(); it != count.end(); ++it){
            int key = it->first;
            int value = it->second;

            freq[value].push_back(key);
        }

        // reverse traverse freq table until k is satisfied
        vector<int> result;
        for(int i = freq.size() - 1; i > 0; i--){
            for(int n : freq[i]){
                result.push_back(n);
                if(result.size() == k)
                    return result;
            }
        }

        // return final result
        return result;
    }
};
