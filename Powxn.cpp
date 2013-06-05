class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (fabs(x)==1)
        {
            if (x==1 || n%2==0) return 1;
            return -1;
        }
        if (n<0)
        {
            n = -n;
            x = 1.0/x;
        }
        double res = 1;
        while (n--)
        {
            res = res*x;
            if (fabs(res)<1e-7) return res;
        }
        return res;
    }
};
