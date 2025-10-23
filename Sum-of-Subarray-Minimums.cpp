// https://leetcode.com/problems/sum-of-subarray-minimums/

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 10^9 + 7.
*/



class Solution {
public:
    // to avoid duplicates, we need t0 use equal sign in one of NSL or NSR
    // we will store indices in stack, not the element

    vector<int> getNSL(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> res(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(i);
        }

        return res;
    }

    vector<int> getNSR(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> res(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(st.empty())
                res[i] = n;
            else
                res[i] = st.top();

            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int MOD = 1e9 + 7;
        
        // get next smaller on left side
        vector<int> NSL = getNSL(arr, n);
        // get next smaller on right side
        vector<int> NSR = getNSR(arr, n);

        for(int i=0; i<n; i++)
        {
            long long elementsOnLeft = i - NSL[i];
            long long elementsOnRight = NSR[i] - i;

            long long totalWays = elementsOnLeft*elementsOnRight;
            long long elementSum = arr[i] * totalWays;

            sum = (sum + elementSum) % MOD;
        }

        return sum;
    }
};
