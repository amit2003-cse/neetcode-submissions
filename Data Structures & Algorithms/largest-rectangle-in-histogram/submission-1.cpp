class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int left=i;
            while(left>0 && heights[left-1]>=heights[i]){
                left--;
            }
            int right=i;
            while(right<n-1 && heights[right+1]>=heights[i]){
                right++;
            }
            int width = right-left + 1;
            int area = heights[i] * width;
            maxArea= max(maxArea,area);
        }
        return maxArea;
    }
};
