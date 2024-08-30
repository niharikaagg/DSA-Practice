// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/*
Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.
*/



/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    // To sort array based on profit
    bool static compareByProfit(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compareByProfit);
        
        int count = 0;
        int totalProfit = 0;
        
        int sequence[n] = {0};
        
        for(int i=0; i<n; i++)
        {
            int pos = arr[i].dead - 1;
            
            while(sequence[pos] != 0 && pos >= 0)
                pos--;
                
            if(pos == -1)
                continue;
                
            sequence[pos] = arr[i].id;
            count++;
            totalProfit += arr[i].profit;
        }
        
        return {count, totalProfit};
    } 
};
