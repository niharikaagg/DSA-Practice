// https://leetcode.com/problems/next-greater-element-ii/

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // hypothetically double the array so that it can be considered circular
        // start from the read end, while our original elements will be at the beginning
        // this will be able to map the next greater element in circular fashion
        // eg. 1 10 2 12 11
        // double array 1 10 2 12 11 1 10 2 12 11
        // if we use the monotonic stack concept here, we will have 12 in the stack as next greater element for 11

        for(int i=2*n-1; i>=0; i--)
        {
            int index = i % n;
            while(!st.empty() && st.top() <= nums[index])
                st.pop();

            if(st.empty())
                ans[index] = -1;
            else
                ans[index] = st.top();

            st.push(nums[index]);
        }

        return ans;
    }
};
