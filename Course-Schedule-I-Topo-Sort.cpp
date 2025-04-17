// https://leetcode.com/problems/course-schedule/description/

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/



class Solution {
public:
    vector<vector<int>> createAdjacencyList(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        return adj;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = createAdjacencyList(numCourses, prerequisites);
        
        vector<int> inDegree(numCourses, 0);
        
        for(int i=0; i<numCourses; i++)
        {
            for(auto it : adj[i])
                inDegree[it]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topoOrder;
        
        while(!q.empty())
        {
            int node = q.front();
            topoOrder.push_back(node);
            q.pop();
            
            for(auto it : adj[node])
            {
                inDegree[it]--;
                
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(topoOrder.size() != numCourses)
            return false;
        return true;
    }
};
