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
        bool action(TreeNode *root, int sumNow, int &sum)
        {
            if (root->left==NULL && root->right==NULL)
              if (sumNow==sum)
                return true;
              else
                return false;

            if (root->left!=NULL)
            {
                if ( action(root->left, sumNow+root->left->val, sum) )
                  return true;

            }

            if (root->right!=NULL)
            {       
                if ( action(root->right, sumNow+root->right->val, sum) )
                  return true;

            }
            return false;
        }
        bool hasPathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function        
            if (root==NULL) return false;

            return action(root, root->val, sum);

        }
};
