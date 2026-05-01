class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       
        int n=temperatures.size();
         vector<int> result(n,0);
        for(int i=0;i<n;i++){
           
            for(int j=i+1;j<n;j++){
                
                if(temperatures[i]<temperatures[j]){
                    result[i]=j-i;
                    break;
                    }
                    
                
            }
        }
        return result;
        }
        
    
};
