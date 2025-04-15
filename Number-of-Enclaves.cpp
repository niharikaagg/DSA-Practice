// https://leetcode.com/problems/number-of-enclaves/description/

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/



class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int m, int n)
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

                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY] == 1 && !visited[newX][newY])
                {
                    s.push({newX, newY});
                    visited[newX][newY] = 1;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            if(grid[0][i] == 1 && !visited[0][i])
                dfs(grid, visited, 0, i, m, n);

            if(grid[m-1][i] == 1 && !visited[m-1][i])
                dfs(grid, visited, m-1, i, m, n);
        }

        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
                dfs(grid, visited, i, 0, m, n);

            if(grid[i][n-1] == 1 && !visited[i][n-1])
                dfs(grid, visited, i, n-1, m, n);
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};
