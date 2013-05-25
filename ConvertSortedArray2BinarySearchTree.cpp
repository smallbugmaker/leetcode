class Solution {
public:

   TreeNode *getTree(vector<int> &num, int start, int end)
        {            
            if (start >= end) return NULL;
            
            int mid = (start+end)/2;                    
            
            TreeNode *left = getTree(num, start, mid);
            TreeNode *right = getTree(num, mid+1, end);
            TreeNode *root = new TreeNode(num[mid]);
            root->left = left;
            root->right = right;
            return root;
        }
        
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if (len==0) return NULL;
        return getTree(num, 0, len);
    }
};
