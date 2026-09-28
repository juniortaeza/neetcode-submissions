/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
    struct IntervalComparator{
        bool operator()(const Interval& a, const Interval& b) const {
            return a.start < b.start;
        }
    };

public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), IntervalComparator());
        int prevStart = intervals[0].start;
        int prevEnd   = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++){
            int currStart = intervals[i].start;
            int currEnd   = intervals[i].end;

            if(prevEnd > currStart)
                return false;
            prevStart = currStart;
            prevEnd   = currEnd;
        }

        return true;
    }
};
