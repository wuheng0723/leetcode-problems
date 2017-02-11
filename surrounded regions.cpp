class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        if(m<3 || n<3) return;
        for(int i=0,j=0;j<n;j++)   //第一行所有元素
            if(board[i][j] == 'O')
                dfs(board,i,j);
        for(int i=m-1,j=0;j<n;j++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //最后一行所有元素
        for(int i=0,j=0;i<m;i++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //第一列所有元素
        for(int i=0,j=n-1;i<m;i++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //最后一列所有元素
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
    }
    void dfs(vector<vector<char>> &board,int row,int col)
   {
        board[row][col] = '*';
        if(row>0 && board[row-1][col]=='O')  dfs(board,row-1,col);//上
        if(col<board[0].size()-1 && board[row][col+1]=='O') dfs(board,row,col+1);//右
        if(row<board.size()-1 && board[row+1][col]=='O') dfs(board,row+1,col);//下
        if(col>0 && board[row][col-1]=='O') dfs(board,row,col-1);//左
    }
void bfs(vector<vector<char>> &board,int row,int col)
{
	typedef pair<int,int> element;
	int m = board.size();
	int n = board[0].size();
	queue<element> boardQueue;
	boardQueue.push(element(row,col));
	while(!boardQueue.empty())   //队列不为空
	{
		element nodeNow = boardQueue.front();
		boardQueue.pop();
		int i = nodeNow.first;
		int j = nodeNow.second;
		board[i][j] = '*';   //将边界的'o'变为'*'
		if(i>0 && board[i-1][j]=='O')  boardQueue.push(element(i-1,j));//上
		if(j<n-1 && board[i][j+1]=='O') boardQueue.push(element(i,j+1));//右
		if(i<m-1 && board[i+1][j]=='O') boardQueue.push(element(i+1,j));//下
		if(j>0 && board[i][j-1]=='O') boardQueue.push(element(i,j-1));//左
	}
}

};