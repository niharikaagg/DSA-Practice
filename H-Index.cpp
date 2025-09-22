// https://leetcode.com/problems/h-index/

/*
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
*/



// Optimal
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> numberOfPapers(n+1, 0);

        for(int i=0; i<n; i++)
        {
            if(citations[i] >= n)
                numberOfPapers[n]++;
            else
                numberOfPapers[citations[i]]++;
        }

        int count = 0;
        for(int i=n; i>=0; i--)
        {
            count += numberOfPapers[i];
            if(count >= i)
                return i;
        }

        return -1;
    }
};

// Using sorting
class Solution {
public:
    int hIndex(vector<int>& citations) {        
        sort(citations.rbegin(), citations.rend());

        int i = 0;

        while(i < citations.size() && citations[i] >= i+1)
            i++;
        return i;
    }
};
