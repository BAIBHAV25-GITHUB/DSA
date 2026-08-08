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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> curr;
            
            for(int i=0; i<n; i++){
                TreeNode* Node = q.front(); 
                q.pop();
                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);
                curr.push_back(Node->val);
            }

            ans.push_back(curr);
        }

        int l=0, r=ans.size()-1;
        while(l < r){
            swap(ans[l], ans[r]);
            l++, r--;
        }
        return ans;
    }
};