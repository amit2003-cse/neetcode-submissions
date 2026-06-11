class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // current index unreachable
            if (i > maxReach)
                return false;

            // update farthest reachable index
            maxReach = max(maxReach, i + nums[i]);

            // already can reach last index
            if (maxReach >= n - 1)
                return true;
        }

        return true;
    }
};