class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
                A[i] = B[i];
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int l = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (A[i] > B[j])
            {
                A[l] = A[i];
                i--;
            }
            else
            {
                A[l] = B[j];
                j--;
            }
            l--;
        }
        while (i >= 0)
        {
            A[l] = A[i];
            l--;
            i--;
        }
        while (j >= 0)
        {
            A[l] = B[j];
            l--; 
            j--;
        }
    }
};