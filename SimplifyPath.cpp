class Solution {
public:
  string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<string> str;
        int pos = 0;
        string s = "";
        while (pos<=path.length())
        {
            if (path[pos]=='/' || pos==path.length())
            {
                if (s.compare("..")==0)
                { 
                    if(!str.empty()) str.pop();
                }
                else
                    if (s.compare(".")!=0 && s.length()>0)
                      str.push(s);
                s = "";
            }
            else
                s = s+path[pos];
            pos++;
        }
        
     //   if (s.length()>0) str.push(s);
        if (str.empty()) return "/";
        s = "";
        while (!str.empty())
        {
            s = "/" + str.top() +s;
            str.pop();
        }

        return s;
    }                 
};
