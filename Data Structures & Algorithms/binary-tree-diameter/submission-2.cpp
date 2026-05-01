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
    int dia;
    int height(TreeNode* root){
        if(!root) return 0;

        int maxleft = height(root->left);
        int maxright = height(root->right);

        dia = max(dia,maxleft + maxright);

        return max(maxleft,maxright) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
       height(root);
       return dia; 
    }
};
