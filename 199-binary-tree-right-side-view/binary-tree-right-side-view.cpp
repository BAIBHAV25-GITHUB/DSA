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
    void rightView(TreeNode* root, vector<int>& res, int level){
        if(root == nullptr) return;

        if(level == res.size()) res.push_back(root->val);
        if(root->right){
            rightView(root->right, res, level+1);
        }
        if(root->left){
            rightView(root->left, res, level+1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        // Picking the last node of each level.. T(n)-O(n), S(n)-O(n);
        // vector<int> ans;
        // if(root == nullptr) return ans;

        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     vector<int> level;
        //     int size = q.size();
        //     for(int i=0; i<size; i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         level.push_back(node->val);
                
        //         if(node->left){
        //             q.push(node->left);
        //         }
        //         if(node->right){
        //             q.push(node->right);
        //         }
        //     }
        //     ans.push_back(level.back());
        // }
        // return ans;

        //Using DFS T(n)-O(n), S(n)-O(h)
        vector<int> ans;
        rightView(root, ans, 0);
        return ans;
    }
};