// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

/*
You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/



class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        
        vector<int> distance(n, 1e9);    // initialize with very large number so minimum distance can be updatedmin
        
        queue<int> q;
        
        q.push(src);
        
        distance[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            
            q.pop();
            
            for(auto it : adj[node])
            {
                int dist = distance[node] + 1;
                
                if(dist < distance[it])
                {
                    q.push(it);
                    distance[it] = dist;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(distance[i] == 1e9)
                distance[i] = -1;
        }
        
        return distance;
    }
};
