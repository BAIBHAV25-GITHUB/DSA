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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isRev) {
        reverse = isRev;
        print(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) print(temp->right);
        else print(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !(st.empty());
    }

    void print(TreeNode* root){
        while(root != nullptr){
            st.push(root);
            if(reverse == true) root = root->right;
            else root = root->left; 
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i=l.next();
        int j=r.next();
        while(i < j){
            if(i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};