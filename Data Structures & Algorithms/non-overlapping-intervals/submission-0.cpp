class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[] (const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        
        int remove_count = 0;

        int prev_end = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];

            if(prev_end > curr_start){ remove_count += 1;
            continue;
            }

            prev_end = curr_end;
        }
        return remove_count;
    }
};
