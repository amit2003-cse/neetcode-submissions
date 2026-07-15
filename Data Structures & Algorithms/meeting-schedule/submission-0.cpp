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
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto& i : intervals){
            pq.push({i.start,i.end});
        }
        while(!pq.empty()){
            int temp = pq.top().second;
            pq.pop();
            if(!pq.empty() && pq.top().first < temp) return false;
        }
        return true;
    }
};
