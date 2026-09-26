class Solution {
    struct IntervalComparator{
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a[0] < b[0];
        }
    };

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), IntervalComparator());
        vector<vector<int>> merged;
        int prevStart = intervals[0][0];
        int prevEnd   = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];
            if(currStart <= prevEnd){
                prevEnd = max(prevEnd, currEnd);
            } else {
                merged.push_back({prevStart, prevEnd});
                prevStart = currStart;
                prevEnd   = currEnd;
            }
        }
        merged.push_back({prevStart, prevEnd});
        return merged;
    }
};
