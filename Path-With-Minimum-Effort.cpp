// https://leetcode.com/problems/path-with-minimum-effort/description/

/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell
*/



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
                       minHeap;

        vector<vector<int>> distance(m, vector<int>(n, 1e9));

        distance[0][0] = 0;
        minHeap.push({0, {0, 0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!minHeap.empty())
        {
            int dist = minHeap.top().first;
            int x = minHeap.top().second.first;
            int y = minHeap.top().second.second;
            minHeap.pop();

            for(int i=0; i<4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n)
                {
                    int newDist = max(dist, abs(heights[x][y] - heights[newX][newY]));

                    if(newDist < distance[newX][newY])
                    {
                        distance[newX][newY] = newDist;
                        minHeap.push({newDist, {newX, newY}});
                    }
                }
            }
        }

        return distance[m-1][n-1];
    }
};
