// https://leetcode.com/problems/find-eventual-safe-states/description/

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/



class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> inDegree(n, 0);

        for(int i=0; i<n; i++)
        {
            for(auto it : graph[i])
            {
                revGraph[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }

        vector<int> safeNodes;

        while(!q.empty())
        {
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();

            for(auto it : revGraph[node])
            {
                inDegree[it]--;

                if(inDegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};
