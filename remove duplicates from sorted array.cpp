class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)
			return n;
        for(int i=1;i<n;i++)
        {
            if(A[i-1] == A[i])
            {
                for(int j=i;j<n-1;j++)
                    A[j] = A[j+1];
                i--;
                n--;
            }
        }
        return n;
    }
};