// https://leetcode.com/problems/rotting-oranges/description/

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int total = 0, rotten = 0, time = 0;
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                }

                if(grid[i][j])
                {
                    total++;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;

            q.pop();

            time = t;
            rotten++;

            for(int i=0; i<4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX<0 || newX>=m || newY<0 || newY>=n || grid[newX][newY]!=1)
                    continue;
                grid[newX][newY] = 2;
                q.push({{newX, newY}, t+1});
            }
        }

        if(rotten == total)
            return time;
        return -1;
    }
};
