// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.
*/



/*
**** NOTE ****
This is basically Kahn's algorithm with a extra ending condition. If the topological sort produced by the Kahn's algorithm has fewer nodes than the vertices, it means that a cycle exists.
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
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj = createAdjacencyList(V, edges);
        
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
                inDegree[it]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topoOrder;
        
        while(!q.empty())
        {
            int node = q.front();
            topoOrder.push_back(node);
            q.pop();
            
            for(auto it : adj[node])
            {
                inDegree[it]--;
                
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(topoOrder.size() != V)
            return true;
        return false;
    }
};
