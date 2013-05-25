struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:       
        int maxPathSum(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            maxpath = -2147483647;
            int maxl=0, maxr=0;
            findMaxPath(root, maxl, maxr);
            return maxpath;
        }
        int maxpath;
        int returnMax(int x, int y)
        {
            if (x>y)
              return x;
            return y;
        }
        void findMaxPath(TreeNode *node, int &maxl, int &maxr)
        {
            maxl = node->val;
            if (node->left!=NULL)
            {
                int lmaxl = -2147483647, lmaxr = -2147483647;
                findMaxPath(node->left, lmaxl, lmaxr);
                if (returnMax(lmaxl, lmaxr)+node->val>maxl)
                  maxl = returnMax(lmaxl, lmaxr)+node->val;
            }
            maxr = node->val;
            if (node->right!=NULL)
            {
                int rmaxl = -2147483647, rmaxr = -2147483647;
                findMaxPath(node->right, rmaxl, rmaxr);
                if (returnMax(rmaxl, rmaxr)+node->val>maxr)
                 maxr = returnMax(rmaxl, rmaxr)+node->val;
            }
            if (maxl+maxr-node->val>maxpath)
              maxpath = maxl+maxr-node->val;
            if (maxl>maxpath)
              maxpath = maxl;
            if (maxr>maxpath)
              maxpath = maxr;
        }
};
