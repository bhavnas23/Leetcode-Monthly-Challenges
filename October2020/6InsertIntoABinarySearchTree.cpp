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
    void inorder(TreeNode* root, int val){
        if(root->val>val){
            if(root->left)
                inorder(root->left, val);
            else{
                root->left = new TreeNode(val);
                return;
            }
        }
        else{
            if(root->right)
                inorder(root->right, val);
            else{
                root->right = new TreeNode(val);
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        inorder(root, val);
        return root;        
    }
};
