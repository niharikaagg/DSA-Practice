// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st)
        {
            if(!st.count(num - 1))
            {
                int currNum = num;
                int currLen = 1;

                while(st.count(currNum + 1))
                {
                    currLen++;
                    currNum++;
                }

                longest = max(longest, currLen);
            }
        }

        return longest;
    }
};
