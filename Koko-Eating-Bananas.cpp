// https://leetcode.com/problems/koko-eating-bananas/description/

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/



class Solution {
public:
    long long calculateHours(int mid, vector<int> piles)
    {
        long long hours = 0;

        for(int i=0; i<piles.size(); i++)
        {
            hours += ceil((double)(piles[i])/(double)(mid));
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int largestPile = INT_MIN;

        for(int i=0; i<piles.size(); i++)
        {
            largestPile = max(largestPile, piles[i]);
        }

        int s = 1, e = largestPile;

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            long long hours = calculateHours(mid, piles);

            if(hours <= h)
                e = mid-1;
            else
                s = mid+1;
        }

        return s;
    }
};
