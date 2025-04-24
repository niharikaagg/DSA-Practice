// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
*/



class DisjointSet {
    vector<int> size, parent;
    
    public:
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;

        for(auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int nodesInSet = maxRow + maxCol + 2;

        DisjointSet ds(nodesInSet);
        unordered_map<int, int> stonePresent;   // to store those nodes which have a stone

        for(int i=0; i<stones.size(); i++)
        {
            int u = stones[i][0];
            int v = stones[i][1] + maxRow + 1;

            ds.unionBySize(u, v);

            stonePresent[u] = 1;
            stonePresent[v] = 1;
        }

        // We will find components from only those nodes where stones are present

        int components = 0;

        for(auto it : stonePresent)
        {
            if(ds.findUltimateParent(it.first) == it.first)
                components++;
        }

        return stones.size() - components;
    }
};
