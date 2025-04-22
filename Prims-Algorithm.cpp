// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.
*/



/*
**** NOTE ****
Spanning tree is a tree with N vertices and N-1 edges, where every vertex is reachable from every other vertex.
Minimum spanning tree is that spanning tree for a graph that has the minimum weight among all the possible spanning trees.
*/

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> minHeap;
        
        vector<int> visited(V, 0);
        
        minHeap.push({0, 0});   // {weight, node}
        
        int weightMST = 0;
        
        while(!minHeap.empty())
        {
            int node = minHeap.top().second;
            int weight = minHeap.top().first;
            minHeap.pop();
            
            if(visited[node])
                continue;
            
            visited[node] = 1;
            weightMST += weight;
            
            for(auto it : adj[node])
            {
                int neighbour = it[0];
                int wt = it[1];
                
                if(!visited[neighbour])
                    minHeap.push({wt, neighbour});
            }
        }
        
        return weightMST;
    }
};
