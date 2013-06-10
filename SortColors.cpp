class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int red = 0, white = 0, blue = n-1;
        
        while (white<=blue)
        {
            if (A[white]==0)
            {
                if (red<white)
                    swap(A[red], A[white]);
                else
                   white++;
                red++;                
                continue;
            }
            if (A[white]==2)
            {                
                swap(A[white], A[blue]);
                blue--;  
                continue;
            }
            white++;
        }
    }
};
