class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (root==NULL) return 0;
        
        vector< TreeNode* > node[2];
        vector< TreeNode* >().swap(node[0]);        
        vector< TreeNode* >().swap(node[1]);        
        node[0].push_back(root);
        
        int t = 0, n = 0;
        while (node[t].size()>0)
        {
            vector< TreeNode* >().swap(node[1-t]);
            n++;
            for (int i=0; i<node[t].size(); i++)
            {
                if (node[t][i]->left==NULL && node[t][i]->right==NULL)
                {
                    return n;
                }
                if (node[t][i]->left!=NULL)
                {
                    node[1-t].push_back(node[t][i]->left);
                }
                if (node[t][i]->right!=NULL)
                {
                    node[1-t].push_back(node[t][i]->right);
                }
            }
            t = 1-t;
        }
        return n;
        
    }
};
