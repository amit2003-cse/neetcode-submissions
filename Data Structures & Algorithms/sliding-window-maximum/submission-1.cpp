class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        
        for(int right=0;right<=n-k;right++){
            int m = INT_MIN;
            int left=right;
            int window = k;
            while(left<k+right){
                m = max(m,nums[left]);
                left++;
            }
            ans.push_back(m);
        }
        return ans;
    }
};
