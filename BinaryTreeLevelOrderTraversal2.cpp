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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
                
        vector< vector<int> > res;
        vector< vector<int> >().swap(res);
        if (root==NULL) return res;
        
        vector< TreeNode* > node[2];
        vector< TreeNode* >().swap(node[0]);        
        vector< TreeNode* >().swap(node[1]);        
        node[0].push_back(root);
        
        int t = 0, n = 0;
        while (node[t].size()>0)
        {
            vector< TreeNode* >().swap(node[1-t]);
            n++;
            vector<int> temp;
            vector<int>().swap(temp);
            for (int i=0; i<node[t].size(); i++)
            {       
                temp.push_back(node[t][i]->val);
                if (node[t][i]->left!=NULL)
                {
                    node[1-t].push_back(node[t][i]->left);                    
                }
                if (node[t][i]->right!=NULL)
                {
                    node[1-t].push_back(node[t][i]->right);                    
                }
            }
            res.push_back(temp);
            t = 1-t;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
