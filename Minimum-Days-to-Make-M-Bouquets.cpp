// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/



class Solution {
public:
    bool bouquetsPossible(vector<int> &bloomDay, int m, int k, int day)
    {
        int n = bloomDay.size();
        int numberOfFlowers = 0, bouquets = 0;

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= day)
            {
                numberOfFlowers++;
            }
            else
            {
                bouquets += numberOfFlowers/k;
                numberOfFlowers = 0;
            }
        }

        bouquets += numberOfFlowers/k;

        return (bouquets >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long totalFlowers = 1LL*m*k;
        // 1LL makes it long long before multiplication; without it, m*k is done in int first and may overflow

        if(totalFlowers > n)
            return -1;

        int s = INT_MAX, e = INT_MIN;

        for(int i=0; i<n; i++)
        {
            s = min(bloomDay[i], s);
            e = max(bloomDay[i], e);
        }

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(bouquetsPossible(bloomDay, m, k, mid))
                e = mid - 1;
            else
                s = mid + 1;
        }

        return s;
    }
};
