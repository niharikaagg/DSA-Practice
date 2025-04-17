// https://www.geeksforgeeks.org/problems/topological-sort/1

/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
*/

/*
**** VERYIMPORTANT ****
For this algorithm, you can use either a stack or a queue, both will work perfectly fine. They will just return different topological orderings.

Visited array is not required in this algorithm. This is because we are only inserting the node into the queue whenever the degree of that node becomes 0 and this will happen only once.
*/

// QUEUE
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
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = createAdjacencyList(V, edges);
        
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
            }
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
            
            for(int i=0; i<adj[node].size(); i++)
            {
                int neighbour = adj[node][i];
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        return topoOrder;
    }
};

// STACK
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
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj = createAdjacencyList(V, edges);
        
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
            }
        }
        
        stack<int> s;
        
        for(int i=0; i<V; i++)
        {
            if(inDegree[i] == 0)
                s.push(i);
        }
        
        vector<int> topoOrder;
        
        while(!s.empty())
        {
            int node = s.top();
            topoOrder.push_back(node);
            s.pop();
            
            for(int i=0; i<adj[node].size(); i++)
            {
                int neighbour = adj[node][i];
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0)
                    s.push(neighbour);
            }
        }
        
        return topoOrder;
    }
};
