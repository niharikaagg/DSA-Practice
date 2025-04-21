// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.
*/



class Solution {
public:
    vector<vector<pair<int, int>>> createAdjacencyList(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(int i=0; i<roads.size(); i++)
        {
            int node = roads[i][0];
            int neighbour = roads[i][1];
            int weight = roads[i][2];
            
            adj[node].push_back({neighbour, weight});
            adj[neighbour].push_back({node, weight});
        }
        
        return adj;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(n, roads);

        // use long long everywhere since the weights use large values, outside int range
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        minHeap.push({0, 0});
        distance[0] = 0;
        ways[0] = 1;

        const int MOD = 1e9 + 7;

        while(!minHeap.empty())
        {
            int node = minHeap.top().second;
            long long dist = minHeap.top().first;
            minHeap.pop();

            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int weight = it.second;

                long long newDist = dist + weight;

                if(newDist < distance[neighbour])
                {
                    distance[neighbour] = newDist;
                    minHeap.push({newDist, neighbour});
                    ways[neighbour] = ways[node];
                }

                else if(newDist == distance[neighbour])
                {
                    // This means you've found another path to neighbor that's equally as fast as the best one you knew before, i.e., path from another node to neighbour which is equally fast
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                    // Already existing ways + Ways from the current node
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
