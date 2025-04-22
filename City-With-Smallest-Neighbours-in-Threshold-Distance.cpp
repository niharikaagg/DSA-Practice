// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/



class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++)
        {
            distance[i][i] = 0;
        }

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            distance[u][v] = wt;
            distance[v][u] = wt;
        }

        for(int via=0; via<n; via++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(distance[i][via] != 1e9 && distance[j][via] != 1e9)
                            distance[i][j] = min(distance[i][j], distance[i][via] + distance[via][j]);
                }
            }
        }

        vector<int> reachable(n, 0);
        int minReachable = INT_MAX;
        int index = -1;

        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j && distance[i][j]<=distanceThreshold)
                    count++;
            }

            if(count <= minReachable)
            {
                minReachable = count;
                index = i;
            }
        }

        return index;
    }
};
