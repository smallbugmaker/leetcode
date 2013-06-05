class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int digits[7] = {1,5,10,50,100,500,1000};
        char romans[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        
        string res = "";
        for (int i=6; i>=0; i-=2)
        {
            int d = num/digits[i];          
            switch (d)
            {
                case 0: break;
                case 1:
                case 2:
                case 3: res.append(d, romans[i]); break;
                case 4:
                   res.push_back(romans[i]);                   
                case 5:
                   res.push_back(romans[i+1]);
                   break;
                case 6: 
                case 7:
                case 8: res.push_back(romans[i+1]);
                        res.append(d-5, romans[i]);
                        break;
                case 9: res.push_back(romans[i]);
                        res.push_back(romans[i+2]);
                        break;
            }            
            num = num%digits[i];
        }        
        return res;
    }
};
