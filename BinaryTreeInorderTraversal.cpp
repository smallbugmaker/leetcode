/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//recursive
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root==NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
//iteratively
class Solution {
public:

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> st;
        while (st.size()>0) st.pop();
        st.push(root);
        TreeNode *p = root->left;
        while (st.size()>0 || p)
        {
            while (p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
        }        
        return res;
    }
};
