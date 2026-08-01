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
        if(root == NULL) return "";
        string s = "";
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr != NULL){
                s += to_string(curr->val)+',';
                q.push(curr->left);
                q.push(curr->right);
            }
            else{
                s += "#,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        vector<string> s;
        string temp = "";
        
        for(int i=0; i<data.size(); i++){
            if(data[i] == ','){
                s.push_back(temp);
                temp = "";
            }
            else{
                temp += data[i];
            }
        }

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(s[0]));

        q.push(root);
        int i = 1;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(s[i] != "#"){
                TreeNode* leftnode = new TreeNode(stoi(s[i]));
                curr->left = leftnode;
                q.push(leftnode);
            }
            else{
                curr->left = NULL;
            }
            i++;

            if(s[i] != "#"){
                TreeNode* rightnode = new TreeNode(stoi(s[i]));
                curr->right = rightnode;
                q.push(curr->right);
            }
            else curr->right = NULL;
            i++;
        }
        return root;
    }
};
