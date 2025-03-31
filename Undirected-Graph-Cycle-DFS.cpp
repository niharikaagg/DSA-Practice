// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].
*/



class Solution {
  public:
    
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, int i)
    {
        stack<pair<int, int>> s;
        
        s.push({i, -1});
        visited[i] = 1;
        
        while(!s.empty())
        {
            int node = s.top().first;
            int parent = s.top().second;
            s.pop();
            
            for(int j=0; j<adj[node].size(); j++)
            {
                int neighbour = adj[node][j];
                
                if(neighbour!=parent)
                {
                    if(visited[neighbour])
                    {
                        return true;
                    }
                    s.push({neighbour, node});
                    visited[neighbour] = 1;
                }
                
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> visited(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(dfs(adj, visited, i))
                    return true;
            }
        }
        return false;
    }
};
