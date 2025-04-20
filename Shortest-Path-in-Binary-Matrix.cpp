// https://leetcode.com/problems/shortest-path-in-binary-matrix/

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // We will use queue and not priority queue since it is a binary matrix so in every iteration the distance will be incremented by one, and thus the queue will always be sorted
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> distance(n, vector<int>(n, 1e9));

        q.push({1, {0,0}});    // Distance one because we have to count the number of cells, so the first cells will be distance one
        distance[0][0] = 1;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty())
        {
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i=0; i<8; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==0)
                {
                    int newDist = dist + 1;

                    if(newDist < distance[newX][newY])
                    {
                        distance[newX][newY] = newDist;
                        q.push({newDist, {newX, newY}});
                    }
                }
            }
        }
        if(distance[n-1][n-1] == 1e9)
            return -1;
        return distance[n-1][n-1];
    }
};
