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

        int findpos(vector<int> &vec, int st, int en, int num)
        {
            for (int i=st; i<en; i++)
              if (vec[i]==num)
                return i;
            return -1;
        }

        TreeNode *getTree(vector<int> &inorder, vector<int> &preorder, int inorderst, int inorderen, int preorderst, int preorderen)
        {
            if (preorderst>=preorderen || inorderst>=inorderen)
              return NULL;
            int pos = findpos(inorder, inorderst, inorderen, preorder[preorderst]);
            TreeNode* left = getTree(inorder, preorder, inorderst, pos, preorderst+1, preorderst+1+(pos-inorderst));
            TreeNode* right = getTree(inorder, preorder, pos+1, inorderen, preorderst+1+(pos-inorderst), preorderen);
            TreeNode* root = new TreeNode(preorder[preorderst]);
            root->left = left;
            root->right = right;
            return root;        
        }    

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (inorder.size()==0 || preorder.size()==0) return NULL;
            return getTree(inorder, preorder, 0, inorder.size(), 0, preorder.size());
        }
};
