class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // 1. Base Case
    if (i == nums.size()) {
        result.push_back(current);
        return;
    }

    // 2. TAKE IT (Include)
    current.push_back(nums[i]); // DO
    solve(i+1, nums, current, result); // RECURSE
    current.pop_back(); // UNDO

    // 3. LEAVE IT (Exclude)
    // Plate mein kuch nahi dalna hai, bas agle number par jana hai
    solve(i+1, nums, current, result); // RECURSE
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
         solve(0,nums,current, result);
         return result;
    }
};
