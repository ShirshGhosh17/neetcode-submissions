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

    bool helper(TreeNode* root, int minval, int maxval){
        if(root == NULL) return true;
        if(root->val < maxval && root->val > minval){
            if(helper(root->left,minval,root->val) && helper(root->right,root->val,maxval)){
                return true;
            }
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
    }
};
