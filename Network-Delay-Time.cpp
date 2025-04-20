// https://leetcode.com/problems/network-delay-time/description/

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/



class Solution {
public:
    vector<vector<pair<int, int>>> createAdjacencyList(int n, vector<vector<int>> &times)
    {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(int i=0; i<times.size(); i++)
        {
            int node = times[i][0];
            int neighbour = times[i][1];
            int weight = times[i][2];
            
            adj[node].push_back({neighbour, weight});
        }
        
        return adj;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(n, times);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> distance(n+1, 1e9);

        distance[k] = 0;
        minHeap.push({0, k});   // {distance, node}

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
                }
            }
        }

        int time = INT_MIN;

        for(int i=1; i<=n; i++)
        {
            if(distance[i] == 1e9)
                return -1;
            time = max(time, distance[i]);
        }

        return time;
    }
};
