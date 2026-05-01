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
    int max_dia = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        int height_left = height(root->left);
        int height_right = height(root->right);
         max_dia = max(max_dia,height_left + height_right);
        return 1 + max(height_left,height_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return max_dia;
    }
};
