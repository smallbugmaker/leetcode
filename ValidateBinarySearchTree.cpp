/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isvalid(TreeNode *root, int low, int high)
    {
        if (root==NULL) return true;        
        
        bool left=true, right=true;
        
        if (root->left)
           if(root->left->val<root->val && root->left->val>low && root->left->val<high)
               left = isvalid(root->left, low, root->val);
           else
               left = false;
        
        if (left==false) return false;
        if (root->right)
           if (root->right->val>root->val && root->right->val>low && root->right->val<high)
               right = isvalid(root->right, root->val, high);
           else
               right = false;
        return right;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) return true;
        return isvalid(root, -2147483647, 2147483647);
    }
};
