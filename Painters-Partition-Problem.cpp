// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

/*
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.
*/



int numberOfPainters(vector<int> &boards, int k, int maxTime)
{
    int painters = 1, time = 0;

    for(int i=0; i<boards.size(); i++)
    {
        if(time + boards[i] > maxTime)
        {
            painters++;
            time = boards[i];
        }

        else
            time += boards[i];
    }

    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(boards.begin(), boards.end());
    // int e = accumulate(boards.begin(), boards.end(), 0);
    int e = 0;
    for(int i = 0; i < boards.size(); i++) {
        e += boards[i];
}

    while(s <= e)
    {
        int mid = s + (e-s)/2;

        if(numberOfPainters(boards, k, mid) <= k)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return s;
}
