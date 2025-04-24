// https://leetcode.com/problems/making-a-large-island/

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
*/



class DisjointSet {    
    public:
        vector<int> size, parent;

        DisjointSet(int n) {
            size.resize(n, 1);
            parent.resize(n);
            
            for(int i=0; i<n; i++)
                parent[i] = i;
        }
        
        int findUltimateParent(int node) {
            if(node == parent[node])
                return node;
                
            return findUltimateParent(parent[node]);
        }
        
        void unionBySize(int u, int v) {
            int pu = findUltimateParent(u);
            int pv = findUltimateParent(v);
            
            if(pu == pv)
                return;
                
            if(size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            
            else
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 1 - Make connected components 4-directionally adjacent
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 0)
                    continue;

                int nodeNo = row*n + col;

                for(int i=0; i<4; i++)
                {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    int adjNodeNo = newRow*n + newCol;

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==1)
                        ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }

        // Step 2 - Change each node from 0 to 1 and find components adjacent to make island and find largest size
        int maxSize = 0;
        
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == 1)
                    continue;

                int size = 0;

                // To keep track of unique components, and to prevent counting the same component more than one time if it is adjacent to that node in more than one direction
                unordered_set<int> uniqueParents;

                for(int i=0; i<4; i++)
                {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    int adjNodeNo = newRow*n + newCol;

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==1)
                    {
                        int parent = ds.findUltimateParent(adjNodeNo);

                        if(uniqueParents.find(parent) == uniqueParents.end())
                        {
                            uniqueParents.insert(parent);
                            size += ds.size[parent];
                        }
                    }
                }

                maxSize = max(maxSize, size+1);
            }
        }

        if(maxSize == 0)    // If the entire grid has 1, no 0 can be flipped so maxSize will remain 0
            return n*n;
        return maxSize;
    }
};
