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
    TreeNode* build(vector<int>& inorder,int inStart, int inEnd, vector<int>& postorder, int poStart, int poEnd, map<int, int>& inMap) {
        if(inStart > inEnd || poStart > poEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[poEnd]);

        int inRoot=inMap[postorder[poEnd]];
        int left=inRoot-inStart;

        root->left = build(inorder, inStart, inRoot-1, postorder, poStart, poStart+left-1, inMap);
        root->right = build(inorder, inRoot+1, inEnd, postorder, poStart+left, poEnd-1,inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;

        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
};