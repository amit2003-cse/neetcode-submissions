class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int tw = 0;

        while(left<right){
            if(height[left] < height[right]){
                if(height[left]>= leftMax){
                    leftMax = height[left];
                }
                else{
                    tw += leftMax - height[left];
                }
                left++;
            }
            else{
                if(height[right]>= rightMax){
                    rightMax = height[right];
                }
                else{
                    tw += rightMax - height[right];
                }
                right--;
            }
        }
        return tw;
        
    }
};
