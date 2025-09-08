// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/



class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int count = 0;

        for(int i=0; i<s.length(); i++)
        {
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            }
        }

        return count;
    }
};
