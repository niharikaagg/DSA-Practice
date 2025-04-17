// https://www.geeksforgeeks.org/problems/topological-sort/1

/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
*/



class Solution {
  public:
    vector<vector<int>> createAdjacencyList(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        return adj;
    }
    
    void dfs(vector<vector<int>> &adj, vector<int> &visited, stack<int> &s, int i)
    {
        visited[i] = 1;
        
        for(int j=0; j<adj[i].size(); j++)
        {
            if(!visited[adj[i][j]])
                dfs(adj, visited, s, adj[i][j]);
        }
        
        s.push(i);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = createAdjacencyList(V, edges);
        
        vector<int> visited(V, 0);
        stack<int> s;
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
                dfs(adj, visited, s, i);
        }
        
        vector<int> topoOrder;
        
        while(!s.empty())
        {
            topoOrder.push_back(s.top());
            s.pop();
        }
        
        return topoOrder;
    }
};
