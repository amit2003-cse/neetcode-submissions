class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
       vector<int> output(n);

        output[0] = 1;
       for(int i=1;i<n;i++){
        output[i] = output[i-1] * nums[i-1];
       }
       int postfix = 1;
       for(int j=n-1;j>=0;j--){
        output[j] = output[j] * postfix;
        postfix *= nums[j];
       }
       return output;
    }
};
