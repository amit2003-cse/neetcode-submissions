class Solution {
public:
    int trap(vector<int>& height) {
        int tw=0, n=height.size();
        vector<int> lm(n,0);
        vector<int> rm(n,0);
        lm[0] = height[0];
        rm[n-1]= height[n-1];

        for(int i=1;i<n;i++){
            lm[i] = max(lm[i-1],height[i]);
            rm[(n-1)-i] = max(rm[n-i],height[(n-1)-i]);
        }
        for(int i=1;i<n-1;i++){
            if(min(lm[i-1],rm[i+1]) - height[i]>0){
                tw += min(lm[i-1],rm[i+1]) - height[i];
            }
        }
        return tw;
    
    }
};
