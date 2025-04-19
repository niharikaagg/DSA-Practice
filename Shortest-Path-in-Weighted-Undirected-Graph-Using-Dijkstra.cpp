// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/0

/*
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 
*/



class Solution {
  public:
    vector<vector<pair<int, int>>> createAdjacencyList(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(int i=0; i<edges.size(); i++)
        {
            int node = edges[i][0];
            int neighbour = edges[i][1];
            int weight = edges[i][2];
            
            adj[node].push_back({neighbour, weight});
            adj[neighbour].push_back({node, weight});
        }
        
        return adj;
    }
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(n, edges);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> distance(n+1, 1e9);

        // We will use a parent array to keep track of the node's parent to get the path in the end
        vector<int> parent(n+1);
        
        for(int i=1; i<=n; i++)
        {
            parent[i] = i;
        }
        
        distance[1] = 0;
        minHeap.push({0, 1});
        
        while(!minHeap.empty())
        {
            int node = minHeap.top().second;
            int dist = minHeap.top().first;
            minHeap.pop();
            
            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int weight = it.second;
                
                int newDist = dist + weight;
                
                if(newDist < distance[neighbour])
                {
                    distance[neighbour] = newDist;
                    minHeap.push({newDist, neighbour});
                    parent[neighbour] = node;
                }
            }
        }
        
        if(distance[n] == 1e9)
            return {-1};
        
        vector<int> path;
        
        int node = n;
        path.push_back(node);
        
        while(node != 1)
        {
            path.push_back(parent[node]);
            node = parent[node];
        }
        
        path.push_back(distance[n]);
        
        reverse(path.begin(), path.end());
        
        return path;
    }
};
