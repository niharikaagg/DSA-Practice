// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

/*
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.
*/



class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int i, stack<int> &s)
    {
        visited[i] = 1;
        
        for(auto it : adj[i])
        {
            if(!visited[it])
                dfs(adj, visited, it, s);
        }
        
        s.push(i);  // Push on returning (according to finishing time)
    }
    
    void dfsForCountingComponents(vector<vector<int>> &reverseGraph, vector<int> &visited, int node)
    {
        visited[node] = 1;
        
        for(auto it : reverseGraph[node])
        {
            if(!visited[it])
                dfsForCountingComponents(reverseGraph, visited, it);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // Strongly connected components in a directed graph are those components in whichfor each pair of node in the component, one can go from node1 to node2 and node2 to node1 as well
        
        int n = adj.size();
        
        vector<int> visited(n, 0);
        stack<int> s;
        
        // Step 1 - Sort nodes according to finishing time
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(adj, visited, i, s);
        }
        
        // The top of stack now has the node with largest finishing time, and that node will surely be in the first strongly connected component
        
        // Step 2 - Reverse the graph
        vector<vector<int>> reverseGraph(n);
        
        for(int i=0; i<n; i++)
        {
            visited[i] = 0;     // Clear the visited array for use again
            
            for(auto it : adj[i])
                reverseGraph[it].push_back(i);
        }
        
        
        // Step 3 - Perform a dfs to count number of components
        int noOfSCC = 0;
        
        // Use the nodes stored in the same stack for dfs traversal
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            if(!visited[node])
            {
                noOfSCC++;
                dfsForCountingComponents(reverseGraph, visited, node);
            }
        }
        
        return noOfSCC;
    }
};
