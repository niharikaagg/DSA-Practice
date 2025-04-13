// https://www.geeksforgeeks.org/problems/odd-or-even3618/1

/*
Given a positive integer n, determine whether it is odd or even. Return true if the number is even and false if the number is odd.
*/



class Solution {
  public:
    bool isEven(int n) {
        return ((n & 1) == 0);
    }
};
