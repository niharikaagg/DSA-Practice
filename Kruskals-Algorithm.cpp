// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
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
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        
        int weightMST = 0;
        
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                ds.unionBySize(u, v);
                weightMST += wt;
            }
        }
        
        return weightMST;
    }
};
