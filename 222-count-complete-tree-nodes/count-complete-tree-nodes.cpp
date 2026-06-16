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
    int leftHeight(TreeNode* root){
        // if(root == nullptr) return 0;
        
        int height = 0;
        while(root) {
            height += 1;
            root=root->left;
        }
        return height;
    }

    int rightHeight(TreeNode* root){
        // if(root == nullptr) return 0;

        int height = 0;
        while(root) {
            height += 1;
            root=root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int leftH = leftHeight(root);
        int rightH = rightHeight(root);

        if(leftH == rightH){
            return (1 << leftH) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;;
    }
};