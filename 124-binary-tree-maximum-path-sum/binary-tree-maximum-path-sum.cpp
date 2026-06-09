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
    int sum(TreeNode* root, int& maxSum){
        if(root == nullptr) return 0;

        int leftSum = max(0, sum(root->left, maxSum));
        int rightSum = max(0, sum(root->right, maxSum));

        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return root->val + max(leftSum , rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        sum(root, ans);
        return ans;
    }
};