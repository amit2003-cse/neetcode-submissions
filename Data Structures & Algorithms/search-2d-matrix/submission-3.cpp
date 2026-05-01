class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row*col - 1;

        while(left<=right){
            int mid = (left+right)/2;
            int midr = mid/col;
            int midc = mid%col;
            int midval = matrix[midr][midc];
            if(midval==target){
                return true;
            }
            else if(midval>target){
                right=mid-1;
            }
            else{
                left= mid+1;
            }
        }
        return false;

        
    }
};
