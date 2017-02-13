class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int End = m*n-1;
        int start = 0;
        while(true)
        {
            if(start>End)
                return false;
            int pos = start+(End-start)/2;
            int posRow = pos/n;
            int posCol = pos%n;
            if(matrix[posRow][posCol] == target)
                return true;
            else
                if(target > matrix[posRow][posCol])
                    start = pos+1;
                else
                    End = pos-1;
        }
    }
};