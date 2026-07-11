class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int f_max = 0;

        for(auto& t:tasks){
            count[t - 'A']++;
            f_max = max(f_max,count[t - 'A']);
        }

        int l = 0;

        for(auto& c : count){
            if(c == f_max){
                l += 1;
            }
        }

        int a = (f_max - 1) * (n + 1) + l;

        return max(a, (int)tasks.size());
    }
};
