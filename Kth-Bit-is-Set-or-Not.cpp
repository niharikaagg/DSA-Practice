// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

/*
Given a number n and a bit number k, check if the kth index bit of n is set or not. A bit is called set if it is 1. The position of set bit '1' should be indexed starting with 0 from the LSB side in the binary representation of the number.
Note: Index is starting from 0. You just need to return true or false.
*/



class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1 << k));
    }
};
