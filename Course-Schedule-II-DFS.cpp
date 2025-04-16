// https://leetcode.com/problems/course-schedule-ii/description/

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/



class Solution {
public:
    vector<vector<int>> createAdjacencyList(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        return adj;
    }

    // Recursive

    bool dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, vector<int> &order, int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(int j=0; j<adj[node].size(); j++)
        {
            int neighbour = adj[node][j];
            if(!visited[neighbour])
            {
                if(!dfs(adj, visited, pathVisited, order, neighbour))
                    return false;   // cycle detected in neighbours traversal
            }

            if(pathVisited[neighbour])
                return false;   // cycle detected
        }
        pathVisited[node] = 0; // reset pathVisited for node after exploring all neighbours
        order.push_back(node);
        return true;
    }

    // Interative

    // bool dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& order, int i) {
    //     stack<int> s;
    //     s.push(i);
        
    //     while (!s.empty()) {
    //         int node = s.top();
            
    //         if (!visited[node]) {
    //             visited[node] = 1;
    //             pathVisited[node] = 1;
                
    //             // Push back the node to process neighbors
    //             s.push(node);
                
    //             // Push all unvisited neighbors
    //             for (int neighbor : adj[node]) {
    //                 if (!visited[neighbor]) {
    //                     s.push(neighbor);
    //                 } else if (pathVisited[neighbor]) {
    //                     return false; // Cycle detected
    //                 }
    //             }
    //         } else {
    //             s.pop(); // Remove the node from stack
                
    //             if (pathVisited[node]) {
    //                 pathVisited[node] = 0;
    //                 order.push_back(node);
    //             }
    //         }
    //     }
    //     return true;
    // }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
        vector<int> order;

        vector<vector<int>> adj;

        adj = createAdjacencyList(numCourses, prerequisites);

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {               
                if(!dfs(adj, visited, pathVisited, order, i))
                    return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
