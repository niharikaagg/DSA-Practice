// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/



class Solution {
public:
    vector<vector<pair<int, int>>> createAdjacencyList(int n, vector<vector<int>> &flights) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(int i=0; i<flights.size(); i++)
        {
            int node = flights[i][0];
            int neighbour = flights[i][1];
            int weight = flights[i][2];
            
            adj[node].push_back({neighbour, weight});
        }
        
        return adj;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj = createAdjacencyList(n, flights);

        // We will use queue since we are sorting based on number of stops and after each iteration, one stop will increase, so they will automatically be sorted
        queue<pair<int, pair<int, int>>> q;   // {stops, {node, cost}}
        vector<int> costArray(n, 1e9);

        q.push({-1, {src, 0}});
        costArray[src] = 0;

        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stops+1 > k)
                break;

            for(auto it : adj[node])
            {
                int neighbour = it.first;
                int cost = it.second;

                int newCost = price + cost;

                if(newCost < costArray[neighbour])
                {
                    costArray[neighbour] = newCost;
                    q.push({stops+1, {neighbour, newCost}});
                }
            }
        }

        if(costArray[dst] == 1e9)
            return -1;
        return costArray[dst];
    }
};
