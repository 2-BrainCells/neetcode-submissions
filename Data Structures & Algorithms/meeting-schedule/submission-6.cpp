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
   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });

        for(auto ele: intervals){
            cout << ele.start << " " << ele.end << endl;
        }

        int temp = intervals[0].end;
        bool val = true;

        for (int i = 1; i < intervals.size(); i++) {
            if (temp > intervals[i].start) {
                val = false;
            }
            temp = intervals[i].end;
            cout << val << endl;
        }
        return val;
    }
};
