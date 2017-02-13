class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int m = matrix.size();
        int n = matrix[0].size();
        if(m<=1) return;
        //根据副对角线对折，交换元素
        for(int i=0;i<m;i++)
            for(int j=0;j<n-i;j++)
            {
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        for(int i=0;i<m/2;i++)
            for(int j=0;j<n;j++)
            {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
    }
};