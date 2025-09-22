// https://leetcode.com/problems/candy/

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/



class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1, i = 1;
        int n = ratings.size();

        while(i < n)
        {
            if(ratings[i] == ratings[i-1])
            {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1])
            {
                peak += 1;
                sum += peak;
                i++;
            }

            int down = 0;
            while(i < n && ratings[i] < ratings[i-1])
            {
                down += 1;
                sum += down;
                i++;
            }

            if(down + 1 > peak)
                sum += (down + 1 - peak);
        }

        return sum;
    }
};
