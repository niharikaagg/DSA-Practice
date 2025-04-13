// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
*/



class Solution {
  public:
    vector<vector<int>> createAdjMatrix(int V, vector<vector<int>> edges) {
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return adj;
    }
  
    bool bfs(vector<vector<int>> adj, vector<int> &visited, int i)
    {
        queue<pair<int, int>> q;
        
        q.push({i, -1});
        visited[i] = 1;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int j=0; j<adj[node].size(); j++)
            {
                int neighbour = adj[node][j];
                
                if(!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push({neighbour, node});
                }
                
                else if(neighbour != parent)
                    return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> adj = createAdjMatrix(V, edges);
        
        vector<int> visited(V, 0);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(bfs(adj, visited, i))
                    return true;
            }
        }
        return false;
    }
};
