class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> count;
        map<char, int>().swap(count);
        
        int lens = S.length();
        int lent = T.length();
        for (int i=0; i<lent; i++)
            if (count.find(T[i])!=count.end())
                count[T[i]]++;
            else
                count.insert(make_pair(T[i], 1));
            
        int st=0, en=0, n = 0;
        int res = 2147483647, resst = 0, resen = 0;
        
        while (en<lens)
        {
            while (en<lens && n!=lent)
            {
                if (count.find(S[en])!=count.end())
                {
                    if (count[S[en]]>0) n++;
                    count[S[en]]--;                    
                }
                en++;
            }
            if (n!=lent) break;            
            while(st<en)
            {
                if (count.find(S[st])!=count.end())
                {
                    count[S[st]]++;
                    if (count[S[st]]>0)
                    {
                        if (en-st<res)
                        {
                            res = en-st;
                            resst = st;
                            resen = en;
                        }            
                        st++;
                        n--;
                        break;
                    }
                }
                st++;
            }                       
                        
        }        
        return S.substr(resst, resen-resst);
    }
};
