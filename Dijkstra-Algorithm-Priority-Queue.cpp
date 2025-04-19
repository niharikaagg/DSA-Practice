// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
*/



// This algorithm cannot be used for negative weights since it will get stuck in an infinite loop.

// A priority queue is used instaed of a queue because a queue travels all the possible paths, whereas the priority queue keeps the shortest distance path on top and hence travels only minimal paths. A queue is like a brute force whereas the priority queue greedily travels only minimal paths.

class Solution {
  public:
    vector<vector<pair<int, int>>> createAdjacencyList(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        
        for(int i=0; i<edges.size(); i++)
        {
            int node = edges[i][0];
            int neighbour = edges[i][1];
            int weight = edges[i][2];
            
            adj[node].push_back({neighbour, weight});
        }
        
        return adj;
    }
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(V, edges);
        
        // We will use a priority queue as a min heap
        // It will store {distance, node} pairs
        // The pairs will be ordered according to distance in the heap with minimum distance on top
        // If distance is same, they will be ordered according to smaller node on top
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> distance(V, 1e9);
        
        distance[src] = 0;
        minHeap.push({0, src});
        
        while(!minHeap.empty())
        {
            int dist = minHeap.top().first;
            int node = minHeap.top().second;
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
                }
            }
        }
        
        return distance;
    }
};
