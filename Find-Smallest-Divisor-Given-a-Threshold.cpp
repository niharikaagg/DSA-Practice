// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
*/



class Solution {
public:
    int calculateSum(vector<int> nums, int divisor)
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += ceil((double)nums[i]/divisor);
            // if both are integers, integer division takes place and result is truncated before reaching ceil() function, so we need to convert atleast one to float value so that floating point division takes place and ceil() function then works correctly
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1, high = *max_element(nums.begin(), nums.end());
        int sum = 0, ans = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            sum = calculateSum(nums, mid);

            if(sum <= threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};
