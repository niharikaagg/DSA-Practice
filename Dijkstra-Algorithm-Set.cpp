// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

/*
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
*/



/*
**** NOTE ****
Sets store the pair in ascending order of first element. Here it is stored in ascending order of distance for {distance, node} pair.
But in addition to this, it provides the flexibility to erase the elements from the set. We can erase those entries from the set which have a higher distance when a smaller distance entry for the same node is found. Thus the number of iterations are reduced.

But we cannot say that is necessarily better than priority queue. It depends on the type of graph.
The set method reduces iterations but the erase operation also takes logN time.
So which method is to be chosen, depends on the graph.
*/

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
        
        // We will use a set since set stores elements in ascending order
        // We will store it as a pair of {distance, node}
        
        set<pair<int, int>> s;
        vector<int> distance(V, 1e9);
        
        distance[src] = 0;
        s.insert({0, src});
        
        while(!s.empty())
        {
            auto it = *(s.begin());    // an iterator that points to the beginning of the set
            
            int dist = it.first;
            int node = it.second;
            
            s.erase(it);
            
            for(auto itr : adj[node])
            {
                int neighbour = itr.first;
                int weight = itr.second;
                
                int newDist = dist + weight;
                
                if(newDist < distance[neighbour])
                {
                    // If the neighbour has already been visited at a greater distance, then erase it from the set
                    if(distance[neighbour] != 1e9)
                        s.erase({distance[neighbour], neighbour});
                        
                    s.insert({newDist, neighbour});
                    distance[neighbour] = newDist;
                }
            }
        }
        
        return distance;
    }
};
