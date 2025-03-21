// https://www.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices

/*
Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
*/



class Solution {
  public:
    long long count(int n) {
        int edge = (n*(n-1))/2;
        return pow(2, edge);
    }
};
