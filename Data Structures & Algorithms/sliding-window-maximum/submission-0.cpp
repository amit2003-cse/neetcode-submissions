class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            int m=INT_MIN;
            for(int j=i;j<k+i;j++){
                m = max(m,nums[j]);
            }
            ans.push_back(m);
        }
        return ans;
        
    }
};
