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

    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int prelo, int prehi, int inlo, int inhi, unordered_map<int,int> &m){

        if(prelo > prehi || inlo > inhi) return NULL;

        TreeNode* node = new TreeNode(preorder[prelo]);
        int inidx = m[preorder[prelo]];

        int leftlen = inidx-inlo;

        TreeNode* lefttree = build(preorder,inorder,prelo+1,prelo+leftlen,inlo, inidx-1,m);
        TreeNode* righttree = build(preorder,inorder,prelo+leftlen+1,prehi,inidx+1,inhi,m);

        node->left = lefttree;
        node->right = righttree;
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n = preorder.size();
        for(int i=0; i<n; i++){
            m[inorder[i]] = i;
        }

        return build(preorder,inorder,0,n-1,0,n-1,m);
    }
};
