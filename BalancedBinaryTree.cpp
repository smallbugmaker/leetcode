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
    bool balanced(TreeNode *root, int &depth)
    {
        depth = 0;
        if (root==NULL) return true;
        
        int left, right;
        bool flag_l = balanced(root->left, left);
        bool flag_r = balanced(root->right, right);
        if (left>right) depth = left+1;
            else depth = right+1;
        if (flag_l && flag_r && abs(left-right)<=1) return true;
        else
            return false;        
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root==NULL) return true;
        int depth = 0;
        return balanced(root, depth);        
    }
};
