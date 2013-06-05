class Solution {
public:
    string multiplySingle(string &num, char mul)
    {
        string res = "";
        int b = 0;
        int m = mul-'0';
        for (int i=num.length()-1; i>=0; i--)
        {
            int x = (num[i]-'0')*m+b;
            b = x/10;
            char c = '0' + x%10;
            res = c + res;
        }
        if (b!=0)
        {
            char c = '0' + b;
            res = c + res;         
        }
        return res;
    }
    
    string add(string &num1, string &num2)
    {
        string res = "";
        
        int l1 = num1.length()-1;
        int l2 = num2.length()-1;
        int b = 0;
        while (l1>=0 && l2>=0)
        {
            int x = (num1[l1]-'0') + (num2[l2]-'0') + b;
            b = x/10;
            char c = '0' + x%10;
            res = c + res;
            l1--;
            l2--;
        }
        while (l1>=0)
        {
            int x = (num1[l1]-'0') + b;
            b = x/10;
            char c = '0' + x%10;
            res = c + res;
            l1--;
        }
        while (l2>=0)
        {
            int x = (num2[l2]-'0') + b;
            b = x/10;
            char c = '0' + x%10;
            res = c + res;
            l2--;
        }
        if (b!=0)
        {
            char c = '0' + b;
            res = c + res;         
        }
        return res;
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res = "";
        string zero = "";
        for (int i=num2.length()-1; i>=0; i--)
        {
            res = add(res, multiplySingle(num1, num2[i]).append(zero));
            zero += '0';
        }
        while (res[0]=='0' && res.size()>1)
            res.erase(res.begin());
        return res;
    }
};
