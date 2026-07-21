class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(),intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<pair<int,int>> sorted_query(queries.size());

        for(int i=0;i<queries.size();i++){
            sorted_query[i] = {queries[i],i};
        }

        vector<int> result(queries.size(),-1);

        sort(sorted_query.begin(),sorted_query.end());

        int j = 0;

        for(int i=0;i<sorted_query.size();i++){
            
            while(j<intervals.size() && intervals[j][0]<=sorted_query[i].first){
                int len = (intervals[j][1] - intervals[j][0]) + 1;
                pq.push({len,intervals[j][1]});
                j++;
            }

            while(!pq.empty() && pq.top().second < sorted_query[i].first){
                pq.pop();
            }

            if(!pq.empty()){
                result[sorted_query[i].second] = pq.top().first;
            }
            
            

        }
        return result;
        
    }
};
