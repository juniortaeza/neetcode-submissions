class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create hashmap from elements mapping to occ,
        unordered_map<int, int> count;
        for(int n : nums){
            if(count.find(n) != count.end())
                count[n] += 1;
            else
                count.insert({n, 1});
        }

        // use occurrence as a bucket index,
        vector<vector<int>> bucket(nums.size()+1);
        for(unordered_map<int, int>::iterator it = count.begin(); it != count.end(); it++){
            int num = it->first;
            int occ = it->second;

            // assign elements to proper bucket
            bucket[occ].push_back(num);
        }

        // iterate backwards grabbing the k elements
        vector<int> res;
        for(int i = bucket.size()-1; i >= 0; i--){
            vector<int> bt = bucket[i];
            for(int n : bt){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }

        return res;
    }
};

/*

Notes:
    - we just want to return the K most frequent numbers in the list
    - tests cases guarantee unique answers
    - may return output in any order
    - always an element in the list
    - numbers may be negative
    - k won't ever be greater than distinct elements in nums

Breakdown:
    1 1 2 2 2 3 3 3 3 4 4  | k=2

    hashmap:
    1:2
    2:3
    3:4
    4:2

    bucket-sort:
    1 2 3 4
      1 2 3
      4

    what if we sort the map by values?:
    1:2
    4:2
    2:3
    3:4

Solutions:
    - brute-force: create hashmap from elements mapping to occ,
                    we could sort the key-value pairs by value in inc order,
                    iterate backwards returning up to k elements
            - O(nlogn + n + k) = O(n) - Time Complexity
            - O(n)             = O(n) - Space Complexity

    -  bucket sort: create hashmap from elements mapping to occ,
                    use occurrence as a bucket index,
                    assign elements to proper bucket,
                    iterate backwards grabbing the k elements
            - O(n + n + k) = O(2n + k) = O(n) - Time Complexity
            - O(n + n)     = O(2n)     = O(n) - Space Complexity
*/
