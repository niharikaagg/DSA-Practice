// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/*
Given a undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/



class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<int> bfs;
        vector<int> visited(n, 0);
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            bfs.push_back(x);
            visited[x] = 1;
            
            for(int i=0; i<adj[x].size(); i++)
            {
                if(!visited[adj[x][i]])
                {
                    q.push(adj[x][i]);
                    visited[adj[x][i]] = 1;
                }
            }
        }
        
        return bfs;
    }
};
