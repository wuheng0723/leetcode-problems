class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> res;
        if(!matrix.size() || !matrix[0].size())
            return res;
        int left = 0;
        int right = matrix[0].size()-1;
        int up = 0;
        int down = matrix.size()-1;
        while(left<=right&&up<=down)
        {
            for(int i=left;i<=right;i++)
                res.push_back(matrix[up][i]);
            for(int i=up+1;i<=down;i++)
                res.push_back(matrix[i][right]);
            if(down>up)  //处理当只有一行的情况
            {
                for(int i=right-1;i>left;i--)
                    res.push_back(matrix[down][i]);
            }
            if(right>left)  //处理当只有一列的情况
            {
                for(int i=down;i>up;i--)
                    res.push_back(matrix[i][left]);
            }
            left++;
            up++;
            right--;
            down--;
        }
        return res;
    }
};