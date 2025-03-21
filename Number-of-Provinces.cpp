// https://leetcode.com/problems/number-of-provinces/description/

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/



class Solution {
public:
    void bfs(vector<vector<int>>adj, vector<int>&visited, int start)
    {
        queue<int> q;
        visited[start] = 1;
        q.push(start);

        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            visited[x] = 1;
            for(int i=0; i<adj.size(); i++)
            {
                if(adj[x][i]==1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> visited(n, 0);

        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(isConnected, visited, i);
            }
        }

        return count;
    }
};
