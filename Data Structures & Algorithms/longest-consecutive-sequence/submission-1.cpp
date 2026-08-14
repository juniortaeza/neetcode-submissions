class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;

        set<int> s;
        for(int n : nums)
            s.insert(n);

        vector<int> count;
        for(set<int>::iterator it = s.begin(); it != s.end(); it++){
            int num = *it;
            int seq = 0;
            while(s.find(num) != s.end()){
                seq += 1;
                num += 1;
            }
            count.push_back(seq);
        }

        int maxSeq = *max_element(count.begin(), count.end());

        return maxSeq;
    }
};
