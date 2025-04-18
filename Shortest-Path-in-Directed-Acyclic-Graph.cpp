// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/



/*
**** NOTE ****
This algorithm first uses topological sort to create the topological ordering to avoid repetition of nodes, since we know that all the nodes prior to a certain node have already been processed due to topological ordering.
It then uses the shortest path algorithm which maintains a distance array and updates the distances to minimum distance. The nodes are chosen for processing in topological sort order.
Any algorithm, BFS or DFS, can be used for topological sort. 
*/

class Solution {
  public:
  //vector<vector<pair<int, int>>>
    vector<vector<pair<int, int>>> createAdjacencyList(int V, int E, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        
        for(int i=0; i<E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adj[u].push_back({v, weight});
        }
        
        return adj;
    }

    // BFS Topological Sort - Kahn's Algorithm
    vector<int> topologicalSort(int V, vector<vector<pair<int, int>>>& adj)
    {
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                int neighbour = it.first;
                
                inDegree[neighbour]++;
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
            q.pop();
            topoOrder.push_back(node);
            
            for(auto it : adj[node])
            {
                int neighbour = it.first;
                
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        
        return topoOrder;
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(V, E, edges);
        
        vector<int> topoOrder = topologicalSort(V, adj);
        
        vector<int> distance(V, 1e9);
        
        distance[0] = 0;
        
        for(int i=0; i<V; i++)
        {
            int node = topoOrder[i];
            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int dist = it.second;
                
                int newDist = distance[node] + dist;
                
                if(newDist < distance[neighbour])
                    distance[neighbour] = newDist;
            }
        }
        
        for(int i=0; i<V; i++)
        {
            if(distance[i] == 1e9)
                distance[i] = -1;
        }
        
        return distance;
    }
};
