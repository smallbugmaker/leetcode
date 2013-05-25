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
    
    TreeNode *getTree(vector<int> &inorder, vector<int> &postorder, int inorderst, int inorderen, int postorderst, int postorderen)
    {
        if (postorderst>=postorderen || inorderst>=inorderen)
            return NULL;
        int pos = findpos(inorder, inorderst, inorderen, postorder[postorderen-1]);
        TreeNode* left = getTree(inorder, postorder, inorderst, pos, postorderst, postorderst+(pos-inorderst));
        TreeNode* right = getTree(inorder, postorder, pos+1, inorderen, postorderst+(pos-inorderst), postorderen-1);
        TreeNode* root = new TreeNode(postorder[postorderen-1]);
        root->left = left;
        root->right = right;
        return root;        
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size()==0 || postorder.size()==0) return NULL;
        return getTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
