class Solution {
public:
    void getResult(string &digits, int pos, string &now, vector<string> &res)
    {
        if (pos==digits.length())
        {
            res.push_back(now);
            return ;
        }
        char st = ' ', en = ' ';
        switch (digits[pos])
        {
             case '7': st = 'p'; en = 's'; break;
             case '8': st = 't'; en = 'v'; break;
             case '9': st = 'w'; en = 'z'; break;
             default:
                 int i = (digits[pos]-'0'-2)*3;
                 st = i+'a';
                 en = i+2+'a';
                 break;
        }
        
        for (char i=st; i<=en; i++)
        {
            now.push_back(i);
            getResult(digits, pos+1, now, res);
            now.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        string now = "";
        getResult(digits, 0, now, res);
        return res;
    }
};
