class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        vector<string>().swap(res);
                
        int st = 0, en = 0, n = words.size(), lnow = 0;
        if (n==1)
        {
            string now = "";
            res.push_back(now.append(words[0]).append(L-words[0].length(), ' '));
            return res;
        }
        
        while (en<n)
        {
            int l = words[en].length();
            if (lnow+l+(en-st)>L)
            {                
                string now = "";
                if (en-st==1)
                {
                    now.append(words[st]).append(L-lnow, ' ');
                }
                else
                {
                    int x = (L-lnow)/(en-st-1);
                    int y = (L-lnow)%(en-st-1);
                    now.append(words[st]);
                    for (int i=st+1; i<en; i++)
                    {
                        if (y>0)
                        {
                            now.append(x+1,' ');
                            now.append(words[i]);
                            y--;
                        }
                        else
                        {
                            now.append(x, ' ');
                            now.append(words[i]);
                        }
                    }
                }
                res.push_back(now);
                lnow = l;                
                st = en;
                en++;
            }
            else
            {
                lnow += l;
                en++;
            }
        }     
        if (st<n && st<en)
        {
            string now = "";
            now.append(words[st]);
            for (int i=st+1; i<n; i++)
            {
                now.append(1, ' ');
                now.append(words[i]);
            }
            now.append(L-(lnow+(n-st-1)), ' ');
            res.push_back(now);
        }
        return res;
    }
};

