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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "N"; }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);}
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";
        // Manually comma se split karo
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) {
            nodes.push_back(temp); // Last element add karo
        }
        
        int ind = 0;
        return buildTree(nodes, ind);
    }

    TreeNode* buildTree(vector<string>& nodes,int &ind){
        int size = nodes.size();
        if(ind >= size || nodes[ind] == "N"){
            ind++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[ind]));
        ind++;
        root->left = buildTree(nodes,ind);
        root->right = buildTree(nodes,ind);
        return root;
    }
};
