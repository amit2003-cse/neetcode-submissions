class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i :nums){
            map[i]++;
        }
        for(auto& it:map){
            q.push({it.second,it.first});
            while(k<q.size()){
                q.pop();
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};
