class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto& s : stones){
            pq.push(s);
        }
        while(!pq.empty()){
            if(pq.size()<2) return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x==y) continue;
            
            if(x>y){
                int z = x-y;
                pq.push(z);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};
