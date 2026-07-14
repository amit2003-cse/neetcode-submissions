class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>, greater<pair<double,vector<int>>>> pq;
        for(auto& p : points){
            int a = p[0];
            int b = p[1];

            double result = sqrt(pow(a,2) + pow(b,2));
            pq.push({result,{a,b}});
        }
        vector<vector<int>> final;
        int i = 0;
        while(!pq.empty() &&  i < k){
            final.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return final;
    }
};
