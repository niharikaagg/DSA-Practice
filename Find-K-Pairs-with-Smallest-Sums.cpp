// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k == 0)
            return res;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        set<pair<int, int>> visited;
        
        minHeap.push({nums1[0]+nums2[0], {0,0}});
        visited.insert({0, 0});

        while(k && !minHeap.empty())
        {
            int i = minHeap.top().second.first;
            int j = minHeap.top().second.second;
            res.push_back({nums1[i], nums2[j]});
            minHeap.pop();
            k--;

            if(i+1 < nums1.size() && !visited.count({i+1, j}))
            {
                minHeap.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }

            if(j+1 < nums2.size() && !visited.count({i, j+1}))
            {
                minHeap.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }

        return res;
    }
};
