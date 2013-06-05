class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> pos;
        vector<int> flag;
        int m = 1;
        for (int i=1;i<n;i++)
        {
            m = m*i;
            flag.push_back(i);
        }
        flag.push_back(n);
            
        while(n)
        {
            int x = k/m;
            if (k%m!=0)
                x++;
            pos.push_back(x-1);
            k = k - m*(x-1);
            n--;
            if (n) m = m/n;            
        }
        n = pos.size();
        string res = "";
        for (int i=0; i<n; i++)
        {
            res.push_back('0'+flag[pos[i]]);
            flag.erase(flag.begin()+pos[i]);
        }
        return res;
    }
};
