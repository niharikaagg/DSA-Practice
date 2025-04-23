// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;

        // Add the edge if both are not in same component. If both nodes are in same component already then it is an extra edge.

        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if(ds.findUltimateParent(u) == ds.findUltimateParent(v))
            {
                extraEdges++;
            }

            ds.unionBySize(u, v);
        }

        int components = 0;

        for(int i=0; i<n; i++)
        {
            if(ds.findUltimateParent(i) == i)
                components++;
        }

        // Minimum number of edges required to connect N components is N-1.
        int minOperations = components - 1;

        if(extraEdges >= minOperations)
            return minOperations;
        return -1;
    }
};
