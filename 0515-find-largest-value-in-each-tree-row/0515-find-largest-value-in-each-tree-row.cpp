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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int max_val=INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode* frnt=q.front();
                q.pop();
                max_val=max(max_val,frnt->val);
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);
            }
            v.push_back(max_val);
        }
        return v;
    }
};