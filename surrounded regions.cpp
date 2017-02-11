class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        if(m<3 || n<3) return;
        for(int i=0,j=0;j<n;j++)   //��һ������Ԫ��
            if(board[i][j] == 'O')
                dfs(board,i,j);
        for(int i=m-1,j=0;j<n;j++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //���һ������Ԫ��
        for(int i=0,j=0;i<m;i++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //��һ������Ԫ��
        for(int i=0,j=n-1;i<m;i++)
            if(board[i][j] == 'O')
                dfs(board,i,j);   //���һ������Ԫ��
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
        if(row>0 && board[row-1][col]=='O')  dfs(board,row-1,col);//��
        if(col<board[0].size()-1 && board[row][col+1]=='O') dfs(board,row,col+1);//��
        if(row<board.size()-1 && board[row+1][col]=='O') dfs(board,row+1,col);//��
        if(col>0 && board[row][col-1]=='O') dfs(board,row,col-1);//��
    }
void bfs(vector<vector<char>> &board,int row,int col)
{
	typedef pair<int,int> element;
	int m = board.size();
	int n = board[0].size();
	queue<element> boardQueue;
	boardQueue.push(element(row,col));
	while(!boardQueue.empty())   //���в�Ϊ��
	{
		element nodeNow = boardQueue.front();
		boardQueue.pop();
		int i = nodeNow.first;
		int j = nodeNow.second;
		board[i][j] = '*';   //���߽��'o'��Ϊ'*'
		if(i>0 && board[i-1][j]=='O')  boardQueue.push(element(i-1,j));//��
		if(j<n-1 && board[i][j+1]=='O') boardQueue.push(element(i,j+1));//��
		if(i<m-1 && board[i+1][j]=='O') boardQueue.push(element(i+1,j));//��
		if(j>0 && board[i][j-1]=='O') boardQueue.push(element(i,j-1));//��
	}
}

};