// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/



class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    int maxMeetings(int n, int start[], int end[]) {
        
        // Sort start and end array based on end time
        
        vector <pair <int, int>> pairStartEnd;
        
        for(int i=0; i<n; i++)
        {
            pairStartEnd.push_back(make_pair(end[i], start[i]));
        }
        
        sort(pairStartEnd.begin(), pairStartEnd.end());  // sorts on the basis of end array (first element of pair)
        
        for(int i=0; i<n; i++)
        {
            end[i] = pairStartEnd[i].first;
            start[i] = pairStartEnd[i].second;
        }
        
        // Count number of meetings
        
        int count = 1;
        int prevJob = 0;
        
        for(int i=1; i<n; i++)
        {
            if(start[i] > end[prevJob])
            {
                count++;
                prevJob = i;
            }
        }
        
        return count;
    }
};
