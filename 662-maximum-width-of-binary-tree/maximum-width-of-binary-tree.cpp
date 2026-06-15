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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long maxWidth = 1;

        while(!q.empty()){
            long long size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            maxWidth = max(maxWidth, end-start+1);

            for(int i=0; i<size; i++){
                pair<TreeNode*, int>p = q.front();
                int idx = p.second-start;
                q.pop();

                if(p.first->left){
                    q.push({p.first->left, (long long)2*idx+1});
                }
                if(p.first->right){
                    q.push({p.first->right, (long long)2*idx+2});
                }
            }
        }
        return maxWidth;
    }
};