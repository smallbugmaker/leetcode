class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool p = false;
        if ( (dividend<0 && divisor>0) || (dividend>0 && divisor<0))
           p = true;
        
        long long dividendNew = dividend;
        long long divisorNew = divisor;
        if (dividendNew < 0) dividendNew = -dividendNew;
        if (divisorNew < 0) divisorNew = -divisorNew;
        long long res = 0;
        long long mul = 1, d = divisorNew;
        while (dividendNew>0 && d>0)
        {
            if (dividendNew>=d)
            {
               res+=mul;               
               dividendNew -=d;
               d +=divisorNew;
               mul++;
             }
             else
             {
                 while (dividendNew<d)
                 {
                     d -= divisorNew;
                     mul--;
                 }
             }
        }
        if (p) res = -res;
        return res;
    }
};
