class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)
			return n;
        for(int i=0;i<n;i++)
        {
            if(A[i] == elem)
            {
                n--;
                for(int j=i;j<n;j++)
                {
                    A[j] = A[j+1];
                }
                i--;
            }
        }
        return n;
    }
};