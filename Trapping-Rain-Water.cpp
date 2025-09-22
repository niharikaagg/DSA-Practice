// https://leetcode.com/problems/trapping-rain-water/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/



// Optimal approach - O(1) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, totalWater = 0;
        int leftMax = height[l], rightMax = height[r];

        while(l < r)
        {
            if(leftMax <= rightMax)
            {
                l += 1;
                leftMax = max(leftMax, height[l]);
                totalWater += leftMax - height[l];
            }

            else
            {
                r -= 1;
                rightMax = max(rightMax, height[r]);
                totalWater += rightMax - height[r];
            }
        }

        return totalWater;
    }
};

// O(N) or O(2N) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0);
        for(int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], height[i-1]);

        vector<int> rightMax(n, 0);
        for(int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], height[i+1]);

        int totalWater = 0;
        for(int i=0; i<n; i++)
        {
            if(min(leftMax[i], rightMax[i]) > height[i])
                totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};
