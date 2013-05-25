class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector<int> > res;
        vector< vector<int> >().swap(res);
        if (numRows==0) return res;
        
        vector<int> temp;
        vector<int>().swap(temp);
        temp.push_back(1);
        res.push_back(temp);

        if (numRows==1) return res;

        for (int i=1; i<numRows; i++)
        {
            vector<int>().swap(temp);
            temp.push_back(1);
            for (int j=1; j<i; j++)
              temp.push_back(res[i-1][j]+res[i-1][j-1]);
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};
