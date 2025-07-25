// https://leetcode.com/problems/is-graph-bipartite/description/

/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/



class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int i)
    {
        stack<int> s;
        s.push(i);
        color[i] = 0;

        while(!s.empty())
        {
            int node = s.top();
            s.pop();

            for(int j=0; j<graph[node].size(); j++)
            {
                int neighbour = graph[node][j];
                if(color[neighbour] == color[node])
                    return false;

                if(color[neighbour] == -1)
                {
                    s.push(neighbour);
                    color[neighbour] = 1 - color[node];
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
                if(dfs(graph, color, i) == false)
                    return false;
        }

        return true;
    }
};
