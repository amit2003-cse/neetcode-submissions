class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n=position.size();
       vector<pair<int,double>> cars;

       for(int i=0;i<n;i++){
        double time = (double)(target-position[i])/speed[i];
        cars.push_back({position[i],time});
       }
       sort(cars.rbegin(),cars.rend());
       stack<double> s;
       for(auto& c:cars){
        
        double time = c.second;
        if(s.empty() || time>s.top()){
            s.push(time);
        }
       }
       return s.size();
        
    }
};
