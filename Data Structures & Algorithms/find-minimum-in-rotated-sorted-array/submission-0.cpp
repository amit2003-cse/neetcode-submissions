class Solution {
public:
    int findMin(vector<int> &nums) {
        int Min=INT_MAX;
        for(int n:nums){
            if(n<Min){
                Min=n;
            }
        }
        return Min;
    }
};
