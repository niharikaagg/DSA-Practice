// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

/*
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/



class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> dfs;
        vector<int> visited(n, 0);
        stack<int> s;
        
        s.push(0);
        
        while(!s.empty())
        {
            int x = s.top();
            s.pop();
            
            if (visited[x])
                continue;
            
            visited[x] = 1;
            dfs.push_back(x);
            
            for(int i=adj[x].size()-1; i>=0; i--)
            {
                if(!visited[adj[x][i]])
                {
                    s.push(adj[x][i]);
                    //visited[adj[x][i]] = 1;
                }
            }
        }
        
        return dfs;
    }
};
