/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathDown(root,maxSum);
        return maxSum;

    }
    int maxPathDown(TreeNode* root,int &maxSum){
        if(!root) return 0;

        int left = max(maxPathDown(root->left,maxSum),0);
        int right = max(maxPathDown(root->right,maxSum),0);

        int currMax = root->val+left+right;
        maxSum = max(maxSum,currMax);

        return root->val + max(left,right);
    }
};
