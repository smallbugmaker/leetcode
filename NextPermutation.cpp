class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = num.size()-1;
        if (pos<1) return;
        while (pos>0 && num[pos]<=num[pos-1])
            pos--;
        int mpos = -1;
        for (int i=pos; i<num.size(); i++)
        {
            if (num[i]>num[pos-1] && (mpos==-1 || num[i]<num[mpos]))
                mpos = i;
        }
        
        int tmp = num[pos-1];
        num[pos-1] = num[mpos];
        num[mpos] = tmp;
        sort(num.begin()+pos, num.end());       
    }
};
