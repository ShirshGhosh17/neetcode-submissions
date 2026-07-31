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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while(!q.empty()){
            int n = q.size();
            vector<int> res(n);

            if(level%2 == 1){
                for(int i=0; i<n; i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    res[i] = curr->val;

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            else{
                for(int i=0; i<n; i++){
                    TreeNode* curr = q.front();
                    q.pop();

                    res[n-i-1] = curr->val;
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            level++;
            ans.push_back(res);
        }
        return ans;
    }
};