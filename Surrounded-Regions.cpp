// https://leetcode.com/problems/surrounded-regions/description/

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/



class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, int m, int n)
    {
        stack<pair<int, int>> s;
        s.push({i, j});
        visited[i][j] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();

            for(int i=0; i<4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n && board[newX][newY]=='O' && !visited[newX][newY])
                {
                    visited[newX][newY] = 1;
                    s.push({newX, newY});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            if(board[0][i] == 'O' && !visited[0][i])
                dfs(board, visited, 0, i, m, n);

            if(board[m-1][i] == 'O'  && !visited[m-1][i])
                dfs(board, visited, m-1, i, m, n);
        }

        for(int i=0; i<m; i++)
        {
            if(board[i][0] == 'O'  && !visited[i][0])
                dfs(board, visited, i, 0, m, n);

            if(board[i][n-1] == 'O'  && !visited[i][n-1])
                dfs(board, visited, i, n-1, m, n);
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
