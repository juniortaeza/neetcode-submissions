class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // use hashmap to store occurrence of each element
        unordered_map<int, int> count;
        for(int i : nums){
            if(count.find(i) != count.end())
                count[i] += 1;
            else
                count.insert({i, 1});
        }

        // create frequency table (bucket sort approach) based off map pairs
        vector<vector<int>> freq(nums.size()+1);
        cout << freq.size() << endl;
        unordered_map<int, int>::iterator it;
        for(it = count.begin(); it != count.end(); ++it){
            int key = it->first;
            int value = it->second;

            freq[value].push_back(key);
        }

        // grab the first k values in frequency table going backwards
        vector<int> res;
        for(int i = freq.size()-1; i >= 0; i--){
            vector<int> bucket = freq[i];
            for(int n : bucket){
                res.push_back(n);
                if(res.size() == k)
                    return res;
            }
        }

        // default return
        return res;
    }
};

/*
    brute-force: use hashmap to track number occurence,
                    sort pairs by occurence value,
                    return first k pair's key going backwards

    1 1 2 2 2 3 3 3 3

    3:4
    1:2
    2:3

     1:2
->   2:3
->   3:4   -> such that k=2 (first 2 pair keys)

    O(n + nlogn + n) = O(2n + nlogn) --> O(nlogn)

    
    bucket sort: use hashmap to store occurence of each element,
                 create frequency table mapping occurrence to an element,

    1 1 2 2 2 3 3 3 3 4 4 4

    1:2
    2:3
    3:4
    4:3

    look-up table where index = occ number

    index  -> 0 1 2 3 4 -> uses occurrence as index
    values ->     1 2 3     
                    4       -> what if we return [3,4] vs [3,2] for k=2?

    in this case: pretend 4 wasn't in input array

    index  -> 0 1 2 3 4
    values ->     1 2 3     -> [3,2] for k=2, traversing backwards

    O(n + n + k) = O(2n + k) --> O(n) --> this cuts down from nlogn
*/








