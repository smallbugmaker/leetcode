    /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Space O(n)
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &val)
    {
        if (root==NULL) return ;
        inorder(root->left, val);
        val.push_back(root->val);
        inorder(root->right, val);
    }
    
    void recover(TreeNode *root, vector<int> &val, int &i)
    {
        if (root==NULL) return ;
        recover(root->left, val, i);
        root->val = val[i];
        i++;
        recover(root->right, val, i);
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> val;
        vector<int>().swap(val);
        inorder(root, val);
        sort(val.begin(), val.end());
        int i = 0;
        recover(root, val, i);
    }
};

//Sapce O(1)
class Solution {
public:
    void inorder(TreeNode *root, TreeNode* &first, TreeNode* &second, TreeNode* &pre )
    {
        if (root==NULL) return ;
        inorder(root->left, first, second, pre);
        if (pre && pre->val>root->val)
        {
            if (first==NULL) 
                first = pre;
            second = root;
        }
        pre = root;        
        inorder(root->right, first, second, pre);        
    }     
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *pre = NULL;
        inorder(root, first, second, pre);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;        
    }
};
