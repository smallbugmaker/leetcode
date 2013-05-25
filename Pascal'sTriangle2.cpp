class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        rowIndex++;
        vector<int> res[2];
        vector<int>().swap(res[0]);
        vector<int>().swap(res[1]);
        if (rowIndex==0) return res[0];

        res[0].push_back(1);
        if (rowIndex==1) return res[0];

        int t = 0;

        for (int i=1; i<rowIndex; i++)
        {
            vector<int>().swap(res[1-t]);
            res[1-t].push_back(1);
            for (int j=1; j<i; j++)
              res[1-t].push_back(res[t][j]+res[t][j-1]);
            res[1-t].push_back(1);
            t = 1-t;
        }
        return res[t];
    }
};
