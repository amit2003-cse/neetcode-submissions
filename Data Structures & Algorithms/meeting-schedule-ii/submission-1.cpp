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
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>,greater<int>> pq;
        
        sort(intervals.begin(),intervals.end(), []( const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        for(auto& i : intervals){

            if(!pq.empty() && i.start >= pq.top()){
                pq.pop();
                pq.push(i.end);
            }else{
            pq.push(i.end);}

        }
        return pq.size();
    }
};
