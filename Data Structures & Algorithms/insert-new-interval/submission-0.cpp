class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;
        int n = intervals.size();

        // Step 1) append intervals before newInterval's index -> end times < newInterval start
        while(i < n && intervals[i][1] < newInterval[0]){
            merged.push_back(intervals[i]);
            i += 1;
        }

        // Step 2) merge overlapping intervals such that newIntervals end >= overlapping's start
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i += 1;
        }

        merged.push_back(newInterval);

        // Step 3) append remaining intervals from list to merged
        while(i < n){
            merged.push_back(intervals[i]);
            i += 1;
        }

        return merged;
    }
};
