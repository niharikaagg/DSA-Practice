// https://leetcode.com/problems/sum-of-subarray-ranges/

/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/



class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSL(n), NSR(n), NGL(n), NGR(n);
        long long minSum = 0;
        long long maxSum = 0;
        stack<int> st;

        // smallest on left
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            NSL[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // smallest on right
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            NSR[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // greatest on left
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            NGL[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        // greatest on right
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            NGR[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        for(int i=0; i<n; i++)
        {
            long long minElementsOnLeft = i - NSL[i];
            long long minElementsOnRight = NSR[i] - i;
            long long minTotalWays = minElementsOnLeft * minElementsOnRight;
            minSum += (long long)nums[i] * minTotalWays;

            long long maxElementsOnLeft = i - NGL[i];
            long long maxElementsOnRight = NGR[i] - i;
            long long maxTotalWays = maxElementsOnLeft * maxElementsOnRight;
            maxSum += (long long)nums[i] * maxTotalWays;
        }
        
        return maxSum - minSum;
    }
};
