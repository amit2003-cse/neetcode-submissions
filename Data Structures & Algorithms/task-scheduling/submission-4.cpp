class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq;

        for(auto& t: tasks){map[t]++;
        }
        for(auto& t : map){
            pq.push({t.second,t.first});
        }
        int f_max = pq.top().first;
        pq.pop();

        int l = 1;
        while(!pq.empty()){
            if(pq.top().first == f_max){
                l += 1;
                pq.pop();
            }
            break;
        }

        int a = (f_max - 1) * (n+1) + l;
        int result =  max(a,(int)tasks.size());
        return result;
    }
};
