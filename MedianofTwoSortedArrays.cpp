class Solution {
public:
    double findKth(int A[], int m, int B[], int n, int k)
    {
        int a = k/2, b = k - a - 1;
        a--;
        
        if (a>=m)
        {
            a = m;
            b = k - a -1;
            a--;
        }
        
        if (b>=n)
        {
            b = n;
            a = k - b - 1;
            b--;
        }        
        
        while (b>=0 && a+1<m && A[a+1]<B[b])
        {
            a++;
            b--;
        }
        while (a>=0 && b+1<n && B[b+1]<A[a])
        {
            b++;
            a--;            
        }  

        if (a<0) return B[b];
        if (b<0) return A[a];
        if (A[a]>B[b]) return A[a];
        else return B[b];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m==0 && n==0) return 0;
        if ((m+n)%2==0)
          return (findKth(A,m,B,n,(m+n)/2)+findKth(A,m,B,n,(m+n)/2+1))/2.0;
        else
          return findKth(A,m,B,n,(m+n+1)/2);    
    }
};
