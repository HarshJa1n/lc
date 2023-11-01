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
    void inorder(TreeNode* root, vector<int> &res){
        if(!root){
            return ;
        }
        res.push_back(root->val);
        inorder(root->left, res);
        inorder(root->right, res);
    }


    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> counts;
        vector<int> store;
        inorder(root, store);
        int maxm=0;

        for(auto it: store){
            counts[it]++;
            maxm=max(maxm,counts[it]);
        }

        vector<int> ans;
        for(auto it: counts){
            if(it.second==maxm){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};