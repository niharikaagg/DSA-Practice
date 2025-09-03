// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/



class Solution {
public:
    bool capacityPossible(vector<int> &weights, int days, int capacity)
    {
        int n = weights.size();
        int numberOfDays = 1, sum = 0;

        for(int i=0; i<n; i++)
        {
            sum += weights[i];

            if(sum > capacity)
            {
                numberOfDays++;
                sum = weights[i];
            }
        }

        return (numberOfDays <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int maxWeight = 0, sum = 0;

        for(int i=0; i<n; i++)
        {
            maxWeight = max(maxWeight, weights[i]);
            sum += weights[i];
        }

        int s = maxWeight, e = sum;

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(capacityPossible(weights, days, mid))
                e = mid-1;
            else
                s = mid+1;
        }

        return s;
    }
};
