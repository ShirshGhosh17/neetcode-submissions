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

    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int inlo, int inhi, int postlo, int posthi, unordered_map<int,int> &m){
        if(inlo > inhi || postlo > posthi) return NULL;
        TreeNode* node = new TreeNode(postorder[posthi]);

        int inidx = m[postorder[posthi]];
        int leftlen = inidx-inlo;
        int rightlen = inhi-inidx;

        TreeNode* lefttree = build(inorder,postorder,inlo,inidx-1,postlo,postlo+leftlen-1,m);
        TreeNode* righttree = build(inorder,postorder,inidx+1,inhi,posthi-rightlen,posthi-1,m);

        node->left = lefttree;
        node->right = righttree;
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n = postorder.size();

        for(int i=0; i<n; i++){
            m[inorder[i]] = i;
        }

        return build(inorder,postorder,0,n-1,0,n-1,m);
    }
};