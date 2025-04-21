// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

/*
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.
*/



/*
**** NOTE ****
This algorithm computes shortest distance but unlike Dijkstra, it can handle negative edges and can detect negative cycles as well.
This algorithm can only be applied to directed graphs. To apply it on undirect graphs, convert the graph to directed by add to and fro directed edges between the nodes, with equal weights.
In a graph of N nodes, in the worst case, it takes at most N-1 moves to reach from first to last node. We use N-1 iterations because in the worst case, each node is dependent on previous node (in case of a straight graph) and in each iteration only one distance is updated in the distance array. Since one value (source) is already non-infinity, we take N-1 iterations to remove all infinity values/find the shortest distance for each node.
To detect a negative weight cycle, perform Nth iteration and if the distance array gets updated, these is a cycle, since ideally, we should have got the shortest path answer at the (N-1)th iteration itself.
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> distance(V, 1e8);
        
        distance[src] = 0;
        
        for(int i=1; i<V; i++)
        {
            for(int j=0; j<edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if((distance[u] != 1e8) && (distance[u] + wt < distance[v]))
                    distance[v] = distance[u] + wt;
            }
        }
        
        for(int j=0; j<edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
                
            if((distance[u] != 1e8) && (distance[u] + wt < distance[v]))  // (distance[u] != 1e8) condition to avoid detection disconnected components with negative weights as negative cycles
                return {-1};
        }
        
        return distance;
    }
};
