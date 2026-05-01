class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // Process first k elements
        for(int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process rest of the elements
        for (int i = k; i < nums.size(); i++) {
            // Push the max for previous window
            ans.push_back(nums[dq.front()]);

            // Remove out-of-window elements
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove all smaller elements
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Push the max for the last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};
