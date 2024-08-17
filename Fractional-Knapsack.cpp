// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack. Return a double value representing the maximum value in knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the comments above the given function.
*/



// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    bool static compareUsingValueByWeight(Item a, Item b){
        
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1>r2;
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr+n, compareUsingValueByWeight);
        
        double val=0, wt=0, currWt=0;
        
        int i=0;
        while(wt<w && i<n)
        {
            wt = min((double)arr[i].weight, w-currWt);
            currWt = currWt + wt;
            val = val + ((double)arr[i].value/(double)arr[i].weight)*wt;
            i++;
        }
        
        return val;
    }
};
