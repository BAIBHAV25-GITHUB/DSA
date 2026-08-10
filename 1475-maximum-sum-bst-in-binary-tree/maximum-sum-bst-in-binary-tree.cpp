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

class Node{
public:
    int minNode, maxNode, sum;
    Node(int minNode, int maxNode, int sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxSum = 0;
    Node helper(TreeNode* root){
        if(!root) return Node(INT_MAX, INT_MIN, 0);

        auto left = helper(root->left);
        auto right = helper(root->right);

        if(left.maxNode < root->val && root->val < right.minNode){
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);
            return Node(min(root->val, left.minNode), max(root->val, right.maxNode), currSum);
        }        

        return Node(INT_MIN, INT_MAX, 0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};