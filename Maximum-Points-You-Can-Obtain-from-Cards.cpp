// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/



// Solution 1

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = 0, rightSum = 0, maxSum = 0, sum = 0;

        for(int i=0; i<k; i++)
            leftSum += cardPoints[i];

        maxSum = leftSum;
        int rightIndex = n-1;

        for(int i=k-1; i>=0; i--)
        {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};

// Solution 2

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0, maxSum=0;
        int n=cardPoints.size();
        int i=n-k, j=n-1;
        int count;

        for(int count=i; count<=j; count++)
            sum += cardPoints[count];

        if(k == n)
            return sum;

        maxSum = sum;

        count = k;

        while(count)
        {
            sum -= cardPoints[i];

            i = (i+1)%n;
            j = (j+1)%n;

            sum += cardPoints[j];

            maxSum = max(maxSum, sum);

            count--;
        }

        return maxSum;
    }
};
